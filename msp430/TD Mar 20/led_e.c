#include <msp430f2122.h>	

unsigned int i;

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
 
  BCSCTL1 = CALBC1_1MHZ;                    // Set range  (1 Mhz)
  DCOCTL = CALDCO_1MHZ;                     // Set DCO step + modulation */ 
  
  //P1OUT &= ~0x01;                           // Set P1.0 to 0 (when output)
  //asm("BIC.B   #0x1, &0x21");
  asm("DB 0xd2,0xc3,0x21,0x00");
  
  //P1DIR |= 0x01;                            // Set P1.0 to output direction 
                                              // => Red Light OFF
  //asm("BIS.B   #0x1, &0x22");
  asm("DB 0xd2,0xd3,0x22,0x00");
 
  //for (;;)
  //{
 
    asm("main_10:");                        //1111111111111111111111111111  
    
    //P1OUT ^= 0x01;                        // Toggle P1.0 using exclusive-OR
    //asm("XOR.B   #0x1, &0x21");  
    asm("DB 0xd2,0xe3,0x21,0x00");
 
    //i = 50000;                            // Delay
    //asm("MOV.W   #0xc350, &i");
    asm("DB 0xb2,0x40,0x50,0xc3,0x00,0x02");    
    
  
    //do 
    asm("main_20:");                        //2222222222222222222222222222
    
      //i--;
      //asm("ADD.W #0xffff, &i");
      asm("DB 0xb2,0x53,0x00,0x02");
      
    //while (i != 0);
    //asm("CMP.W #0x0, &i\n"
    //    "JNE main_20"); 
    asm("DB 0x82,0x93,0x00,0x02,0xfb,0x23");//2222222222222222222222222222
    
    //asm("jmp main_10");                   //1111111111111111111111111111
    asm("DB 0xf5,0x3f");
  //}
}
