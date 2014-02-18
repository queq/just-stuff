#include  <msp430f2122.h>

extern void ConfigTimer0();          // in module Configs.c
extern void SPI_Master_Init();       //
extern void SPI_Write(char dato);    //

void Display(char num);
void Counter();

void TimeCounter();

enum FLAGS_STATES {CLEAR,SET};              // define constant CLEAR=0 , SET=1
enum SYSTEM_STATE_NAMES {S0,S1,S2,S3};      // define system state names

#define timeValue 250
int timeCount=timeValue;             //value to load the TimerCounter
char elapsedTimeFlag;               //set to SET when timeCount reaches 0

char timerInterruptFlag;            //set to SET when a Timer0 intrrupt occurs


// ----------- NEW: Contatnt codes array for seven segment diaplay -------
const char digits[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
                       
const char dp=0x80;
//-------------------------------------------------------------------------



int main( void )
{
  
  WDTCTL = WDTPW + WDTHOLD;          // Stop watchdog timer
 
  BCSCTL1 = CALBC1_1MHZ;             // Set range  (1 Mhz)
  DCOCTL = CALDCO_1MHZ;              // Set DCO step + modulation */ 
  
  SPI_Master_Init();

  P1OUT &= ~(BIT0 + BIT1);            // Set P1.0 and P1.1 to 0 (when output)
  P1DIR |= (BIT0 + BIT1);             // Set P1.0 and P1.1 to output direction   
  
  timerInterruptFlag=CLEAR;

  ConfigTimer0();                    //Configure Timer0 Module
                                     //for 10 ms interrupt 
  
  _EINT();                           // enable (general) interrupts
                                     //eint <-----> bis #8,sr
  
  //example of a timed loop:
  
  for(;;){                                // loop forever 

    while(timerInterruptFlag != SET);     // loop forever while Flag not SET
    timerInterruptFlag=CLEAR;             // Clear timer flag
    
    Counter();

  }

  return 0;
}


// Timer_A Interrupt Vector handler --------------------------------------------
#pragma vector=TIMER0_A0_VECTOR      //vector de interupcion para channel CCR0
__interrupt void Timer0_A0(void)
{
   
      //CCTL0 &=~ BIT0;(not needed)   //CCIFG is Bit 0 of CCTLO register 
      //The TACCR0 CCIFG flag is automatically reset when the TACCR0 interrupt 
      //request is serviced
  
      timerInterruptFlag=SET;
  
}
//------------------------------------------------------------------------------

//Counter  ------------------------------------------
void Counter(){
  
  static char i=0;
    
  Display(i);
  if (elapsedTimeFlag==SET){
    elapsedTimeFlag=CLEAR;
    if (i<99) i++;
    else i=0;
    timeCount=timeValue;        
  }
  TimeCounter();  

}
//-----------------------------------------------------

//Display  --------------------------------------------
void Display(char num){
  
    char units,tenths;
    static char presentState=S0;
    
    tenths=num/10;
    units=num%10;
    
    switch(presentState){
      case S0:                                //refresh units
        P1OUT &= ~(BIT0 + BIT1);              //display off
        SPI_Write(digits[units]);
        P1OUT |= BIT0;                        //units on
        presentState=S1;
        break;

      case S1:                                //refresh tenths
        P1OUT &= ~(BIT0 + BIT1);              //display off
        SPI_Write(digits[tenths]);
        P1OUT |= BIT1;                       //tenths on
        presentState=S0;
        break;        
        
        

    }    
    
}
//-----------------------------------------------------------


// TimeCounter() --------------------------------------------

void TimeCounter(){
  timeCount--;
  if (timeCount==0){
    elapsedTimeFlag=SET;
  }
}  
//-----------------------------------------------------------