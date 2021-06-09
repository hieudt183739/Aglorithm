#include "reg51.h"
#include "string.h"
#define LCD_DATA P2

//Dinh nghia mot so chan de dieu khien den LCD
sbit EN = P0 ^ 2;
sbit RS = P0 ^ 0;
sbit RW = P0 ^ 1;
sbit SPK = P3 ^ 7;

//Khai bao prototype cho cac ham
void Init_System();
void Delay_ms(int interval);
void LCD_init();
void Wait_For_LCD();
void LCD_Send_Command(unsigned char x);
void LCD_Write_One_Char(unsigned char c);
void LCD_Write_String(unsigned char *s);
void music();// mo bai hat Happy birthday 
void play(char uart_data);// choi nhac
void init();
void delay(unsigned int time);

// cac bien can dung
unsigned char note_index;
char uart_data;
char flag;
code unsigned int noteTH[]={0xf8,0xf9,0xfa,0xfa,0xfb,0xfb,0xfc};// gia tri thanh ghi TH
code unsigned int noteTL[]={0x8b,0x5b,0x17,0x6b,0x07,0x92,0x0d};// gia tri thanh ghi TL
code unsigned char ten[7][10]={"do","re","mi","fa","son","la","si"};
code unsigned int hp[25]={0,0,1,0,3,2,0,0,1,0,4,3,0,0,6,5,3,2,1,6,6,5,3,4,3};// bai hat Happy birthday


void serial_IT(void) interrupt 4{
    if (RI == 1) {
        RI = 0;           /* prepare for next reception */
        uart_data = SBUF; /* Read receive data */
        flag = 1;
        SBUF = uart_data; /* Send back same data on uart*/
    }
    else {
        TI = 0; /* if emission occur */
    }
}

void timer0() interrupt 1 {
    TH0 = noteTH[note_index];
    TL0 = noteTL[note_index];
    SPK = ~SPK;
}

void music() { 
    unsigned char i;
    note_index = 0;
    for (i = 0; i < 25; i++) {
        note_index = hp[i];
        TH0 = noteTH[note_index];
        TL0 = noteTL[note_index];
        TR0 = 1;
        delay(30000);
        TR0 = 0;
        SPK = 1;
        delay(30000);
    }
    delay(50000);
    delay(50000);
}

void play(char uart_data) {
    note_index = uart_data - 49;
    TH0 = noteTH[note_index];
    TL0 = noteTL[note_index];
    TR0 = 1;
    LCD_Send_Command(0x01); //Xoa man hinh
    LCD_Write_String(ten[note_index]);
}



void main(void) {
    init();
    SCON = 0x50; 			/* uart in mode 1 (8 bit), REN=1 */
    TMOD = TMOD | 0x20 ; 	/* Timer 1 in mode 2 */
    TH1 = 0xFD; 			/* 9600 Bds at 11.0592MHz */
    TL1 = 0xFD; 			/* 9600 Bds at 11.0592MHz */
    ES = 1; 				/* Enable serial interrupt*/
    EA = 1; 				/* Enable global interrupt */
    TR1 = 1; 				/* Timer 1 run */
	

    music(); // bai hat happy birthday
    flag = 0;
    while (1) {
      if(flag == 1){ 
          flag = 0;
          play(uart_data);
          continue;
      }
      TR0 = 0;
      SPK = 1;
    }
}

void init()
{
	TMOD = 0x01;
	EA = 1;
	ET0 = 1;
	TR0 = 0;

    Init_System();
    LCD_init();
    LCD_Write_String("HAPPY");
    LCD_Send_Command(0xC0); //Chuyen con tro xuong dong thu 2
    LCD_Write_String("BIRTHDAY");
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
    RS = 1;       //Chon thanh ghi du lieu
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
        s++;                    //Tang con tro
        length--;
    }
}