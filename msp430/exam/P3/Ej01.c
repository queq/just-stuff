#include  <msp430f2122.h>

extern void ConfigTimer0();          // in module Configs.c
extern void SPI_Master_Init();       //
extern void SPI_Write(char dato);    //

void TimeCounter();

void EvaluateInputTransition();

enum FLAGS_STATES {CLEAR,SET};              // define constant CLEAR=0 , SET=1
enum SYSTEM_STATE_NAMES {S0,S1,S2,S3};      // define system state names

#define timeValue 250
int timeCount=timeValue;             //value to load the TimerCounter
char elapsedTimeFlag;               //set to SET when timeCount reaches 0

char timerInterruptFlag,inputTransitionFlag;

char num;

int main( void )
{
  
  WDTCTL = WDTPW + WDTHOLD;          // Stop watchdog timer
 
  BCSCTL1 = CALBC1_1MHZ;             // Set range  (1 Mhz)
  DCOCTL = CALDCO_1MHZ;              // Set DCO step + modulation */ 
  
  //Hi/Low transition detection+++++++++++++++++++++++++++++++++++++++++++++++
  P1IES |= BIT4;                      // P1.3 Hi/Low transition detection
                                      // IES:Interrupt Edge Select register
  P1IFG &= ~BIT4;                     // P1.3 IFG cleared 
                                      // IFG:Interupt Flag register
//--------------------------------------------------------------------------
  

  
  SPI_Master_Init();
  
  num=0;
  
  P2OUT &= ~(0x1F);            // Set P2.0 to P2.4 to 0 (when output)
  P2DIR |= (0x1F);             // Set P2.0 and P2.4 to output direction
  P1DIR ^= (0xF);
  
  inputTransitionFlag=CLEAR;
  
  timerInterruptFlag=CLEAR;

  ConfigTimer0();                    //Configure Timer0 Module
                                     //for 10 ms interrupt 
  
  _EINT();                           // enable (general) interrupts
                                     //eint <-----> bis #8,sr
  
  //example of a timed loop:
  
  for(;;){  
	if (inputTransitionFlag==SET){
      inputTransitionFlag=CLEAR;
      P2OUT = (P1IN & 0xF);
    }// loop forever 
	timeCount = timeValue;
    while(timerInterruptFlag != SET);     // loop forever while Flag not SET
    timerInterruptFlag=CLEAR;             // Clear timer flag
    
    
	EvaluateInputTransition();
	TimeCounter();
           

  }

  return 0;
}


// Timer_A Interrupt Vector handler --------------------------------------------
#pragma vector=TIMER0_A0_VECTOR      //vector de interupcion para channel CCR0
__interrupt void Timer0_A0(void)
{
   
      //CCTL0 &=~ BIT0;(not needed)   //CCIFG is Bit 0 of CCTLO register 
      //The TACCR0 CCIFG flag is automatically reset when the TACCR0 interrupt 
      //request is serviced
  
      timerInterruptFlag=SET;
  
}
//------------------------------------------------------------------------------


// TimeCounter() --------------------------------------------

void TimeCounter(){
  timeCount--;
  if (timeCount==0){
    elapsedTimeFlag=SET;
  }
}  
//-----------------------------------------------------------

void EvaluateInputTransition(){

  if ((P1IFG & BIT4) != 0){             // edge detected?
      P1IFG &= ~BIT4;                   // P1.3 IFG cleared 
      inputTransitionFlag=SET ;         // Set main transition indicator flag
  }
   
}