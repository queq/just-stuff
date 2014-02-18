#include  <msp430f2122.h>
#include  "Debounce.h"

extern void ConfigTimer0();          // in module Configs.c
extern void SPI_Master_Init();       //
extern void SPI_Write(char dato);    //

void EvaluateInputTransition();      // determine if a transition has ocurred

void Display(char num);
void Counter();

void TimeCounter();                  // counts time

void GetData();                      //gets thumbswitch data

enum FLAGS_STATES {CLEAR,SET};              // define constant CLEAR=0 , SET=1
enum SYSTEM_STATE_NAMES {S0,S1,S2,S3};      // define system state names

#define timeValue 250
int timeCount=timeValue;             //value to load the TimerCounter
char elapsedTimeFlag;               //SET when timeCount reaches 0

char timerInterruptFlag;            //SET when a Timer0 intrrupt occurs
char inputTransitionFlag=CLEAR;           //SET when a high to low transition

char dataReady=CLEAR;

char num;

// ----------- NEW: Contatnt codes array for seven segment diaplay -------
const char digits[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
                       
const char dp=0x80;
//-------------------------------------------------------------------------


int main( void )
{
  
  WDTCTL = WDTPW + WDTHOLD;          // Stop watchdog timer
 
  BCSCTL1 = CALBC1_1MHZ;             // Set range  (1 Mhz)
  DCOCTL = CALDCO_1MHZ;              // Set DCO step + modulation */ 
  
  SPI_Master_Init();
  
  P1OUT &= ~(BIT0 + BIT1);            // Set P1.0 and P1.1 to 0 (when output)
  P1DIR |= (BIT0 + BIT1);             // Set P1.0 and P1.1 to output direction   

//Pull up resistor in P2.4++++++++++++++++++++++++++++++++++++++++++++++++++ 
  P2OUT |= BIT4;                      // Bit 4 of P2OUT in 1
  P2REN |= BIT4;                      // Bit 4 of P2REN in 1
                                      // REN:Pullup/Pulldown Resistor Enable
                                      // register
//--------------------------------------------------------------------------  
  
//Hi/Low transition detection+++++++++++++++++++++++++++++++++++++++++++++++
  P2IES |= BIT4;                      // P2.4 Hi/Low transition detection
                                      // IES:Interrupt Edge Select register
  P2IFG &= ~BIT4;                     // P2.4 IFG cleared 
                                      // IFG:Interupt Flag register
//--------------------------------------------------------------------------


  timerInterruptFlag=CLEAR;

  ConfigTimer0();                    //Configure Timer0 Module
                                     //for 10 ms interrupt 
  
  _EINT();                           // enable (general) interrupts
                                     //eint <-----> bis #8,sr
  
  //example of a timed loop:
  
  for(;;){                                // loop forever 

    while(timerInterruptFlag != SET);     // loop forever while Flag not SET
    timerInterruptFlag=CLEAR;             // Clear timer flag
    
    GetData();

    Counter();
    
    EvaluateInputTransition();         //Find if a transition has happened 

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


//GetData  ------------------------------------------
void GetData(){
  
  if (inputTransitionFlag==SET){
    inputTransitionFlag=CLEAR;
    dataReady=SET;
    num=P2IN & 0x0F;
  }

}
//-----------------------------------------------------




//Counter  ------------------------------------------
void Counter(){
  
  static char i=0;
  static char presentState=S0;
  
  switch(presentState){
    
    case S0:
        if (dataReady==SET){
          i=num;
          Display(i);
          timeCount=timeValue;
          presentState=S1;
        }
        break;
        
    case S1:
      if (elapsedTimeFlag==SET){
        elapsedTimeFlag=CLEAR;
        
        if (i<9){
          i++;
          Display(i);
        }else presentState=S0;
        timeCount=timeValue;
      }
 
      TimeCounter();  
      break;        
    
  }
  
}
//-----------------------------------------------------

//Display  --------------------------------------------
void Display(char num){

    P1OUT |= (BIT0 + BIT1);     //display off
    
    SPI_Write(digits[num]);
    
    P1OUT &= ~BIT0;             //display on
  
}
//-----------------------------------------------------------

// TimeCounter() --------------------------------------------

void TimeCounter(){
  timeCount--;
  if (timeCount==0){
    elapsedTimeFlag=SET;
  }
}  
//-----------------------------------------------------------


// EvaluateInputTransition --------------------------------------------
void EvaluateInputTransition(){

  char debounceFlag;                    // value returned by dbounce routine
   
  if ((P2IFG & BIT4) != 0){             // edge detected?
    debounceFlag=Debounce(2,4,3);    
    if (debounceFlag==1){               // true 1 to 0 transition detected
      debounceFlag=0;                   // clear routine indicator
      P2IFG &= ~BIT4;                   // P2.4 IFG cleared 
      inputTransitionFlag=SET ;         // Set main transition indicator flag
    }else if(debounceFlag==2){          // no 1 to 0 transition detected 
      debounceFlag=0;                   // clear routine indicator
      P2IFG &= ~BIT4;                   // P2.4 IFG cleared 
    }
  }
   
}
//----------------------------------------------------------------------