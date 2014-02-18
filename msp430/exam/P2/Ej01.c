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

char num;

char dataArray[10][5]={
			{0x41,0x3A,0x36,0x2E,0x41},  // 0
			{0x7F,0x3F,0x00,0x3D,0x7F},  // 1
			{0x39,0x36,0x2E,0x1E,0x3D},  // 2
			{0x4E,0x34,0x3A,0x3E,0x5E},  // 3
			{0x6F,0x00,0x6D,0x6B,0x67},  // 4
			{0x46,0x3A,0x3A,0x3A,0x58},  // 5
			{0x4F,0x36,0x36,0x35,0x43},  // 6
			{0x7C,0x7A,0x76,0x0E,0x7E},  // 7
			{0x49,0x36,0x36,0x36,0x49},  // 8
			{0x61,0x56,0x36,0x36,0x79}   // 9

};

int main( void )
{
  
  WDTCTL = WDTPW + WDTHOLD;          // Stop watchdog timer
 
  BCSCTL1 = CALBC1_1MHZ;             // Set range  (1 Mhz)
  DCOCTL = CALDCO_1MHZ;              // Set DCO step + modulation */ 
  
  SPI_Master_Init();
  
  num=0;
  
  P2OUT &= ~(0x1F);            // Set P2.0 to P2.4 to 0 (when output)
  P2DIR |= (0x1F);             // Set P2.0 and P2.4 to output direction 
  
  timerInterruptFlag=CLEAR;

  ConfigTimer0();                    //Configure Timer0 Module
                                     //for 10 ms interrupt 
  
  _EINT();                           // enable (general) interrupts
                                     //eint <-----> bis #8,sr
  
  //example of a timed loop:
  
  for(;;){                                // loop forever 

    while(timerInterruptFlag != SET);     // loop forever while Flag not SET
    timerInterruptFlag=CLEAR;             // Clear timer flag
    
    Display(num);

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
  
  static char presentState=S0;
  
  num=i;
  
  switch(presentState){
      case S0:
		if (elapsedTimeFlag==SET){
		  elapsedTimeFlag=CLEAR;
		  if (i<9)i++;
		  else{
			i=9;
			presentState = S1;
			timeCount = timeValue/2;
		  }
		  timeCount=timeValue;
		  
		}                              
      break;
	  
      case S1:
		if (elapsedTimeFlag==SET){
		  elapsedTimeFlag=CLEAR;
		  if (i>0)i--;
		  else{
			i=0;
			presentState = S2;
			timeCount = timeValue;
		  }
		  timeCount=timeValue/2;
		  
		}                              
      break;
	
      case S2:
		if (elapsedTimeFlag==SET){
		  elapsedTimeFlag=CLEAR;
		  if (i<8)i+=2;
		  else{
			i=0;
			presentState = S0;
			timeCount = timeValue;
		  }
		  timeCount=timeValue;
		  
		}                              
      break;
	
  }
  
  TimeCounter();  
  
  
}

//-----------------------------------------------------

//Display  --------------------------------------------
void Display(char num){

    static unsigned char i=0x01,k=0,ready=1;
    static char row;
    
    if (ready==1){
      ready=0;
      row=num;
    }
  
    P2OUT = i;
    SPI_Write(dataArray[row][k]);
    if (i<16){
      i<<=1;
      k++;     
    }else{
      i=0x01;
      k=0; 
      ready=1;
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