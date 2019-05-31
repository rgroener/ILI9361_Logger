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

// variables for sensor values
int32_t temperature;
uint32_t pressure;
uint32_t humidity;
int32_t altitude;

uint16_t test=0;
uint8_t x=0;



char string[24];
uint32_t graph_raw[128];


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


int main( void )
{
	DDRB |= (1<<PB2); 	//Backlight pin
	PORTB |= (1<<PB2);	//Backlight on
	
	 /* init display, set default orientation (optional) */
	LCD_init();
	LCD_Orientation(LCD_ROT_180);
	LCD_FillScreen( LCD_RGB(255,255,255) ); /* white where R,G,B are at max. value 255 */
	
	//LCD_ShowImage( 0,0,64,64,(const unsigned char*)ili9163_image);/* ShowImage is for high/true color */
	temperature=0;
	pressure=0;
	humidity =0;
	altitude=0;
	
 for(x=0;x<128;x++)
 {
	 graph_raw[x]=40;
 }
  // init sensor
  bme280_init();
 //LCD_ShowImage(0, 0, 64, 64, ili9163_image);
  LCD_Line(0,75,128, 75,LCD_BLACK);
	while(1)
	{
		
		temperature = bme280_readTemperature(); // in °C
		pressure = bme280_readPressure()/100; // in mbar
		humidity = bme280_readHumidity(); // in %
		altitude = bme280_readAltitude(102000); // 
		
		
		
		/*
		if(graph_x==0)
		{
			skal = temperature/teiler;
		}
		
		for(x=0;x<128;x++)
		{
			graph_y=80-(temperature-(skal*teiler));
		
			LCD_Line(graph_xalt,graph_yalt,graph_x, graph_y, LCD_BLACK);
			graph_xalt=graph_x;
			graph_yalt=graph_y;
		
			graph_x++;
			
			
			
		}
		
		if(graph_x > 128)
		{
			LCD_Cleargraph();
			graph_x=0;
			graph_xalt=0;
		}
		
		*/
		itoa(humidity, string, 10);
		//LCD_Puts("Hum:",0,80,LCD_BLUE,LCD_WHITE);
		sprintf(string,"Hum : %d.%2.2d %%", vor_komma(humidity), nach_komma(humidity));
		LCD_Puts(string,3,80,LCD_BLUE,LCD_WHITE);
		
		sprintf(string,"Temp: %d.%2.2d C", vor_komma(temperature), nach_komma(temperature));
		LCD_Puts(string,3,96,LCD_MAGENTA,LCD_WHITE);
		
		sprintf(string,"Pres: %ld hPa", pressure/100);
		LCD_Puts(string,3,112,LCD_RED,LCD_WHITE);
		
		
		
		
		
		 
		 

		
		
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
