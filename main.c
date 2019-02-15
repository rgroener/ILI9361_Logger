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
#include "woodstock_64x64.h"
#include "i2c.h"
#include "bme280.h"

// variables for sensor values
int32_t temperature;
uint32_t pressure;
uint32_t humidity;
int32_t altitude;

char string[24];

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
int main( void )
{
	DDRB |= (1<<PB2); 	//Backlight pin
	PORTB |= (1<<PB2);	//Backlight on
	
	 /* init display, set default orientation (optional) */
	LCD_init();

	
	LCD_Orientation(LCD_ROT_180);
	LCD_FillScreen( LCD_RGB(255,255,255) ); /* white where R,G,B are at max. value 255 */
	
	LCD_ShowImage( 0,0,64,64,(const unsigned char*)ili9163_image);/* ShowImage is for high/true color */
	
	temperature=0;
	pressure=0;
	humidity =0;
	altitude=0;
	
	
	

  
  
  // init sensor
  bme280_init();
 
  
	while(1)
	{
		temperature = bme280_readTemperature(); // in °C
		pressure = bme280_readPressure()/100; // in mbar
		humidity = bme280_readHumidity(); // in %
		altitude = bme280_readAltitude(102000); // 
		
		//itoa(humidity, string, 10);
		//LCD_Puts("Hum:",0,80,LCD_BLUE,LCD_WHITE);
		sprintf(string,"Hum: %d.%2.2d%%", vor_komma(humidity), nach_komma(humidity));
		LCD_Puts(string,0,80,LCD_BLUE,LCD_WHITE);
		
		sprintf(string,"Temp:%d.%d C", vor_komma(temperature), nach_komma(temperature));
		LCD_Puts(string,0,100,LCD_BLUE,LCD_WHITE);
		
		_delay_ms(1000);
		
	}

	return 0;
}
