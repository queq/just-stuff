#include  <msp430f2122.h>

extern void ConfigTimer0();          // in module Configs.c
extern void SPI_Master_Init();       //
extern void SPI_Write(char dato);    //

void LedsShifter();
void TimeCounter();

enum FLAGS_STATES {CLEAR,SET};              // define constant CLEAR=0 , SET=1
enum SYSTEM_STATE_NAMES {S0,S1,S2,S3};      // define system state names

#define timeValue 50
int timeCount=timeValue;             //value to load the TimerCounter
char elapsedTimeFlag;               //set to SET when timeCount reaches 0

char timerInterruptFlag;            //set to SET when a Timer0 intrrupt occurs



int main( void )
{
  
  WDTCTL = WDTPW + WDTHOLD;          // Stop watchdog timer
 
  BCSCTL1 = CALBC1_1MHZ;             // Set range  (1 Mhz)
  DCOCTL = CALDCO_1MHZ;              // Set DCO step + modulation */ 

  SPI_Master_Init();
  
  
  P1OUT &= ~(BIT0+BIT6);            // Set P1.0 and P1.6 to 0 (when output)
  P1DIR |= (BIT0+BIT6);             // Set P1.0 and P1.6 to output direction 
  
  timerInterruptFlag=CLEAR;

  ConfigTimer0();                    //Configure Timer0 Module
                                     //for 10 ms interrupt 
  
  _EINT();                           // enable (general) interrupts
                                     //eint <-----> bis #8,sr
  
  //example of a timed loop:
  
  for(;;){                                // loop forever 

    while(timerInterruptFlag != SET);     // loop forever while Flag not SET
    timerInterruptFlag=CLEAR;             // Clear timer flag
  
    LedsShifter();

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

//LedsShifter() --------------------------------------------

void LedsShifter(){
  static char data=0x01;
  
  SPI_Write(data);
  if (elapsedTimeFlag==SET){
    elapsedTimeFlag=CLEAR;
    if ((data&0x20) == 0x20){
      data=0x01;
    }else{
      data=(data<<1);
    }  
    timeCount=timeValue;                   //time for Green 
  }           
  
 
  TimeCounter();
  
}  


// TimeCounter() --------------------------------------------

void TimeCounter(){
  timeCount--;
  if (timeCount==0){
    elapsedTimeFlag=SET;
  }
}  
//-----------------------------------------------------------