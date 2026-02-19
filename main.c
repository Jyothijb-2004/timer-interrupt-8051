#include<reg51.h>
sbit LED=P2^0;
void timer0_ISR (void)
Interrupt 1 {
  LED=~LED; //toggle LED
  TH0=0xFC; //reload timer
  TL0=0x66;
}
void main(){
TMOD=0x01;  //timer 0 mode 1
TH0=0xFC;
TL0=0x66;
IE=0x82;   // enable timer 0 
TR0=1;     //start timer
while(1);  //infinite loop
}
