#include "msp430F2122.h"

void delay(unsigned int n);           // n * 125 ms     

int main(void)
{

  WDTCTL = WDTPW + WDTHOLD;             // Stop watchdog timer
  
  BCSCTL1 = CALBC1_1MHZ;                // Set range  (1 MHz)
  DCOCTL = CALDCO_1MHZ;                 // Set DCO step + modulation 
  
  P1OUT &= ~0x01;                       // Set P1.0 to 0 (when output)
  P1DIR |= 0x01;                        // Set P1.0 to output direction

  for (;;)
  {
    
    P1OUT ^= 0x01;                      // Toggle P1.0 using exclusive-OR
 
    delay(1);

  }
  
}

void delay(unsigned int n){           
    unsigned int i,j;  
    
    j = n;
    do{                                 // SW Delay
        i = 31250;                          
        do i--;
        while (i != 0);
        j--;        
    }while (j != 0);    
    
}