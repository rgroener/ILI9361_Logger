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
	
	
	LCD_Draw_Line(100, 100, 120, 120,LCD_BLACK);

	return 0;
}
