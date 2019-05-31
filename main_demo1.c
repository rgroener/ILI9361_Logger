  /*
 ********************************************************************************
 * main.c                                                                       *
 *                                                                              *
 * Author: Henryk Richter <bax@comlab.uni-rostock.de>                           *
 *                                                                              *
 * Purpose: ILI9163/ST7735 display control demo                                 *
 *                                                                              *
 * default:                                                                     *
 * control: scripted                                                            *
 *                                                                              *
 ********************************************************************************
*/
#define F_CPU 16000000
#include <avr/pgmspace.h>
#include <util/delay.h> /* might be <avr/delay.h>, depending on toolchain */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include "ILI9163.h"
#include "demoloop.h"
//#include "woodstock_64x64.h"
#include "Luffy64x64.h"
#include "i2c.h"
#include "bme280.h"
#include <avr/interrupt.h>




#define T_RECHTS !(PIND & (1<<PD5)) && (entprell == 0)
#define T_LINKS !(PIND & (1<<PD6)) && (entprell == 0)
#define T_MITTE !(PIND & (1<<PD2)) && (entprell == 0)

#define LED_EIN PORTC |= (1<<PC3)
#define LED_AUS PORTC &= ~(1<<PC3)

#define RELOAD_ENTPRELL 18
#define NEIN 0
#define JA 1

// variables for sensor values
int32_t temperature;
uint32_t pressure;
uint32_t humidity;
int32_t altitude;

uint16_t test=0;
uint8_t x=0;
uint8_t refresh=0;
uint8_t menupos=0;

uint8_t sound,messspannung,last,strommax,schwellespannung;

uint8_t ms, ms10,ms100,sec,min,entprell, state;
enum state{START,MENU,MESSUNG};


char string[24];
uint32_t graph_raw[128];
uint8_t entprell=RELOAD_ENTPRELL;

uint16_t vor_komma(uint32_t value);
uint8_t nach_komma(uint32_t value);

void LCD_Line(int x0, int y0, int x1, int y1, int color)
{
	int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
	
	int err = (dx>dy ? dx : -dy) /2, e2;
	for(;;)
	{
		LCD_SetPixel(x0, y0, color);
		if(x0==x1 && y0==y1)break;
		e2 = err;
		if(e2 >-dx) {err -= dy; x0 += sx;}
		if(e2 < dy) {err += dx; y0 += sy;}
	}
}

void LCD_Cleargraph(void)
{
	LCD_FillRect( 0, 0, 128, 74, LCD_WHITE );
	
}

void graph(int32_t *graph_raw)
{
	uint8_t pos=0;//aktuelle Array Position
	uint8_t y=0;//Wert an aktueller Array Position
	uint8_t pos_alt=0;//vorherige Array Position
	uint8_t y_alt=0;//Wert an vorheriger Array Position
	uint8_t skal=100;//Skalierung
	
	
	
	
	for(pos=0;pos<128;pos++)
	{
		if(graph_raw[pos] != 9999)
		{
			y=graph_raw[pos];
		}else 	if(pos==0)
				{
					y=graph_raw[0];
					pos_alt=pos;
					y_alt=graph_raw[0];
				}else y_alt=graph_raw[pos-1];
		
	
		LCD_Line(pos_alt,y_alt,pos, y, LCD_BLACK);
		pos_alt=pos;
		
	}

	
	
}

ISR (TIMER1_COMPA_vect)
{
	ms10++;
	if(entprell != 0)entprell--;
	if(ms10==10)	//10ms
	{
		ms10=0;
		ms100++;
	}
    if(ms100==10)	//100ms
	{
		ms100=0;
		sec++;
	}
	if(sec==60)	//Minute
	{
		sec=0;
		min++;
	}
}
int main( void )
{
	DDRB |= (1<<PB2); 	//Backlight pin
	PORTB |= (1<<PB2);	//Backlight on
	
	DDRD &= ~((1<<PD2)|(1<<PD5)|(1<<PD6)); //set Taster as Input
	PORTD |= ((1<<PD2)|(1<<PD5)|(1<<PD6)); //set Pull Ups
	
	DDRC |= (1<<PC3);//SMD LED
	LED_AUS;
	
	//Timer 1 Configuration
	OCR1A = 0x009C;	//OCR1A = 0x3D08;==1sec
	
    TCCR1B |= (1 << WGM12);
    // Mode 4, CTC on OCR1A

    TIMSK1 |= (1 << OCIE1A);
    //Set interrupt on compare match

    TCCR1B |= (1 << CS12) | (1 << CS10);
    // set prescaler to 1024 and start the timer
    
    sei();
	
	 /* init display, set default orientation (optional) */
	LCD_init();
	LCD_Orientation(LCD_ROT_180);
	LCD_FillScreen( LCD_RGB(255,255,255) ); /* white where R,G,B are at max. value 255 */
	
	//LCD_ShowImage( 0,0,64,64,(const unsigned char*)ili9163_image);/* ShowImage is for high/true color */
	temperature=0;
	pressure=0;
	humidity =0;
	altitude=0;
	
	messspannung=10;
	strommax=20;
	schwellespannung=5;
	sound=JA;
	last=NEIN;
	
 state=START;
  // init sensor
  bme280_init();
 //LCD_ShowImage(0, 0, 64, 64, ili9163_image);
 //LCD_Line(0,75,128, 75,LCD_BLACK);
 
 LCD_Puts("START",1,0,LCD_BLACK,LCD_WHITE);
 LCD_Puts("TEST     MENU",3,140,LCD_BLACK,LCD_WHITE);
	while(1)
	{
		
		switch(state)
		{
			case START:	if(T_LINKS)
						{
							entprell=RELOAD_ENTPRELL;
							state=MESSUNG;
							LCD_FillScreen( LCD_RGB(255,255,255) ); /* white where R,G,B are at max. value 255 */
							LCD_Puts("MESSUNG",1,0,LCD_BLACK,LCD_WHITE);
						}
						if(T_RECHTS)
						{
							entprell=RELOAD_ENTPRELL;
							menupos=0;
							state=MENU;
							LCD_FillScreen( LCD_RGB(255,255,255) ); /* white where R,G,B are at max. value 255 */
							LCD_Puts("Konfig 1",1,0,LCD_BLACK,LCD_WHITE);
							
							
							LCD_Puts("Volt",3,40,LCD_RED,LCD_WHITE);
							sprintf(string,"%2.2d", messspannung);
							LCD_Puts(string,80,40,LCD_RED,LCD_WHITE);
							LCD_Puts("V",105,40,LCD_RED,LCD_WHITE);
							
							LCD_Puts("Krit",3,60,LCD_BLACK,LCD_WHITE);
							sprintf(string,"%2.2d", schwellespannung);
							LCD_Puts(string,80,60,LCD_BLACK,LCD_WHITE);
							LCD_Puts("V",105,60,LCD_BLACK,LCD_WHITE);
							
							LCD_Puts("Strom",3,80,LCD_BLACK,LCD_WHITE);
							sprintf(string,"%2.2d", strommax);
							LCD_Puts(string,80,80,LCD_BLACK,LCD_WHITE);
							LCD_Puts("mA",105,80,LCD_BLACK,LCD_WHITE);
							
							LCD_Puts("Last",3,100,LCD_BLACK,LCD_WHITE);
							if(last==JA)
							{
								LCD_Puts("JA",80,100,LCD_BLACK,LCD_WHITE);
							}else LCD_Puts("NEIN",80,100,LCD_BLACK,LCD_WHITE);
							
							
							LCD_Puts("Sound",3,120,LCD_BLACK,LCD_WHITE);
							if(sound==JA)
							{
								LCD_Puts("JA",80,120,LCD_BLACK,LCD_WHITE);
							}else LCD_Puts("NEIN",80,120,LCD_BLACK,LCD_WHITE);
						}
					break;
			case MENU:	switch(menupos)
						{
							case 0:	if(T_MITTE)//Messspannung verstellen
									{
										entprell=RELOAD_ENTPRELL;
										menupos=1;
										//LCD_FillScreen( LCD_RGB(255,255,255) ); /* white where R,G,B are at max. value 255 */
										
										LCD_Puts("Konfig 1",1,0,LCD_BLACK,LCD_WHITE);
							
							
										LCD_Puts("Volt",3,40,LCD_BLACK,LCD_WHITE);
										sprintf(string,"%2.2d", messspannung);
										LCD_Puts(string,80,40,LCD_BLACK,LCD_WHITE);
										LCD_Puts("V",105,40,LCD_BLACK,LCD_WHITE);
										
										LCD_Puts("Krit",3,60,LCD_RED,LCD_WHITE);
										sprintf(string,"%2.2d", schwellespannung);
										LCD_Puts(string,80,60,LCD_RED,LCD_WHITE);
										LCD_Puts("V",105,60,LCD_RED,LCD_WHITE);
										
										LCD_Puts("Strom",3,80,LCD_BLACK,LCD_WHITE);
										sprintf(string,"%2.2d", strommax);
										LCD_Puts(string,80,80,LCD_BLACK,LCD_WHITE);
										LCD_Puts("mA",105,80,LCD_BLACK,LCD_WHITE);
										
										LCD_Puts("Last",3,100,LCD_BLACK,LCD_WHITE);
										if(last==JA)
										{
											LCD_Puts("JA",80,100,LCD_BLACK,LCD_WHITE);
										}else LCD_Puts("NEIN",80,100,LCD_BLACK,LCD_WHITE);
										
										
										LCD_Puts("Sound",3,120,LCD_BLACK,LCD_WHITE);
										if(sound==JA)
										{
											LCD_Puts("JA",80,120,LCD_BLACK,LCD_WHITE);
										}else LCD_Puts("NEIN",80,120,LCD_BLACK,LCD_WHITE);
										
									}
									if(T_RECHTS)
									{
										entprell=RELOAD_ENTPRELL;
										messspannung++;
										LCD_Puts("Volt",3,40,LCD_RED,LCD_WHITE);
										sprintf(string,"%2.2d", messspannung);
										LCD_Puts(string,80,40,LCD_RED,LCD_WHITE);
										LCD_Puts("V",105,40,LCD_RED,LCD_WHITE);
									}
									if(T_LINKS)
									{
										entprell=RELOAD_ENTPRELL;
										messspannung--;
										LCD_Puts("Volt",3,40,LCD_RED,LCD_WHITE);
										sprintf(string,"%2.2d", messspannung);
										LCD_Puts(string,80,40,LCD_RED,LCD_WHITE);
										LCD_Puts("V",105,40,LCD_RED,LCD_WHITE);									
									}
									break;
							
							case 1:	if(T_MITTE)//Kriterium Schwellenspannung verstellen
									{
										entprell=RELOAD_ENTPRELL;
										menupos=2;
										//LCD_FillScreen( LCD_RGB(255,255,255) ); /* white where R,G,B are at max. value 255 */
										
										LCD_Puts("Konfig 1",1,0,LCD_BLACK,LCD_WHITE);
							
							
										LCD_Puts("Volt",3,40,LCD_BLACK,LCD_WHITE);
										sprintf(string,"%2.2d", messspannung);
										LCD_Puts(string,80,40,LCD_BLACK,LCD_WHITE);
										LCD_Puts("V",105,40,LCD_BLACK,LCD_WHITE);
										
										LCD_Puts("Krit",3,60,LCD_BLACK,LCD_WHITE);
										sprintf(string,"%2.2d", schwellespannung);
										LCD_Puts(string,80,60,LCD_BLACK,LCD_WHITE);
										LCD_Puts("V",105,60,LCD_BLACK,LCD_WHITE);
										
										LCD_Puts("Strom",3,80,LCD_RED,LCD_WHITE);
										sprintf(string,"%2.2d", strommax);
										LCD_Puts(string,80,80,LCD_RED,LCD_WHITE);
										LCD_Puts("mA",105,80,LCD_RED,LCD_WHITE);
										
										LCD_Puts("Last",3,100,LCD_BLACK,LCD_WHITE);
										if(last==JA)
										{
											LCD_Puts("JA",80,100,LCD_BLACK,LCD_WHITE);
										}else LCD_Puts("NEIN",80,100,LCD_BLACK,LCD_WHITE);
										
										
										LCD_Puts("Sound",3,120,LCD_BLACK,LCD_WHITE);
										if(sound==JA)
										{
											LCD_Puts("JA",80,120,LCD_BLACK,LCD_WHITE);
										}else LCD_Puts("NEIN",80,120,LCD_BLACK,LCD_WHITE);
										
									}
									if(T_RECHTS)
									{
										entprell=RELOAD_ENTPRELL;
										schwellespannung++;
											LCD_Puts("Krit",3,60,LCD_RED,LCD_WHITE);
										sprintf(string,"%2.2d", schwellespannung);
										LCD_Puts(string,80,60,LCD_RED,LCD_WHITE);
										LCD_Puts("V",105,60,LCD_RED,LCD_WHITE);
									}
									if(T_LINKS)
									{
										entprell=RELOAD_ENTPRELL;
										schwellespannung--;
										LCD_Puts("Krit",3,60,LCD_RED,LCD_WHITE);
										sprintf(string,"%2.2d", schwellespannung);
										LCD_Puts(string,80,60,LCD_RED,LCD_WHITE);
										LCD_Puts("V",105,60,LCD_RED,LCD_WHITE);
									}
									break;
									
							case 2:	if(T_MITTE)//Strom verstellen
									{
										entprell=RELOAD_ENTPRELL;
										menupos=3;
										//LCD_FillScreen( LCD_RGB(255,255,255) ); /* white where R,G,B are at max. value 255 */
										
										LCD_Puts("Konfig 1",1,0,LCD_BLACK,LCD_WHITE);
							
							
										LCD_Puts("Volt",3,40,LCD_BLACK,LCD_WHITE);
										sprintf(string,"%2.2d", messspannung);
										LCD_Puts(string,80,40,LCD_BLACK,LCD_WHITE);
										LCD_Puts("V",105,40,LCD_BLACK,LCD_WHITE);
										
										LCD_Puts("Krit",3,60,LCD_BLACK,LCD_WHITE);
										sprintf(string,"%2.2d", schwellespannung);
										LCD_Puts(string,80,60,LCD_BLACK,LCD_WHITE);
										LCD_Puts("V",105,60,LCD_BLACK,LCD_WHITE);
										
										LCD_Puts("Strom",3,80,LCD_BLACK,LCD_WHITE);
										sprintf(string,"%2.2d", strommax);
										LCD_Puts(string,80,80,LCD_BLACK,LCD_WHITE);
										LCD_Puts("mA",105,80,LCD_BLACK,LCD_WHITE);
										
										LCD_Puts("Last",3,100,LCD_RED,LCD_WHITE);
										if(last==JA)
										{
											LCD_Puts("JA",80,100,LCD_RED,LCD_WHITE);
										}else LCD_Puts("NEIN",80,100,LCD_RED,LCD_WHITE);
										
										
										LCD_Puts("Sound",3,120,LCD_BLACK,LCD_WHITE);
										if(sound==JA)
										{
											LCD_Puts("JA",80,120,LCD_BLACK,LCD_WHITE);
										}else LCD_Puts("NEIN",80,120,LCD_BLACK,LCD_WHITE);
									}
									if(T_RECHTS)
									{
										entprell=RELOAD_ENTPRELL;
										strommax++;
										LCD_Puts("Strom",3,80,LCD_RED,LCD_WHITE);
										sprintf(string,"%2.2d", strommax);
										LCD_Puts(string,80,80,LCD_RED,LCD_WHITE);
										LCD_Puts("mA",105,80,LCD_RED,LCD_WHITE);
									}
									if(T_LINKS)
									{
										entprell=RELOAD_ENTPRELL;
										strommax--;
										LCD_Puts("Strom",3,80,LCD_RED,LCD_WHITE);
										sprintf(string,"%2.2d", strommax);
										LCD_Puts(string,80,80,LCD_RED,LCD_WHITE);
										LCD_Puts("mA",105,80,LCD_RED,LCD_WHITE);									
									}
									break;
							
							case 3:	if(T_MITTE)//Last verstellen
									{
										entprell=RELOAD_ENTPRELL;
										menupos=4;
										//LCD_FillScreen( LCD_RGB(255,255,255) ); /* white where R,G,B are at max. value 255 */
										
										LCD_Puts("Konfig 1",1,0,LCD_BLACK,LCD_WHITE);
							
							
										LCD_Puts("Volt",3,40,LCD_BLACK,LCD_WHITE);
										sprintf(string,"%2.2d", messspannung);
										LCD_Puts(string,80,40,LCD_BLACK,LCD_WHITE);
										LCD_Puts("V",105,40,LCD_BLACK,LCD_WHITE);
										
										LCD_Puts("Krit",3,60,LCD_BLACK,LCD_WHITE);
										sprintf(string,"%2.2d", schwellespannung);
										LCD_Puts(string,80,60,LCD_BLACK,LCD_WHITE);
										LCD_Puts("V",105,60,LCD_BLACK,LCD_WHITE);
										
										LCD_Puts("Strom",3,80,LCD_BLACK,LCD_WHITE);
										sprintf(string,"%2.2d", strommax);
										LCD_Puts(string,80,80,LCD_BLACK,LCD_WHITE);
										LCD_Puts("mA",105,80,LCD_BLACK,LCD_WHITE);
										
										LCD_Puts("Last",3,100,LCD_BLACK,LCD_WHITE);
										if(last==JA)
										{
											LCD_Puts("JA",80,100,LCD_BLACK,LCD_WHITE);
										}else LCD_Puts("NEIN",80,100,LCD_BLACK,LCD_WHITE);
										
										
										LCD_Puts("Sound",3,120,LCD_RED,LCD_WHITE);
										if(sound==JA)
										{
											LCD_Puts("JA",80,120,LCD_RED,LCD_WHITE);
										}else LCD_Puts("NEIN",80,120,LCD_RED,LCD_WHITE);
										
									}
									if((T_RECHTS)|(T_LINKS))
									{
										entprell=RELOAD_ENTPRELL;
										
										LCD_Puts("Last            ",3,100,LCD_RED,LCD_WHITE);
										if(last==1)
										{
											last=0;
											LCD_Puts("NEIN",80,100,LCD_RED,LCD_WHITE);
										}else 
										{
											last=1;
											LCD_Puts("JA",80,100,LCD_RED,LCD_WHITE);
										}
									}break;
							case 4:	if(T_MITTE)//Sound verstellen
									{
										entprell=RELOAD_ENTPRELL;
										menupos=5;
										LCD_FillScreen( LCD_RGB(255,255,255) ); /* white where R,G,B are at max. value 255 */
										LCD_Puts("Config saved",10,80,LCD_RED,LCD_WHITE);
									
									}
									if((T_RECHTS)|(T_LINKS))
									{
										entprell=RELOAD_ENTPRELL;
										LCD_Puts("Sound          ",3,120,LCD_RED,LCD_WHITE);
										if(sound==1)
										{
											sound=0;
											LCD_Puts("NEIN",80,120,LCD_RED,LCD_WHITE);
										}else 
										{
											sound=1;
											LCD_Puts("JA",80,120,LCD_RED,LCD_WHITE);
										}
									}
									
									break;
							case 5:if((T_RECHTS)|(T_LINKS)|(T_MITTE))
									{
										entprell=RELOAD_ENTPRELL;
										state=START;
										LCD_FillScreen( LCD_RGB(255,255,255) ); /* white where R,G,B are at max. value 255 */
										LCD_Puts("START",1,0,LCD_BLACK,LCD_WHITE);
										LCD_Puts("TEST     MENU",3,140,LCD_BLACK,LCD_WHITE);
									}
									break;
						}//eof switch(menupos)
						break;
			
			
						
			case MESSUNG:	if(T_LINKS)
							{
								entprell=0;
								LCD_Puts("Test schlecht",6,130,LCD_BLACK,LCD_WHITE);
								LCD_FillRect( 20, 20, 88, 100, LCD_RED );
								
								refresh=1;
								
							}else 	if(T_MITTE)
									{
										entprell=RELOAD_ENTPRELL;
										state=START;
										LCD_FillScreen( LCD_RGB(255,255,255) ); /* white where R,G,B are at max. value 255 */
										 LCD_Puts("START",1,0,LCD_BLACK,LCD_WHITE);	
										 LCD_Puts("TEST     MENU",3,140,LCD_BLACK,LCD_WHITE);							
									}else 	if(T_RECHTS)
											{
												entprell=0;
												
												LCD_Puts("Test gut",30,130,LCD_BLACK,LCD_WHITE);
												LCD_FillRect( 20, 20, 88, 100, LCD_GREEN );
												
												refresh=1;
											}else 	if(refresh==1)
													{
														refresh=0;
														LCD_FillRect( 20, 20, 88, 100, LCD_WHITE );
														LCD_Puts("                 ",1,130,LCD_BLACK,LCD_WHITE);
													}	
											break;
			
		}
	
	
		
		
		
		
		
		
		
		 
		 

		
		
	}

	return 0;
}



uint16_t vor_komma(uint32_t value)
{
	return value/100;
	
}
uint8_t nach_komma(uint32_t value)
{
	uint8_t temp;
	temp = value/100;
	return value-(temp*100);
	
	
}
