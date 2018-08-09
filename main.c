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

#include "DFT48x39.h"

#undef   DFTIMG_MAIN

#include "ILI9163.h"

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





uint8_t o=0;

int main( void )
{
	DDRB |= (1<<PB2); 	//Backlight pin
	PORTB |= (1<<PB2);	//Backlight on
	 /* init display, set default orientation (optional) */
	LCD_init();
	o = LCD_ROT_270;
	LCD_Orientation(o);
	LCD_FillScreen( LCD_RGB(255,255,255) ); /* white where R,G,B are at max. value 255 */
	
	LCD_Puts("Red",0,10,LCD_RED,LCD_WHITE);
	LCD_Puts("Green",40,10,LCD_GREEN,LCD_WHITE);
	LCD_Puts("Blue",80,10,LCD_BLUE,LCD_WHITE);
	LCD_ShowImage( 0,30,DFTIMG_WIDTH,DFTIMG_HEIGHT,(const unsigned char*)DFTIMG_PTR);/* ShowImage is for high/true color */
	LCD_FillRect( 33,44, 33, 1, LCD_RED );
	LCD_Draw_Fill_Circle(30, 90, 10,LCD_BLUE);
	LCD_Draw_Line(100, 100, 124, 124,LCD_BLACK);

	return 0;
}
