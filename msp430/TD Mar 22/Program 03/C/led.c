#include <msp430f2122.h>	

unsigned int i;

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
 
  BCSCTL1 = CALBC1_1MHZ;                    // Set range  (1 Mhz)
  DCOCTL = CALDCO_1MHZ;                     // Set DCO step + modulation */ 
  
  P1OUT &= ~0x01;                           // Set P1.0 to 0 (when output)
  
  P1DIR |= 0x07;                            // Set P1.0 to output direction 
 
  for (;;)
  {
   
    asm("ADD.B #0x1, &P1OUT");                          // Toggle P1.0 using exclusive-OR
 
    i = 50000;                              // Delay
  
    do 
      i--;
    while (i != 0);
    
  }
}
