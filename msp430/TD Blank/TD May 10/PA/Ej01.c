#include  <msp430f2122.h>
#include "Debounce.h"

extern void ConfigTimer0();          // in module Configs.c
extern void SPI_Master_Init();       //
extern void SPI_Write(char dato);    //


void EvaluateInputTransition();

void LedsShifter_a();               //do sequence_a
void LedsShifter_b();               //do sequence_b
void TimeCounter();                 //count time steps for sequence_a and _b

void SequenceController();          //choose sequence




enum FLAGS_STATES {CLEAR,SET};              // define constant CLEAR=0 , SET=1
enum SYSTEM_STATE_NAMES {S0,S1,S2,S3};      // define system state names

#define timeValue 50                //value that fixes sequence time step 
int timeCount=timeValue;            //variable used by TimerCounter
char elapsedTimeFlag;               //SET when timeCount reaches 0

char ready_a=CLEAR;                 //SET when a sequece_a ends a cicle
char ready_b=CLEAR;                 //SET when a sequece_b ends a cicle

char timerInterruptFlag=CLEAR;            //SET when a Timer0 interrupt occurs

char inputTransitionFlag=CLEAR;           //SET when a Hi-Low transition occurs

int main( void )
{
  
  WDTCTL = WDTPW + WDTHOLD;          // Stop watchdog timer
 
  BCSCTL1 = CALBC1_1MHZ;             // Set range  (1 Mhz)
  DCOCTL = CALDCO_1MHZ;              // Set DCO step + modulation */ 

  SPI_Master_Init();
  
  
//Pull up resistor in P1.3++++++++++++++++++++++++++++++++++++++++++++++++++ 
  P1OUT |= BIT3;                      // Bit 3 of P1OUT in 1
  P1REN |= BIT3;                      // Bit 3 of P1REN in 1
                                      // REN:Pullup/Pulldown Resistor Enable
                                      // register
//--------------------------------------------------------------------------  
  
//Hi/Low transition detection+++++++++++++++++++++++++++++++++++++++++++++++
  P1IES |= BIT3;                      // P1.3 Hi/Low transition detection
                                      // IES:Interrupt Edge Select register
  P1IFG &= ~BIT3;                     // P1.3 IFG cleared 
                                      // IFG:Interupt Flag register
//--------------------------------------------------------------------------  
  

  ConfigTimer0();                    //Configure Timer0 Module
                                     //for 10 ms interrupt 
  
  _EINT();                           // enable (general) interrupts
                                     //eint <-----> bis #8,sr
  
  //example of a timed loop:
  
  for(;;){                                // loop forever 

    while(timerInterruptFlag != SET);     // loop forever while Flag not SET
    timerInterruptFlag=CLEAR;             // Clear timer flag
  
//    LedsShifter_a();
//    LedsShifter_b();  
//    EvaluateInputTransition();            //Find if a transition has happened 
//    SequenceController();                 //Select desired sequence

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

//LedsShifter_b() --------------------------------------------

void LedsShifter_b(){
  static char data=0x20;
  
  SPI_Write(data);
  if (elapsedTimeFlag==SET){
    elapsedTimeFlag=CLEAR;
    if ((data&0x3F) == 0x01){
      ready_b=SET;
      data=0x20;
    }else{
      data=(data>>1);
    }  
    timeCount=timeValue;                
  }           
  
 
  TimeCounter();
  
}  
//------------------------------------------------------------------------------

//LedsShifter_a() --------------------------------------------

void LedsShifter_a(){
  static char data=0x01;
  
  SPI_Write(data);
  if (elapsedTimeFlag==SET){
    elapsedTimeFlag=CLEAR;
    if ((data&0x3F) == 0x20){
      ready_a=SET;
      data=0x01;
    }else{
      data=(data<<1);
    }  
    timeCount=timeValue;                  
  }           
  
 
  TimeCounter();
  
}  
//------------------------------------------------------------------------------

// TimeCounter() --------------------------------------------

void TimeCounter(){
  timeCount--;
  if (timeCount==0){
    elapsedTimeFlag=SET;
  }
}  
//------------------------------------------------------------------------------


// Sequence Controller --------------------------------------------
void SequenceController(){
    static char presentState=S0; 
    
    switch (presentState){
        case S0:
          LedsShifter_a();
          if (ready_a==SET){
            ready_a=CLEAR;
            if(inputTransitionFlag==SET){
              inputTransitionFlag=CLEAR;
              presentState=S1;          
            }
          }
          break;
           
         case S1:
          LedsShifter_b();
          if (ready_b==SET){
            ready_b=CLEAR;
            if(inputTransitionFlag==SET){
              inputTransitionFlag=CLEAR;
              presentState=S0;          
            }
          }          
          break;         
          
   }    
  
 
}
//------------------------------------------------------------------------------


// EvaluateInputTransition --------------------------------------------
void EvaluateInputTransition(){

  char debounceFlag;                    // value returned by dbounce routine
   
  if ((P1IFG & BIT3) != 0){             // edge detected?
    debounceFlag=Debounce(1,3,3);    
    if (debounceFlag==1){               // true 1 to 0 transition detected
      debounceFlag=0;                   // clear rotine indicator
      P1IFG &= ~BIT3;                   // P1.3 IFG cleared 
      inputTransitionFlag=SET ;         // Set main transition indicator flag
    }else if(debounceFlag==2){          // no 1 to 0 transition detected 
      debounceFlag=0;                   // clear rotine indicator
      P1IFG &= ~BIT3;                   // P1.3 IFG cleared 
    }
  }
   
}
//----------------------------------------------------------------------