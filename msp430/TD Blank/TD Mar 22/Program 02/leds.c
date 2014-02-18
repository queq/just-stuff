#include <msp430f2122.h>	

unsigned int i;

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
 
  BCSCTL1 = CALBC1_1MHZ;                    // Set range  (1 Mhz)
  DCOCTL = CALDCO_1MHZ;                     // Set DCO step + modulation */ 
  
    
  P1OUT = (P1OUT & ~0x01) | 0x02;           // Set P1.0 to 0 and  
                                            // Set P1.1 to 1 (when outputs): 
  
  P1DIR |= 0x03;                            // Set P1.0 and P1.1 to output direction 
                                            // => Red Light OFF and Yellow Light ON
 
  for (;;)
  {
  
    P1OUT ^= 0x03;                          // Toggle P1.0 and P1.1 using exclusive-OR
                                            // => Change Red Light state and
                                            //    change Yellow Light state

    i = 50000;                              // Delay 1/2 second
    do 
      i--;
    while (i != 0);
  }
}
