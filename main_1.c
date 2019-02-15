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
#include <avr/pgmspace.h>
#include <util/delay.h> /* might be <avr/delay.h>, depending on toolchain */
#include <stdlib.h>
#define  DFTIMG_MAIN

#include "woodstock_64x64.h"

#undef   DFTIMG_MAIN

#include "ILI9163.h"

#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "grn_TWI.h"
#include "grn_24C512.h"
#include "grn_bme280.h"
#include <stdio.h>


#define top_to_bottom  0
#define bottom_to_top  1
#define TFA  0                                        // Top Fixed Area 0 pixel
#define BFA  0 

void VerticalScroll(uint8_t _vsp) ;
void LCD_Draw_Line(int x0, int y0, int x1, int y1, color_t color);
void LCD_Draw_HLine( unsigned char x, unsigned char y, unsigned char w, color_t color);
void LCD_Draw_VLine( unsigned char x, unsigned char y, unsigned char h, color_t color);
void LCD_Draw_Fill_Circle(uint8_t x0, uint8_t y0, uint8_t r, color_t color);
void LCD_Draw_Circle(uint8_t x0, uint8_t y0, uint8_t r, color_t color);
void setScrollDefinition(uint8_t top_fix_height, uint8_t bottom_fix_height, uint8_t _scroll_direction);

uint8_t o=0;
uint8_t scroll = 0;
char string[30] = "";
uint8_t blabla;
int32_t temperatur;
uint32_t pressure, humidity;

uint8_t test;

int main( void )
{
	
	/* Backlight pin PL3, set as output, set high for 100% output */
	DDRB |= (1<<PB2);
	PORTB |= (1<<PB2);
	//PORTB &= ~(1<<PB2);
	
	
	DDRC |=(1<<PC3); 	//Ausgang LED
	PORTC |= (1<<PC3);	//Led ein
	
	
	DDRD &= ~((1<<PD6) | (1<<PD2) | (1<<PD5)); 	//Taster 1-3
	PORTD |= ((1<<PD6) | (1<<PD2) | (1<<PD5)); 	//PUllups für Taster einschalten
	
	DDRD &= ~(1<<PD4); //T0 Counter Input
	TCCR0B |= (1<<CS02) | (1<<CS01) | (1<<CS00);//Counter 0 enabled clock on rising edge
	
	//Timer 1 Configuration
	OCR1A = 0x009C;	//OCR1A = 0x3D08;==1sec
	
    TCCR1B |= (1 << WGM12);
    // Mode 4, CTC on OCR1A

    TIMSK1 |= (1 << OCIE1A);
    //Set interrupt on compare match

    TCCR1B |= (1 << CS12) | (1 << CS10);
    // set prescaler to 1024 and start the timer

    //sei();
    //enable interrupts
	

	bme280_init();
	 /* init display, set default orientation (optional) */
	LCD_init();
	o = LCD_ROT_180;
	LCD_Orientation(o);
	LCD_FillScreen( LCD_WHITE ); /* white where R,G,B are at max. value 255 */
	
	temperatur=0;
	humidity=0;
	pressure=0;
	blabla=222;
	test=0;
	LCD_Puts("RED",0,0,LCD_RED,LCD_WHITE);
	LCD_Puts("BLUE",0,20,LCD_BLUE,LCD_WHITE);
	LCD_Puts("GREEN",0,35,LCD_GREEN,LCD_WHITE);

	LCD_ShowImage( 0,55,IMG_WIDTH,IMG_HEIGHT,(const unsigned char*)IMG_PTR);/* ShowImage is for high/true color */
	/*LCD_FillRect( 33,44, 33, 1, LCD_RED );
	LCD_Draw_Fill_Circle(30, 90, 10,LCD_BLUE);
	LCD_Draw_Line(100, 100, 124, 124,LCD_BLACK);

	setScrollDefinition(TFA, BFA, 1);*/
	while(1)
	{
		
		
		//temperatur = bme280_read_temp();
		//pressure = bme280_read_pressure();
		//humidity = bme280_read_humidity();
		
		/*sprintf(string,"Temp: %0d.%0d\370C",vor_komma(temperatur), nach_komma(temperatur));
		LCD_Puts(string,0,35,LCD_BLACK,LCD_WHITE);
		sprintf(string,"A: %ld",humidity);
		LCD_Puts(string,1,40,LCD_RED,LCD_WHITE);
		sprintf(string,"P: %ld",pressure/100);
		LCD_Puts(string,4,55,LCD_BLUE,LCD_WHITE);*/
		//LCD_Puts("Green",40,10,LCD_GREEN,LCD_WHITE);
		/*VerticalScroll(scroll + TFA);
		scroll++;
		if(scroll >= (LCD_Height - TFA - BFA))
		scroll = 0;
		
	*/
	
	}
	return 0;
}



void LCD_Draw_Line(int x0, int y0, int x1, int y1, color_t color)
{
	int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
	int err = (dx-dy ? dx : -dy)/2, e2;
	for(;;)
	{
		LCD_SetPixel(x0 , y0, color );
		if(x0==x1 && y0==y1)break;
		e2= err;
		if(e2 >-dx){err-=dx; x0 +=sx;}
		if(e2 < dy){err+=dx; y0+=sy;}
		
	}
}
void LCD_Draw_HLine( unsigned char x, unsigned char y, unsigned char w, color_t color)
{
	//Draw horizontal line
	LCD_FillRect( x,y, w, 1, color );
	
}
void LCD_Draw_VLine( unsigned char x, unsigned char y, unsigned char h, color_t color)
{
	//Draw horizontal line
	LCD_FillRect( x,y, 1, h, color );
	
}
void LCD_Draw_Fill_Circle(uint8_t x0, uint8_t y0, uint8_t r, color_t color)
{
	/* source for this function is:
	 * https://github.com/andygock/glcd
	 */
	int8_t f = 1 - r;
	int8_t ddF_x = 1;
	int8_t ddF_y = -2 * r;
	int8_t x = 0;
	int8_t y = r;
	
	int16_t i;

	
	
	for (i=y0-r; i<=y0+r; i++) {
		LCD_SetPixel(x0, i, color);
	}
	
	while (x < y) {
		if (f >= 0) {
			y--;
			ddF_y += 2;
			f += ddF_y;
		}
		x++;
		ddF_x += 2;
		f += ddF_x;
		
		for (i=y0-y; i<=y0+y; i++) {
			LCD_SetPixel(x0+x, i, color);
			LCD_SetPixel(x0-x, i, color);
		} 
		for (i=y0-x; i<=y0+x; i++) {
			LCD_SetPixel(x0+y, i, color);
			LCD_SetPixel(x0-y, i, color);
		}    
	}
}
void LCD_Draw_Circle(uint8_t x0, uint8_t y0, uint8_t r, color_t color)
{
	/* source for this function is:
	 * https://github.com/andygock/glcd
	 */
	int8_t f = 1 - r;
	int8_t ddF_x = 1;
	int8_t ddF_y = -2 * r;
	int8_t x = 0;
	int8_t y = r;
	
	//glcd_update_bbox(x0-r, y0-r, x0+r, y0+r);
	
	LCD_SetPixel(x0, y0+r, color);
	LCD_SetPixel(x0, y0-r, color);
	LCD_SetPixel(x0+r, y0, color);
	LCD_SetPixel(x0-r, y0, color);
	
	while (x<y) {
		if (f >= 0) {
			y--;
			ddF_y += 2;
			f += ddF_y;
		}
		x++;
		ddF_x += 2;
		f += ddF_x;
		
		LCD_SetPixel(x0 + x, y0 + y, color);
		LCD_SetPixel(x0 - x, y0 + y, color);
		LCD_SetPixel(x0 + x, y0 - y, color);
		LCD_SetPixel(x0 - x, y0 - y, color);
		
		LCD_SetPixel(x0 + y, y0 + x, color);
		LCD_SetPixel(x0 - y, y0 + x, color);
		LCD_SetPixel(x0 + y, y0 - x, color);
		LCD_SetPixel(x0 - y, y0 - x, color);
		
	}
}

void setScrollDefinition(uint8_t top_fix_height, uint8_t bottom_fix_height, uint8_t _scroll_direction)
{
	//source of function:
	// http://ccspicc.blogspot.com/2016/11/st7735-tft-screen-vertical-scrolling.html
  uint8_t scroll_height;
  scroll_height = LCD_Height - top_fix_height - bottom_fix_height;
  LCD_CMD(0x33);//vertical scroll definition
  LCD_DTA(0x00);
  LCD_DTA(top_fix_height);
  LCD_DTA(0x00);
  LCD_DTA(scroll_height);
  LCD_DTA(0x00);
  LCD_DTA(bottom_fix_height);
  LCD_CMD(0x36);//MADCTL
  if(_scroll_direction)
  {
	  
	LCD_DTA(0xD8);
    /*if(_tft_type == 0)
    {
      
    }
    if(_tft_type == 1)
    {
      LCD_DTA(0xD0);
    }
    if(_tft_type == 2)
    {
      LCD_DTA(0x18);
    }*/
  }
  else
  {
	LCD_DTA(0xC8);
    /*if(_tft_type == 0)
    {
      
    }
    if(_tft_type == 1)
    {
      LCD_DTA(0xC0);
    }
    if(_tft_type == 2)
    {
      LCD_DTA(0x08);
    }*/
  }
}
void VerticalScroll(uint8_t _vsp) 
{
  LCD_CMD(0x37);//VSCRSADD
  LCD_DTA(0x00);
  LCD_DTA(_vsp);
}
