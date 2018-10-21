#include "C:\Users\kcon\Desktop\solartrackmaharshi\main.h"
  #include <math.h>
  #ZERO_RAM

  char digit10=0;
  char digit2t=0;
  char digit11=0;
  char digit12=0;
  char digit13=0;
  long value=0;//
  long xadc=0;//
   
  char digitd1=0;
  char digitd2=0;
  
  char digit0=0;
  char digit1=0;
  char digitep;//
  char digitwp;//
  char digitsp;//
  char digitnp;//
  char digite0;//
  char digitw0;//
  char digits0;//
  char digitn0;//
  char digite1;//
  char digite2;//

  char digitw1;//
  char digitw2;//

  char digitn1;//
  char digitn2;//

  char digits1;//
  char digits2;//

  long digit1lcd;//
  long digit2lcd;//
  long digit3lcd;//
  long digit4lcd;//
  long digit5lcd;//
 
  
  char line10[20];
  char line20[20];  

BYTE CONST lin1[]= {" SOLAR TRACKER  "};  //digit5=1
BYTE CONST lin2[]= {"----------------"};  //digit5=2
BYTE CONST lin3[]= {" SOLAR AT  HOME "};  //digit5=3
BYTE CONST lin4[]= {"  POSITION SET  "};  //digit5=4


void delay1d()
 {

  delay_us( 100 );

}
void delay2d()
 {

  delay_us(400);

}  
//////////////////////////////////////////////////////////////
void delaylcd()
 {

  delay_ms( 1 );

}
void delay1lcd()
 {

  delay_ms( 4 );

}
void delay()
 {

  delay_ms( 6 );

}
void delaysecond()
 {

  delay_ms( 1000 );

}

void delay1()
 {

  delay_us( 100 );

}

void delay2()
 {

  delay_ms(4);

}  
void delay3()
 {

  delay_ms(5);

}  
void delay4()
 {

  delay_ms(5);

}  
void delay6()
 {

  delay_ms(300);

}  

/////////////////////////////////////////////////////////////
void wreprom()
{
digit13=digit10;
write_eeprom (0x00, digit13);

}

void wreprom1()
{
digit13=digitep;
write_eeprom (0x01, digit13);
digit13=digitwp;
write_eeprom (0x02, digit13);
digit13=digitsp;
write_eeprom (0x03, digit13);
digit13=digitnp;
write_eeprom (0x04, digit13);
 }



void readeeprom()
{
digit13 = read_eeprom (0x00);
digit2t=digit13;
if(digit2t>99)
{
digit13=3;
write_eeprom (0x00, digit13);
}
digit10=digit13;


digit13 = read_eeprom (0x01);
digit2t=digit13;
if(digit2t>59)
{
digit13=0;
write_eeprom (0x01, digit13);
}
digitep=digit13;


digit13 = read_eeprom (0x02);
digit2t=digit13;
if(digit2t>59)
{
digit13=0;
write_eeprom (0x02, digit13);
}
digitwp=digit13;


digit13 = read_eeprom (0x03);
digit2t=digit13;
if(digit2t>59)
{
digit13=0;
write_eeprom (0x03, digit13);
}
digitsp=digit13;


digit13 = read_eeprom (0x04);
digit2t=digit13;
if(digit2t>59)
{
digit13=0;
write_eeprom (0x04, digit13);
}
digitnp=digit13;



}

void offall()
{
output_low(SS1);
output_low(SS2);
output_low(SS3);
output_low(SS4);
}

void onx1()
{
output_high(SS1);
output_low(SS2);
delay();
offall();
}

void onx2()
{
output_high(SS2);
output_low(SS1);
delay();
offall();
}

void onx3()
{
output_high(SS3);
output_low(SS4);
delay();
offall();
}

void onx4()
{
output_high(SS4);
output_low(SS3);
delay();
offall();
}
 
void writelcd()
{
output_low(d4);
output_low(d5);
output_low(d6);
output_low(d7);
if( bit_test(digit1lcd,4))
{                               
output_high(d4);
}
if( bit_test(digit1lcd,5))
{                               
output_high(d5);
}
if( bit_test(digit1lcd,6))
{                               
output_high(d6);
}
if( bit_test(digit1lcd,7))
{                               
output_high(d7);
}

output_high(en);
output_low(en);
output_low(d4);
output_low(d5);
output_low(d6);
output_low(d7);
if( bit_test(digit1lcd,0))
{                               
output_high(d4);
}
if( bit_test(digit1lcd,1))
{                               
output_high(d5);
}
if( bit_test(digit1lcd,2))
{                               
output_high(d6);
}
if( bit_test(digit1lcd,3))
{                               
output_high(d7);
}
output_high(en);
output_low(en);
}

void lcdreset()
{
output_low(rs); 
output_low(en);
output_low(d7); 
output_low(d6); 
output_high(d5); 
output_high(d4);
output_high(en);
output_low(en);
delaylcd();
output_high(en);
output_low(en);
delaylcd();
output_high(en);
output_low(en);
delaylcd();
output_low(d4);
output_high(en);
output_low(en);
delaylcd();     
}        
         
void wrlcdcom4()
{
output_low(en);
output_low(rs);
writelcd();
delay1lcd();
}
void wrlcddata4()
{
output_low(en);
output_high(rs);
writelcd();
delaylcd();
}
void resetlcd()
{
 digit1lcd=0x2c;
 wrlcdcom4();

 digit1lcd=0x0c;
 wrlcdcom4();

 digit1lcd=0x06;
 wrlcdcom4();

 digit1lcd=0x01;
 wrlcdcom4();
delay1lcd();
}
void selectdis()
{
if (digit5lcd==1)
{
digit1lcd=(lin1[digit3lcd]);  
}
else if (digit5lcd==2)
{
digit1lcd=(lin2[digit3lcd]);  
}
else if (digit5lcd==3)
{
digit1lcd=(lin3[digit3lcd]);  
}
else if (digit5lcd==4)
{
digit1lcd=(lin4[digit3lcd]);  
}
}
void line1()
{
digit1lcd=0x80;
wrlcdcom4();
digit3lcd=0x00;
digit4lcd=0x00;
upperline:
if (digit4lcd<16)
{
selectdis();
wrlcddata4();
digit4lcd=digit4lcd+1;
digit3lcd=digit3lcd+1;
goto upperline;
}
}
void line2()
{
digit1lcd=0xc0;
wrlcdcom4();
digit3lcd=0x00;
digit4lcd=0x00;
line1line:
if (digit4lcd<16)
{
selectdis();
wrlcddata4();
digit4lcd=digit4lcd+1;
digit3lcd=digit3lcd+1;
goto line1line;
}
}

///////////////////////////////////////////////////////////////////////

void line1ram()
{
digit1lcd=0x80;
wrlcdcom4();
digit3lcd=0x00;
digit4lcd=0x00;
line1line20:
if (digit4lcd<16)
{
digit1lcd=line10[digit3lcd];
wrlcddata4();
digit4lcd=digit4lcd+1;
digit3lcd=digit3lcd+1;
goto line1line20;
}
}

void line2ram()
{
digit1lcd=0xc0;
wrlcdcom4();
digit3lcd=0x00;
digit4lcd=0x00;
upperline1:
if (digit4lcd<16)
{
digit1lcd=line20[digit3lcd];
wrlcddata4();
digit4lcd=digit4lcd+1;
digit3lcd=digit3lcd+1;
goto upperline1;
}
}

////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////
void ramline1()
{
   
      line10[0]='E';
      line10[1]='=';
      line10[2]=digite2+48;
      line10[3]=digite1+48;
      line10[4]=' ';
      line10[5]='W';
      line10[6]='=';
      line10[7]=digitw2+48;
      line10[8]=digitw1+48;
      line10[9]=' ';
      line10[10]=' ';
if(digitd1==0)
{
      line10[11]='L';
      line10[12]='E';
      line10[13]='V';
      line10[14]='E';
      line10[15]='L';
}
if(digitd1==1)
{
      line10[11]='L';
      line10[12]='E';
      line10[13]='F';
      line10[14]='T';
      line10[15]=' ';
}
if(digitd1==2)
{
      line10[11]='R';
      line10[12]='I';
      line10[13]='G';
      line10[14]='H';
      line10[15]='T';
}


}

void ramline2()
{

      line20[0]='N';
      line20[1]='=';
      line20[2]=digitn2+48;
      line20[3]=digitn1+48;
      line20[4]=' ';
      line20[5]='S';
      line20[6]='=';
      line20[7]=digits2+48;
      line20[8]=digits1+48;
      line20[9]=' ';
  
      line20[10]=digit12+48;
      line20[11]=digit11+48;
      line20[12]=' '; 

if(digitd2==0)
{
      line20[13]='L';
      line20[14]='V';
      line20[15]='L';
}
if(digitd2==1)
{
      line20[13]='U';
      line20[14]='P';
      line20[15]=' ';
}
if(digitd2==2)
{
      line20[13]='D';
      line20[14]='N';
      line20[15]=' ';
}
   


 }

 
void startloop()
{
delay();
lcdreset();
resetlcd();
digit5lcd=1; //display welcome
line1();
digit5lcd=2; //display welcome
line2();
}

 

 

void motor()
{
if(digitd1==1)
{
onx1();
}
if(digitd1==2)
{
onx2();
}
if(digitd2==1)
{
onx3();
}
if(digitd2==2)
{
onx4();
}
}

void adce()
{
  set_adc_channel(0);
      delay1();         // A/D setup functions- built-in
     value = read_adc(); 
     xadc=value;
     value=value/10;
     
value=value+digitep;
     xadc=value;
     if(xadc>99)
     {
     value=99;
     }
digite0=value; 

     digit1=value;
     digit1=digit1/10;
     digit0=(value-(digit1*10));
digite1=digit0;
digite2=digit1;

}

void adcw()
{
  set_adc_channel(1);
      delay1();         // A/D setup functions- built-in
     value = read_adc(); 
     xadc=value;
     value=value/10;
     
value=value+digitwp;
     xadc=value;
     if(xadc>99)
     {
     value=99;
     }
digitw0=value;

     digit1=value;
     digit1=digit1/10;
     digit0=(value-(digit1*10));
digitw1=digit0;
digitw2=digit1;

}

void adcn()
{
  set_adc_channel(2);
      delay1();         // A/D setup functions- built-in
     value = read_adc(); 
     xadc=value;
     value=value/10;
     
value=value+digitnp;
     xadc=value;
     if(xadc>99)
     {
     value=99;
     }
digitn0=value; 
     digit1=value;
     digit1=digit1/10;
     digit0=(value-(digit1*10));
digitn1=digit0;
digitn2=digit1;

}


void adcs()
{
  set_adc_channel(3);
      delay1();         // A/D setup functions- built-in
     value = read_adc(); 
     xadc=value;
     value=value/10;
value=value+digitsp;
     xadc=value;
     if(xadc>99)
     {
     value=99;
     }
digits0=value;
     digit1=value;
     digit1=digit1/10;
     digit0=(value-(digit1*10));
digits1=digit0;
digits2=digit1;

}




void adcall()
{
adce();
adcw();
adcn();
adcs();
}
void datacal()
{
digitd1=0;
digitd2=0;

digit1=digite0;
digit0=digitw0;
//digit1=digit1+1;
if(digit0>digit1)
{
digitd1=1;
}
digit1=digite0;
digit0=digitw0;
//digit0=digit0+1;
if(digit0<digit1)
{
digitd1=2;
}

digit1=digitn0;
digit0=digits0;
//digit1=digit1+1;
if(digit0>digit1)
{
digitd2=1;
}

digit1=digitn0;
digit0=digits0;
//digit0=digit0+1;
if(digit0<digit1)
{
digitd2=2;
}


}

void incriment()
{
digit10=digit10+1;
if(digit10>99)
{
digit10=3;
}
wreprom();
}
void decriment()
{
digit10=digit10-1;
if(digit10<3)
{
digit10=99;
}
wreprom();
}
void devide()
{
digit1=digit10;
     digit1=digit1/10;
     digit0=(digit10-(digit1*10));
digit11=digit0;
digit12=digit1;
}




void keysense()
{
if ( !input (inc))
{
delay3();
if ( !input (inc))
{
incriment();
devide();
}
}
if ( !input (dec))
{
delay3();
if ( !input (dec))
{
decriment();
devide();
}
}
}


void delayloop()
{
digit0=digit10;
digit0=101-digit0;
for(digit1=0;digit1<digit0;digit1++)
{
delay4();
if ( !input (inc))
{
digit1=105;
}
if ( !input (dec))
{
digit1=105;
}
}
}

void homeposition()
{
digitep=0;//
digitwp=0;//
digitsp=0;//
digitnp=0;//
adce();
adcw();

digit0=digite0;
digit1=digitw0;
if(digit0>digit1)
{
digit0=digite0;
digit1=digitw0;
digitwp=digit0-digit1;
}

digit0=digite0;
digit1=digitw0;
if(digit0<digit1)
{
digit0=digite0;
digit1=digitw0;
digitep=digit1-digit0;
}

adcs();
adcn();

digit0=digits0;
digit1=digitn0;
if(digit0>digit1)
{
digit0=digits0;
digit1=digitn0;
digitnp=digit0-digit1;
}


digit0=digits0;
digit1=digitn0;
if(digit0<digit1)
{
digit0=digits0;
digit1=digitn0;
digitsp=digit1-digit0;
}
wreprom1();

digit5lcd=3; //display welcome
line1();
digit5lcd=4; //display welcome
line2();

delaysecond();
delaysecond();
}



void main()
{

   setup_adc_ports(sAN0|sAN1|sAN2|sAN3|VSS_VDD);
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);// This device COMP currently not supported by the PICWizard
//Setup_Oscillator parameter not selected from Intr Oscillotar Config tab

   // TODO: USER CODE!!
output_low(RW);
digitep=0;//
digitwp=0;//
digitsp=0;//
digitnp=0;//
offall();
readeeprom();
devide();
startloop();
delaysecond();
delaysecond();
//homeposition();
TK1:
adcall();
datacal();
motor();
keysense();
ramline1();
line1ram();
ramline2();
line2ram();
delayloop();
if ( !input (dec))
{
if ( !input (inc))
{
homeposition();
}
delay6();
}
if ( !input (inc))
{
delay6();
}

goto TK1;

}




