#include "reg51.h"
#include "string.h"
//Dinh nghia mot so chan de dieu khien den LCD
#define LCD_DATA P2
sbit EN = P0 ^ 2;
sbit RS = P0 ^ 0;
sbit RW = P0 ^ 1;
//Khai bao prototype cho cac ham
void Init_System();
void Delay_ms(int interval);
void LCD_init();
void Wait_For_LCD();
void LCD_Send_Command(unsigned char x);
void LCD_Write_One_Char(unsigned char c);
void LCD_Write_String(unsigned char *s);

sbit SPK = P3 ^ 7;

//verify this table according to your CPU clock
code unsigned int note_table[] = {
	0xf8, 0x8b, //1 do
	0xf9, 0x5b, //2 re
	0xfa, 0x17, //3 mi
	0xfa, 0x6b, //4 fa
	0xfb, 0x07, //5 sol
	0xfb, 0x92, //6 la
	0xfc, 0x0d, //7 si
};

code unsigned int song2[] = {
	0xf8, 0x8b, //1 do
	0xf8, 0x8b, //1 do
	0xf9, 0x5b, //2 re
	0xf8, 0x8b, //1 do
	0xfa, 0x6b, //4 fa
	0xfa, 0x17, //3 mi
	0xf8, 0x8b, //1 do
	0xf8, 0x8b, //1 do
	0xf9, 0x5b, //2 re
	0xf8, 0x8b, //1 do
	0xfb, 0x07, //5 sol
	0xfa, 0x6b, //4 fa
	0xf8, 0x8b, //1 do
	0xf8, 0x8b, //1 do
	0xfc, 0x0d, //7 si
	0xfb, 0x92, //6 la
	0xfa, 0x6b, //4 fa
	0xfa, 0x17, //3 mi
	0xf9, 0x5b, //2 re
	0xfc, 0x0d, //7 si
	0xfc, 0x0d, //7 si
	0xfb, 0x92, //6 la
	0xfa, 0x6b, //4 fa
	0xfb, 0x07, //5 sol
	0xfa, 0x6b, //4 fa

};

unsigned char note_index;

void init();
void delay(unsigned int time);

char uart_data;
void serial_IT(void) interrupt 4
{
	if (RI == 1)
	{
		RI = 0;			  /* prepare for next reception */
		uart_data = SBUF; /* Read receive data */
		SBUF = uart_data; /* Send back same data on uart*/
	}
	else
		TI = 0; /* if emission occur */
}

void music()
{
	unsigned char i;
	note_index = 0;
	for (i = 0; i < 25; i++)
	{
		TH0 = song2[note_index];
		TL0 = song2[note_index + 1];
		TR0 = 1;
		delay(40000);
		TR0 = 0;
		SPK = 1;
		delay(40000);
		note_index += 2;
	}
	delay(50000);
	delay(50000);
}

void main(void)
{
	unsigned char i;
	init();

	Init_System();
	LCD_init(); // reset man hinh LCD
	LCD_Write_String("HHD GROUP");
	LCD_Send_Command(0xC0); //Chuyen con tro xuong dong thu 2
	LCD_Write_String("************");

	//music(); // phat nhac happy birthday

	while (1)
	{
		note_index = 0;
		
		switch (uart_data)
		{
		case 0:
		// neu ko bam nut thi tat loa
			SPK = 1;
			LCD_init();
			TR0 = 0;
			break;

		case 'c':
			// not Do
			note_index = 0;
			TH0 = note_table[note_index];
			TL0 = note_table[note_index + 1];
			TR0 = 1;
			Delay_ms(5000);
			//LCD_Send_Command(0xC0); //Chuyen con tro xuong dong thu 2
			LCD_Write_String("do"); // hien thi tren LCD
			uart_data = 0;
			break;

		case 'd':
			// not Re
			note_index = 2;
			TH0 = note_table[note_index];
			TL0 = note_table[note_index + 1];
			TR0 = 1;
			//LCD_Send_Command(0xC0); //Chuyen con tro xuong dong thu 2
			LCD_Write_String("re");
			uart_data = 0;
			break;

		case 'e':
			// not Mi
			note_index = 4;
			TH0 = note_table[note_index];
			TL0 = note_table[note_index + 1];
			TR0 = 1;
			//LCD_Send_Command(0xC0); //Chuyen con tro xuong dong thu 2
			LCD_Write_String("mi");
			uart_data = 0;
			break;

		case 'f':
			// Not fa
			note_index = 6;
			TH0 = note_table[note_index];
			TL0 = note_table[note_index + 1];
			TR0 = 1;
			//LCD_Send_Command(0xC0); //Chuyen con tro xuong dong thu 2
			LCD_Write_String("fa");
			uart_data = 0;
			break;

		case 'g':
			// not Son
			note_index = 8;
			TH0 = note_table[note_index];
			TL0 = note_table[note_index + 1];
			TR0 = 1;
			//LCD_Send_Command(0xC0); //Chuyen con tro xuong dong thu 2
			LCD_Write_String("sol");
			uart_data = 0;
			break;

		case 'a':
			// not La
			note_index = 10;
			TH0 = note_table[note_index];
			TL0 = note_table[note_index + 1];
			TR0 = 1;
			//LCD_Send_Command(0xC0); //Chuyen con tro xuong dong thu 2
			LCD_Write_String("la");
			uart_data = 0;
			break;

		case 'b':
			//not Si
			note_index = 12;
			TH0 = note_table[note_index];
			TL0 = note_table[note_index + 1];
			TR0 = 1;
			//LCD_Send_Command(0xC0); //Chuyen con tro xuong dong thu 2
			LCD_Write_String("la");
			uart_data = 0;
			break;

		default:
			LCD_init();
			break;
		}

		//delay(50000);
	}
}

void init()
{ // khoi dong Timer 1

	SCON = 0x50;		/* uart in mode 1 (8 bit), REN=1 */
	TMOD = TMOD | 0x20; /* Timer 1 in mode 2 */
	TH1 = 0xFD;			/* 9600 Bds at 11.0592MHz */
	TL1 = 0xFD;			/* 9600 Bds at 11.0592MHz */
	ES = 1;				/* Enable serial interrupt*/
	EA = 1;				/* Enable global interrupt */
	TR1 = 1;			/* Timer 1 run */

	TMOD = 0x01;
	EA = 1;
	ET0 = 1;
	TR0 = 0;
}

void timer0() interrupt 1
{
	TH0 = song2[note_index];
	TL0 = song2[note_index + 1];

	SPK = ~SPK;
}

void delay(unsigned int time)
{
	while (time--)
		;
}

void Init_System()
{
	//Thiet lap LCD o che do doc
	RW = 1;
}
void Delay_ms(int interval)
{
	int i, j;
	for (i = 0; i < 1000; i++)
	{
		for (j = 0; j < interval; j++)
			;
	}
}
//Ham thuc hien gui mot lenh xuong LCD
void LCD_Send_Command(unsigned char x)
{
	LCD_DATA = x;
	RS = 0; //Chon thanh ghi lenh
	RW = 0; //De ghi du lieu
	EN = 1;
	Delay_ms(1);
	EN = 0;
	Wait_For_LCD(); //Doi cho LCD san sang
	EN = 1;
}
//Ham kiem tra va cho den khi LCD san sang
void Wait_For_LCD()
{
	Delay_ms(1);
}
void LCD_init()
{
	LCD_Send_Command(0x38); //Chon che do 8 bit, 2 hang cho LCD
	LCD_Send_Command(0x0E); //Bat hien thi, nhap nhay con tro
	LCD_Send_Command(0x01); //Xoa man hinh
	LCD_Send_Command(0x80); //Ve dau dong
}
//Ham de LCD hien thi mot ky tu
void LCD_Write_One_Char(unsigned char c)
{
	LCD_DATA = c; //Dua du lieu vao thanh ghi
	RS = 1;		  //Chon thanh ghi du lieu
	RW = 0;
	EN = 1;
	Delay_ms(1);
	EN = 0;
	Wait_For_LCD();
	EN = 1;
}
//Ham de LCD hien thi mot xau
void LCD_Write_String(unsigned char *s)
{
	unsigned char length;
	length = strlen(s); //Lay do dai xau
	while (length != 0)
	{
		LCD_Write_One_Char(*s); //Ghi ra LCD gia tri duoc tro boi con tro
		s++;					//Tang con tro
		length--;
	}
}