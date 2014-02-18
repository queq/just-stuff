#include  <msp430f2122.h>

extern void ConfigTimer0();          // in module Configs.c

void HandleRedLed();

enum boolean {NO,YES};              // define constants NO=0 , YES=1

char timerInterruptFlag;


int main( void )
{
  
  WDTCTL = WDTPW + WDTHOLD;          // Stop watchdog timer
 
  BCSCTL1 = CALBC1_1MHZ;             // Set range  (1 Mhz)
  DCOCTL = CALDCO_1MHZ;              // Set DCO step + modulation */ 
  
  
  P1OUT &= ~0x01;                    // Set P1.0 to 0 (when output)
  P1DIR |= 0x01;                     // Set P1.0 to output direction 
  
  timerInterruptFlag=NO;

  ConfigTimer0();                    //Configure Timer0 Module
  
  _EINT();                           // enable (general) interrupts
                                     //eint <-----> bis #8,sr
  
  //example of a timed loop:
  
  for(;;){                                // loop forever 

    while(timerInterruptFlag != YES);     // loop forever while Flag not set to YES
    timerInterruptFlag=NO;                // reset timer flag
    HandleRedLed();                       // called every 125 ms
    
  }

  return 0;
}


// Timer_A Interrupt Vector handler -------------------------------------------------------------
#pragma vector=TIMER0_A0_VECTOR      //vector de interupcion para channel CCR0
__interrupt void Timer0_A0(void)
{
   
      //CCTL0 &=~ BIT0;(not needed)   //CCIFG is Bit 0 of CCTLO register 
      //The TACCR0 CCIFG flag is automatically reset when the TACCR0 interrupt request is serviced
  
      timerInterruptFlag=YES;
  
}
//-----------------------------------------------------------------------------------------------


void HandleRedLed(){
   
   static int redCounter=8; 
  
   redCounter--;
   if (redCounter==0){
      P1OUT ^= 0x01;               //toggle led       
      redCounter=8;                // Init counter again
   }   

}  
