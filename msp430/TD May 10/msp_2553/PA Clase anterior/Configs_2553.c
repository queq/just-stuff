#include  <msp430f2122.h>


//Configure Timer0 Module+++++++++++++++++++++++++++++++++++++++++++++++++++
void ConfigTimer0(){
  
  CCTL0 = CCIE;  // CCR0 interrupt enabled (compare) (set bit 4 of TACCTL0)
  CCR0 = 2499;  //cualquier valor entre 0 y 65535 (2499 <-> 10 ms)
  TACTL = TASSEL_2 + ID_2 + MC_1;    //Timer_A clock source: SMCLK
                                     //Input Divider: 4 ; (TAR clock = SMCLK/4) 
                                     //Mode Control: cont-up-mode
  
}
//--------------------------------------------------------------------------


//Configure SPI Master 430F2122 USCI_B0 ++++++++++++++++++++++++++++++++++++
void SPI_Master_Init(){    
  UCB0CTL1 = UCSWRST;    
  P1SEL |= BIT5+BIT7;                           //P1.5,7 USCI_B0 option select 
  P1SEL2 |= BIT5+BIT7;                          //P1.5,7 USCI_B0 option select 
  UCB0CTL0 |= UCCKPL + UCMSB + UCMST + UCSYNC;  // 3-pin, 8-bit SPI master
  UCB0CTL1 |= UCSSEL_2;                         // BRCLK=SMCLK
  UCB0BR0 |= 0x02;                              // UCB0CLK = SMCLK/2
  UCB0BR1 = 0;                                  //
  UCB0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**  
}
//--------------------------------------------------------------------------


// Write Data using SPI+++++++++++++++++++++++++++++++++++++++++++++++++++++
void SPI_Write(char data){
  while(UCB0STAT & UCBUSY);                // USCI_B0 inactive?
  while (!(IFG2 & UCB0TXIFG));             // USCI_B0 TX buffer ready?
  UCB0TXBUF = data;                        // Transmit data 
  
}
//-------------------------------------------------------------------------

