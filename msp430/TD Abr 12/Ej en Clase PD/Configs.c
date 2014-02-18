#include  <msp430f2122.h>

void ConfigTimer0(){
  
  //Configure Timer0 Module --------------------------------------------------
  CCTL0 = CCIE;  // CCR0 interrupt enabled (compare) (set bit 4 of TACCTL0)
  CCR0 = 15624;  //cualquier valor entre 0 y 65535
  TACTL = TASSEL_2 + ID_3 + MC_1;    //Timer_A clock source: SMCLK
                                     //Input Divider: 8 ; (TAR clock = SMCLK/8) 
                                     //Mode Control: cont-up-mode
  //--------------------------------------------------------------------------  

}

