#include "reg51.h"
#define TH0_50ms 0x3C	
#define TL0_50ms 0xB0
//led 7-seg output data 0-9 
code unsigned char LEDfont[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
unsigned char LEDpos=0;	//choose led 7-seg position		 chon led nao

unsigned char oldkey=0xff;	//push button data (release status)

//Define led 7-seg anot control (on/off):	
sbit LED7SEG_0 = P1^0;	//Led 7-seg 1 anot 
sbit LED7SEG_1 = P1^1;	//Led 7-seg 2 anot
sbit LED7SEG_2 = P1^2;	//Led 7-seg 3 anot
sbit LED7SEG_3 = P1^3;	//Led 7-seg 4 anot

//Buzzer (speaker) connects on P1^5 
sbit SPK  = P1^5;	//Buzzer on/off

//Define 6 push buttons on Port P3
sbit key1 = P3^7;	//Push button 1
sbit key2 = P3^6;	//Push button 2
sbit key3 = P3^5;	//Push button 3
sbit key4 = P3^4;	//Push button 4

// ch? dùng 2 phím này thôi
sbit key5 = P3^3;	//Push button 5
sbit key6 = P3^2;	//Push button 6

unsigned int LEDdata=0;	
			
//Delay 0-65536
void delay(unsigned int time)   
{							    
	while(time--);
}

void display(unsigned int da)
{
	P0=0xFF;			//Port 0 data off
	da=da%10000;	 	//output data for led 7-seg (4-digits)
	switch(LEDpos){
	case 0:		//choose led 7-seg 1
		LED7SEG_0=0;
		LED7SEG_1=1;	
		LED7SEG_2=1;		
		LED7SEG_3=1;
		P0=LEDfont[da/1000];	//Chu so hang nghin
		break;
	case 1:		//choose led 7-seg 2
		LED7SEG_0=1;
		LED7SEG_1=0;	
		LED7SEG_2=1;		
		LED7SEG_3=1;
		P0=LEDfont[da%1000/100]; //Chu so hang tram
		break;
	case 2:		//choose led 7-seg 3
		LED7SEG_0=1;
		LED7SEG_1=1;	
		LED7SEG_2=0;		
		LED7SEG_3=1;
		P0=LEDfont[da%100/10];  //Chu so hang chuc
		break;
	case 3:		//choose led 7-seg 4
		LED7SEG_0=1;
		LED7SEG_1=1;	
		LED7SEG_2=1;		
		LED7SEG_3=0;
		P0=LEDfont[da%10];	 //Chu so hang don vi
		break;
	}
	LEDpos++;		//turn around
	if(LEDpos>3)
		LEDpos=0;	
}
//Read buttons 1-> 6 on P3
unsigned char ReadKey(void)	
{
	unsigned char lkey=0;
	if((P3&0xfc)!=0xfc){	//if any buttons pressed

		SPK=1;				//turn on buzzer

		delay(10);			//delay for buzzer pulse
		if(oldkey!=(P3&0xfc)){//if any buttons pressed  di?u ki?n này d? tránh b?m gi? phím lâu
			oldkey=P3&0xfc;		//update buttons values		
			if(key1==0)
				lkey=1;		//press button 1
			else if(key2==0)
				lkey=2;		//press button 2
			else if(key3==0)
				lkey=3;		//press button 3
			else if(key4==0)
				lkey=4;		//press button 4
			else if(key5==0)
				lkey=5;		//press button 5
			else if(key6==0)
				lkey=6;		//press button 6
		}
	}
	else{
		oldkey=0xfc;		//default data of buttons port

		SPK=0;				//turn off buzzer
	}
	return lkey;
}

void TMR0_Process() interrupt 1{
	TF0  = 0; 			//clear flag
	TR0  = 0; 			//stop timer
	TH0  = 0xD8;	//reset T0 value
	TL0  = 0xEF;	//

	LEDdata++;
	display(LEDdata);
	
	TR0  = 1; 			//restart timer
}

//EXT 0 interrupt handler
void EXT0_Process0() interrupt 0{
	EA=0;	//Cam ngat
	TR0  = 0;	
	EA=1;	//Cho phep ngat
}

void EXT0_Process1() interrupt 2{
	EA=0;	//Cam ngat
	TR0  = 1;	
	EA=1;	//Cho phep ngat
}

void init(){
	LEDdata=0;
	key5 = 1;
	key6 = 1; 		//Thiet lap chan P3_2 lam chan vao
	//ext int 0
	EX0  = 1; 		//Cho phep ngat ngoai 0
	IT0  = 1;		//Ngat theo suon
	EX1  = 1; 		//Cho phep ngat ngoai 0
	IT1  = 1;	
	//timer 0
	TMOD = TMOD & 0xF0;	
	TMOD = TMOD | 0x01;
    TL0  = 0xEF;		
	TH0  = 0XD8; 
	TF0  = 0; 			//Xoa co tran timer 0
	TR0  = 1; 			//Khoi dong timer 0
	ET0  = 1;			//cho phep ngat
	EA   = 1;			//global interrupt enable
}

//Chuong trinh chinh				
void main(void) 
{
	//led-7seg 4 digits data 
	unsigned char i;
	SPK = 0;
	for(i=0;i<8;i++){
		P2<<=1;		//shift left all leds		
		delay(5000);
	}

	P1 = 0x0f;
	P2 = 0xff;		//all LED off
	
	P0 = 0;			//Port 0 connect LCD
	LED7SEG_3=0;		//turn on leg 7-seg 4
	delay(50000);
	LED7SEG_3=1;		//turn off leg 7-seg 4

	LED7SEG_2=0;		//turn on leg 7-seg 3
	delay(50000);
	LED7SEG_2=1;		//turn off leg 7-seg 3

	LED7SEG_1=0;		//turn on leg 7-seg 2
	delay(50000);
	LED7SEG_1=1;		//turn off leg 7-seg 2

	LED7SEG_0=0;		//turn on leg 7-seg 1
	delay(50000);
	LED7SEG_0=1;		////turn off leg 7-seg 1
	
	init();
	while(1){					//loop forever
		P2 = 0x55;				//8 leds on Port 2
	} 
}
