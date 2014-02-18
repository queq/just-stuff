#include  <msp430f2122.h>

extern void ConfigTimer0();          // in module Configs.c


int main( void )
{
  
  WDTCTL = WDTPW + WDTHOLD;          // Stop watchdog timer
 
  BCSCTL1 = CALBC1_1MHZ;             // Set range  (1 Mhz)
  DCOCTL = CALDCO_1MHZ;              // Set DCO step + modulation */ 

  P1OUT &= ~0x01;                    // Set P1.0 to 0 (when output)
  P1DIR |= 0x01;                     // Set P1.0 to output direction 
  
  ConfigTimer0();                    //Configure Timer0 Module

  _EINT();                           // enable (general) interrupts
                                     //eint <-----> bis #8,sr

  while(1);                          // loop forever

  return 0;
}


// Timer_A Interrupt Vector handler --------------------------------------------
#pragma vector=TIMER0_A0_VECTOR      //vector de interupcion para channel CCR0
__interrupt void Timer0_A0(void)
{
      static int redCounter=20;
      
      //CCTL0 &=~ BIT0;(not needed)   //CCIFG is Bit 0 of CCTLO register 
      //The TACCR0 CCIFG flag is automatically reset when the TACCR0 interrupt
      //request is serviced
  
      redCounter--;
      if (redCounter==0){
        P1OUT ^= 0x01;               //toggle led
        redCounter=20;                // Init counter again
      }  
  
}
//------------------------------------------------------------------------------
