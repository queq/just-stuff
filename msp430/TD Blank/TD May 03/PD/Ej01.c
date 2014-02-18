#include  <msp430f2122.h>
#include "Debounce.h"

extern void ConfigTimer0();          // in module Configs.c

void EvaluateInputTransition();

void LedsSequencer_A();            // leds 1 sequenced by pulses 
void PulseCounter();

void LedsSequencer_B();            // leds 2 sequenced by time  
void TimeCounter();

enum FLAG_STATE {CLEAR,SET};        // define constants CLEAR=0 , SET=1

enum SYSTEM_STATE_NAMES {S0,S1};    // define system state names

char pulseCount;                    //value to load the PulseCounter
char endedCountFlag;                //set when pulseCount reaches 0

int timeCount;                      //value to load the TimerCounter
char elapsedTimeFlag;               //set to SET when timeCount reaches 0


char timerInterruptFlag,inputTransitionFlag;

int main( void )
{
  
  WDTCTL = WDTPW + WDTHOLD;          // Stop watchdog timer
 
  BCSCTL1 = CALBC1_1MHZ;             // Set range  (1 Mhz)
  DCOCTL = CALDCO_1MHZ;              // Set DCO step + modulation */ 
  

//Red1 On, Green1 Off +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  P1OUT=(P1OUT|BIT0)&(~BIT6);         // Set P1.0 to 1, P1.6 to 0 (when outputs)  
  P1DIR |= (BIT0+BIT6);               // Set P1.0 and P1.6 to output direction 
//----------------------------------------------------------------------------- 
  
  
//NEW: Configure P2.6 and P2.7 as general I/O pins+++++++++++++++++++++++++++

P2SEL  &= ~BIT6;                      // Configure P2.6 as I/O pin
P2SEL  &= ~BIT7;                      // Configure P2.7 as I/O pin

// --------------------------------------------------------------------------    

//Pull up resistor in P2.7++++++++++++++++++++++++++++++++++++++++++++++++++ 
  P2OUT |= BIT7;                      // Bit 7 of P2OUT in 1
  P2REN |= BIT7;                      // Bit 7 of P2REN in 1
                                      // REN:Pullup/Pulldown Resistor Enable
                                      // register
//--------------------------------------------------------------------------  
  
//Hi/Low transition detection in P2.7+++++++++++++++++++++++++++++++++++++++++++
  P2IES |= BIT7;                      // P2.6 Hi/Low transition detection
                                      // IES:Interrupt Edge Select register
  P2IFG &= ~BIT7;                     // P2.6 IFG cleared 
                                      // IFG:Interupt Flag register
//-----------------------------------------------------------------------------
  
//Red2 On, Green2 Off +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  P2OUT=(P2OUT|BIT0)&(~BIT6);         // Set P2.0 to 1, P2.6 to 0 (when outputs)  
  P2DIR |= (BIT0+BIT6);               // Set P2.0 and P2.6 to output direction 
//-----------------------------------------------------------------------------   
  
  pulseCount=1;                     // pulses count for Red1
  timeCount=100;                    // time for Red2 (100x10ms = 1 seg)

  inputTransitionFlag=CLEAR;
  
  timerInterruptFlag=CLEAR;

  ConfigTimer0();                    //Configure Timer0 Module
                                     //for 10 ms interrupt 
  _EINT();                           // enable (general) interrupts
                                     //eint <-----> bis #8,sr
  
//Timed loop:+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
  for(;;){                            // loop forever 
    while(timerInterruptFlag != SET);  // loop forever while Flag not set to YES
    timerInterruptFlag=CLEAR;          // reset timer flag
    
    LedsSequencer_A();
    LedsSequencer_B();
   
    
  }

//---------------------------------------------------------------------------

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
      //EvaluateInputTransition();
      
  
}
//------------------------------------------------------------------------------


// LedsSequencer_A  -------------------------------------------------------------
void LedsSequencer_A(){
  
  static char presentState=S0;             //in S0 Red1 is on
  
  switch (presentState){
      case S0:
        P1OUT=(P1OUT | BIT0) & ~BIT6;     //Red1 ON; Green1 OFF 
        if (endedCountFlag==SET){
          endedCountFlag=CLEAR;
          pulseCount=4;                   //time for Green1 
          presentState=S1;                //in S1 Green1 on
        }        
        break;
         
       case S1:
        P1OUT=(P1OUT & ~BIT0) | BIT6 ;     //Red1 OFF; Green1 ON    
        if (endedCountFlag==SET){
          endedCountFlag=CLEAR;
          pulseCount=1;                   //time for Red1 
          presentState=S0;                //in S0 Red1 is on
        }  
        break;         
        
  } 

  EvaluateInputTransition();         //Find if a transition has happened 
  PulseCounter();  
  
}  
//------------------------------------------------------------------------------



// EvaluateInputTransition --------------------------------------------
void EvaluateInputTransition(){

  char debounceFlag;                    // value returned by dbounce routine
   
  if ((P2IFG & BIT7) != 0){             // edge detected?
    debounceFlag=Debounce(2,7,3);    
    if (debounceFlag==1){               // true 1 to 0 transition detected
      debounceFlag=0;                   // clear rotine indicator
      P2IFG &= ~BIT7;                   // P2.7 IFG cleared 
      inputTransitionFlag=SET ;         // Set main transition indicator flag
    }else if(debounceFlag==2){          // no 1 to 0 transition detected 
      debounceFlag=0;                   // clear rotine indicator
      P2IFG &= ~BIT7;                   // P2.7 IFG cleared 
    }
  }
   
}
//----------------------------------------------------------------------


//PulseCounter  -------------------------------------------------------
void PulseCounter(){
 
  if(inputTransitionFlag==SET){
    inputTransitionFlag=CLEAR;
    pulseCount--;
    if (pulseCount==0) endedCountFlag=SET;
  } 
}  
//----------------------------------------------------------------------

//LedsSequencer_B() --------------------------------------------
void LedsSequencer_B(){

static char presentState=S0;                  //in S0 Red2 is on

switch (presentState){
      case S0:
        P2OUT=(P2OUT | BIT0) & ~BIT6;     //Red2 ON; Green2 OFF 
        if (elapsedTimeFlag==SET){
          elapsedTimeFlag=CLEAR;
          timeCount=400;                   //time for Green2 
          presentState=S1;                //in S1 Green2 on
        }        
        break;
         
       case S1:
        P2OUT=(P2OUT & ~BIT0) | BIT6 ;     //Red2 OFF; Green2 ON    
        if (elapsedTimeFlag==SET){
          elapsedTimeFlag=CLEAR;
          timeCount=100;                   //time for Red2 
          presentState=S0;                //in S0 Red2 is on
        }  
        break;         
        
    }

    TimeCounter();

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
