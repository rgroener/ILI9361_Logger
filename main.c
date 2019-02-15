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

#include "ILI9163.h"
#include "demoloop.h"
#include "woodstock_64x64.h"

int main( void )
{
	DDRB |= (1<<PB2); 	//Backlight pin
	PORTB |= (1<<PB2);	//Backlight on
	
	 /* init display, set default orientation (optional) */
	LCD_init();

	
	LCD_Orientation(LCD_ROT_180);
	LCD_FillScreen( LCD_RGB(255,255,255) ); /* white where R,G,B are at max. value 255 */
	
	LCD_Puts("Temperature",0,80,LCD_BLACK,LCD_WHITE);
	LCD_ShowImage( 0,0,64,64,(const unsigned char*)ili9163_image);/* ShowImage is for high/true color */
	while(1);

	return 0;
}
