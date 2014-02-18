#include <msp430f2122.h>	

unsigned int i;

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
 
  BCSCTL1 = CALBC1_1MHZ;                    // Set range  (1 Mhz)
  DCOCTL = CALDCO_1MHZ;                     // Set DCO step + modulation */ 
  
  //P1OUT &= ~0x01;                           // Set P1.0 to 0 (when output)
  asm("BIC.B   #0x1, &0x21");
  
  //P1DIR |= 0x01;                            // Set P1.0 to output direction 
  asm("BIS.B   #0x1, &0x22");                                          // => Red Light OFF
 
  //for (;;)
  //{
 
    asm("main_10:");       
    
    P1OUT ^= 0x01;                          // Toggle P1.0 using exclusive-OR
 
    i = 50000;                              // Delay
  
    do 
      i--;
    while (i != 0);
    
    asm("jmp main_10");

  //}
}
