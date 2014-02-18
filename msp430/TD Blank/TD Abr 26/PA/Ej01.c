#include  <msp430f2122.h>
#include "Debounce.h"

extern void ConfigTimer0();          // in module Configs.c

void EvaluateInputTransition();

enum FLAG_STATE {CLEAR,SET};        // define constants CLEAR=0 , SET=1

char timerInterruptFlag,inputTransitionFlag;

int main( void )
{
  
  WDTCTL = WDTPW + WDTHOLD;          // Stop watchdog timer
 
  BCSCTL1 = CALBC1_1MHZ;             // Set range  (1 Mhz)
  DCOCTL = CALDCO_1MHZ;              // Set DCO step + modulation */ 
  

//Red On, Green Off +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  P1OUT=(P1OUT|BIT0)&(~BIT6);         // Set P1.0 to 1, P1.6 to 0 (when outputs)  
  P1DIR |= (BIT0+BIT6);               // Set P1.0 and P1.6 to output direction 
//-----------------------------------------------------------------------------  

//Pull up resistor in P1.3++++++++++++++++++++++++++++++++++++++++++++++++++ 
  P1OUT |= BIT3;                      // Bit 3 of P1OUT in 1
  P1REN |= BIT3;                      // Bit 3 of P1REN in 1
                                      // REN:Pullup/Pulldown Resistor Enable
                                      // register
//--------------------------------------------------------------------------  
  
//Hi/Low transition detection+++++++++++++++++++++++++++++++++++++++++++++++
  P1IES |= BIT3;                      // P1.3 Hi/Low transition detection
                                      // IES:Interrupt Edge Select register
  P1IFG &= ~BIT3;                     // P1.3 IFG cleared 
                                      // IFG:Interupt Flag register
//--------------------------------------------------------------------------
  
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
    
    if (inputTransitionFlag==SET){
      inputTransitionFlag=CLEAR;
      P1OUT ^=(BIT0 + BIT6);           //Toggle Leds
    }
    
    EvaluateInputTransition();         //Find if a transition has happened 
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


// EvaluateInputTransition --------------------------------------------
void EvaluateInputTransition(){

  char debounceFlag;                    // value returned by dbounce routine
   
  if ((P1IFG & BIT3) != 0){             // edge detected?
    debounceFlag=Debounce(1,3,3);    
    if (debounceFlag==1){               // true 1 to 0 transition detected
      debounceFlag=0;                   // clear rotine indicator
      P1IFG &= ~BIT3;                   // P1.3 IFG cleared 
      inputTransitionFlag=SET ;         // Set main transition indicator flag
    }else if(debounceFlag==2){          // no 1 to 0 transition detected 
      debounceFlag=0;                   // clear rotine indicator
      P1IFG &= ~BIT3;                   // P1.3 IFG cleared 
    }
  }
   
}
//----------------------------------------------------------------------
