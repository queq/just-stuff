#include  <msp430f2122.h>

extern void ConfigTimer0();          // in module Configs.c

void HandleRedLed();
void HandleGreenLed();

enum FLAG_STATE {CLEAR,SET};        // define constants CLEAR=0 , SET=1

char timerInterruptFlag;


int main( void )
{
  
  WDTCTL = WDTPW + WDTHOLD;          // Stop watchdog timer
 
  BCSCTL1 = CALBC1_1MHZ;             // Set range  (1 Mhz)
  DCOCTL = CALDCO_1MHZ;              // Set DCO step + modulation */ 
  
  
  //P1OUT &= ~0x01;                    // Set P1.0 to 0 (when output)
  P1OUT &= ~(BIT0+BIT6);                    // Set P1.0 to 0 (when output)
  //P1DIR |= 0x01;                     // Set P1.0 to output direction 
  P1DIR |= (BIT0+BIT6);                     // Set P1.0 to output direction 
  
  
  timerInterruptFlag=CLEAR;

  ConfigTimer0();                    //Configure Timer0 Module
  
  _EINT();                           // enable (general) interrupts
                                     //eint <-----> bis #8,sr
  
  //example of a timed loop:
  
  for(;;){                                // loop forever 

    while(timerInterruptFlag != SET);     // loop forever while Flag not set to YES
    timerInterruptFlag=CLEAR;             // reset timer flag
    HandleRedLed();                       // called every 50 ms
    HandleGreenLed();
    
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


void HandleRedLed(){
   
   static int redCounter=20; 
  
   redCounter--;
   if (redCounter==0){
      P1OUT ^= 0x01;               //toggle led       
      redCounter=20;                // Init counter again
   }   

}

void HandleGreenLed(){
   
   static int greenCounter=80; 
  
   greenCounter--;
   if (greenCounter==0){
      P1OUT ^= BIT6;               //toggle led       
      greenCounter=80;                // Init counter again
   }   

} 
