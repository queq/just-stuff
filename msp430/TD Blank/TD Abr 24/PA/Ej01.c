#include  <msp430f2122.h>

extern void ConfigTimer0();          // in module Configs.c

void TimeCounter();

enum FLAGS_STATES {CLEAR,SET};              // define constant CLEAR=0 , SET=1
enum SYSTEM_STATE_NAMES {S0,S1,S2,S3};      // define system state names

char presentState;                  //actual state  
char timeCount;                     //value to load the TimerCounter
char elapsedTimeFlag;               //set to SET when timeCount reaches 0

char timerInterruptFlag;            //set to SET when a Timer0 intrrupt occurs


int main( void )
{
  
  WDTCTL = WDTPW + WDTHOLD;          // Stop watchdog timer
 
  BCSCTL1 = CALBC1_1MHZ;             // Set range  (1 Mhz)
  DCOCTL = CALDCO_1MHZ;              // Set DCO step + modulation */ 


  P1OUT &= ~(BIT0+BIT6);            // Set P1.0 and P1.6 to 0 (when output)
  P1DIR |= (BIT0+BIT6);             // Set P1.0 and P1.6 to output direction 
  
  presentState=S0;                  //in S0 red is on
  timeCount=20;                     //time for Red
  
  timerInterruptFlag=CLEAR;

  ConfigTimer0();                    //Configure Timer0 Module
  
  _EINT();                           // enable (general) interrupts
                                     //eint <-----> bis #8,sr
  
  //example of a timed loop:
  
  for(;;){                                // loop forever 

    while(timerInterruptFlag != SET);     // loop forever while Flag not SET
    timerInterruptFlag=CLEAR;             // Clear timer flag
    
    switch (presentState){
      case S0:
        P1OUT=(P1OUT | BIT0) & ~BIT6;     //Red ON; Green OFF 
        if (elapsedTimeFlag==SET){
          elapsedTimeFlag=CLEAR;
          timeCount=80;                   //time for Green 
          presentState=S1;                //in S1 Green on
        }        
        break;
         
       case S1:
        P1OUT=(P1OUT & ~BIT0) | BIT6 ;     //Red OFF; Green ON    
        if (elapsedTimeFlag==SET){
          elapsedTimeFlag=CLEAR;
          timeCount=20;                   //time for Red 
          presentState=S0;                //in S0 Red is on
        }  
        break;         
        
    }
    
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