#include  <msp430f2122.h>

extern void ConfigTimer0();          // in module Configs.c

void HandleRedLed();
void EvaluateInputTransition();

enum FLAG_STATE {CLEAR,SET};        // define constants CLEAR=0 , SET=1

char timerInterruptFlag,inputTransitionEvenFlag,inputTransitionOddFlag;


int main( void )
{
  
  WDTCTL = WDTPW + WDTHOLD;          // Stop watchdog timer
 
  BCSCTL1 = CALBC1_1MHZ;             // Set range  (1 Mhz)
  DCOCTL = CALDCO_1MHZ;              // Set DCO step + modulation */ 
  
  P1OUT=(P1OUT|BIT0)&(~BIT6);         // Set P1.0 to 1, P1.6 to 0 (when outputs)  
  P1DIR |= (BIT0+BIT6);               // Set P1.0 and P1.6 to output direction 

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 
  // Pull up resistor in P1.3
  P1OUT |= BIT3;                      // Bit 3 of P1OUT in 1
  P1REN |= BIT3;                      // Bit 3 of P1REN in 1
                                      // REN:Pullup/Pulldown Resistor Enable
                                      // register
//--------------------------------------------------------------------------  
  
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  P1IES |= BIT3;                      // P1.3 Hi/Low transition detection
                                      // IES:Interrupt Edge Select register
  P1IFG &= ~BIT3;                     // P1.3 IFG cleared 
                                      // IFG:Interupt Flag register
//--------------------------------------------------------------------------
 
  
  inputTransitionEvenFlag=SET;
  inputTransitionOddFlag=CLEAR;
  
  timerInterruptFlag=CLEAR;

  ConfigTimer0();                    //Configure Timer0 Module
  
  _EINT();                           // enable (general) interrupts
                                     //eint <-----> bis #8,sr
  
  //example of a timed loop:
  
  for(;;){                                // loop forever 

    while(timerInterruptFlag != SET);     // loop forever while Flag not set to YES
    timerInterruptFlag=CLEAR;             // reset timer flag
    
    if (inputTransitionEvenFlag==SET){
      inputTransitionEvenFlag=CLEAR;
      P1OUT=(P1OUT|BIT0)&(~BIT6);             //Red ON, Green OFF
    }else if (inputTransitionOddFlag==SET){
      inputTransitionOddFlag=CLEAR;
      P1OUT=(P1OUT|BIT6)&(~BIT0);             //Red OFF, Green ON
    }
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
      EvaluateInputTransition();
      
  
}
//------------------------------------------------------------------------------


// EvaluateInputTransition --------------------------------------------
void EvaluateInputTransition(){
  enum NUMBER {EVEN,ODD};
  
  static char transitionNumber=EVEN;
  
    if ((P1IFG & BIT3) != 0){
      P1IFG &= ~BIT3;                   // P1.3 IFG cleared 
      
      if(transitionNumber==EVEN){
        transitionNumber=ODD;
        inputTransitionOddFlag=SET ;
      }else{
        transitionNumber=EVEN;
        inputTransitionEvenFlag=SET ;        
      }

    }
}

//----------------------------------------------------------------------