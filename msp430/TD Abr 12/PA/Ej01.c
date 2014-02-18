#include  <msp430f2122.h>

int main( void )
{
  
  WDTCTL = WDTPW + WDTHOLD;          // Stop watchdog timer
 
  BCSCTL1 = CALBC1_1MHZ;             // Set range  (1 Mhz)
  DCOCTL = CALDCO_1MHZ;              // Set DCO step + modulation */ 
  
  P1OUT &= ~0x01;                    // Set P1.0 to 0 (when output)
  P1DIR |= 0x01;                     // Set P1.0 to output direction 

  //Configure Timer0 Module --------------------------------------------------
  // an interrupt occurs every 50 ms
  CCTL0 = CCIE;  // CCR0 interrupt enabled (compare) (set bit 4 of TACCTL0)
  CCR0 = 12315;  //cualquier valor entre 0 y 65535
  TACTL = TASSEL_2 + ID_2 + MC_1;    //Timer_A clock source: SMCLK
                                     //Input Divider: 4 ; (TAR clock = SMCLK/4) 
                                     //Mode Control: cont-up-mode
  //--------------------------------------------------------------------------  

 
  _EINT();                           // enable (general) interrupts
                                     //eint <-----> bis #8,sr
   
  while(1);                          // loop forever

  return 0;
}


// Timer_A Interrupt Vector handler --------------------------------------------
#pragma vector=TIMER0_A0_VECTOR      //vector de interupcion para channel CCR0
__interrupt void Timer0_A0(void)
{
    
      //CCTL0 &=~ BIT0;(not needed)   //CCIFG is Bit 0 of CCTLO register 
      //The TACCR0 CCIFG flag is automatically reset when the TACCR0 interrupt
      //request is serviced
  
      static int redCounter=20;
  
      redCounter--;
      if (redCounter==0){
        P1OUT ^= 0x01;               //toggle led
        redCounter=20;                // Init counter again
      }  
  
}
//------------------------------------------------------------------------------
