#include <16F887.h>
#device adc=10

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES INTRC_IO                 //Internal RC Osc, no CLKOUT
#FUSES NOPUT                    //No Power Up Timer
#FUSES NOMCLR                   //Master Clear pin used for I/O
#FUSES PROTECT                  //Code protected from reads
#FUSES CPD                      //Data EEPROM Code Protected
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOIESO                   //Internal External Switch Over mode disabled
#FUSES NOFCMEN                  //Fail-safe clock monitor disabled
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NODEBUG                  //No Debug mode for ICD
#FUSES NOWRT                    //Program memory not write protected
#FUSES BORV40                   //Brownout reset at 4.0V

#use delay(clock=4000000)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)


///////////////////////////////////
#define RS   PIN_E0
#define RW   PIN_E1
#define EN   PIN_E2
 
#define D4   PIN_C0
#define D5   PIN_C1
#define D6   PIN_C2
#define D7   PIN_C3
//////////////////////////////////
#define inc PIN_C4
#define dec PIN_C5
///////////////////////////////
#define SS4 PIN_D0
#define SS3 PIN_D1
#define SS2 PIN_D2
#define SS1 PIN_D3

