#include  <msp430f2122.h>

void ConfigTimer0(){
  
  //Configure Timer0 Module --------------------------------------------------
  // an interrupt occurs every 50 ms
  CCTL0 = CCIE;  // CCR0 interrupt enabled (compare) (set bit 4 of TACCTL0)
  CCR0 = 12499;  //cualquier valor entre 0 y 65535
  TACTL = TASSEL_2 + ID_2 + MC_1;    //Timer_A clock source: SMCLK
                                     //Input Divider: 4 ; (TAR clock = SMCLK/4) 
                                     //Mode Control: cont-up-mode
  //--------------------------------------------------------------------------
}

