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
                                              // => Red Light OFF
  asm("BIS.B   #0x1, &0x22");
  
 
  //for (;;)
  //{
 
    asm("main_10:");                        //1111111111111111111111111111  
    
    //P1OUT ^= 0x01;                        // Toggle P1.0 using exclusive-OR
    asm("XOR.B   #0x1, &0x21");    
 
    //i = 50000;                            // Delay
    asm("MOV.W   #0xc350, &i");    
    
  
    //do 
    asm("main_20:");                        //2222222222222222222222222222
    
      //i--;
      asm("ADD.W #0xffff, &i");
      
    //while (i != 0);
    asm("CMP.W #0x0, &i\n"
        "JNE main_20");                     //2222222222222222222222222222
    
    asm("jmp main_10");                     //1111111111111111111111111111

  //}
}
