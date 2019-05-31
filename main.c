/*
 ********************************************************************************
 * main.c                                                                       *
 *                                                                              *
 * Testprogram Nokia Sensorboard LW RUAG                                        *
 * Color TFT Display                                                            *
 * BME280 Sensor                                                                *
 * SD Card Functionality                                                        *
 ********************************************************************************
*/

#include <avr/pgmspace.h>
#include <util/delay.h> /* might be <avr/delay.h>, depending on toolchain */
#include <stdlib.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <inttypes.h>
#include "ILI9163.h"
#include "i2c.h"
#include "bme280.h"
/*
 * SD Card Reader
 * */
 
#include <string.h>
#include "fat.h"
#include "fat_config.h"
#include "partition.h"
#include "sd_raw.h"
#include "sd_raw_config.h"
#include "uart.h"

#define T_YELLOW !(PIND & (1<<PD5)) && (entprell == 0)
#define T_BLUE !(PIND & (1<<PD6)) && (entprell == 0)
#define T_GREEN !(PIND & (1<<PD2)) && (entprell == 0)
#define RELOAD_ENTPRELL 80

// variables for sensor values
int32_t temperature;
uint32_t pressure;
uint32_t humidity;
int32_t altitude;

uint8_t flag_backlight;


uint8_t logging =0;//flag log on =1 0=off
uint16_t logtimer=0;
uint16_t logcounter=0;
char string[24];
uint32_t graph_raw[128];
char sd_string[40] = "";
uint8_t ms,ms10,ms100,sec,min,hour, entprell;  //timer variables


// additional functions below main.c
uint16_t vor_komma(uint32_t value);
uint8_t nach_komma(uint32_t value);
uint32_t strtolong(const char* str);
uint8_t find_file_in_dir(struct fat_fs_struct* fs, struct fat_dir_struct* dd, const char* name, struct fat_dir_entry_struct* dir_entry);
struct fat_file_struct* open_file_in_dir(struct fat_fs_struct* fs, struct fat_dir_struct* dd, const char* name);
uint8_t print_disk_info(const struct fat_fs_struct* fs);
void get_datetime(uint16_t* year, uint8_t* month, uint8_t* day, uint8_t* hour, uint8_t* min, uint8_t* sec);
void sd_card(const char * sddata, uint8_t close);


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
		logtimer=1;//write values to sd card
	}
}


int main( void )
{
	DDRB |= (1<<PB2); 	//Backlight pin
	PORTB |= (1<<PB2);	//Backlight on
	DDRD &= ~((1<<PD6) | (1<<PD2) | (1<<PD5)); 	//Taster 1-3
	PORTD |= ((1<<PD6) | (1<<PD2) | (1<<PD5)); 	//PUllups für Taster einschalten
	
	
		//Timer 1 Configuration
	OCR1A = 0x009C;	//OCR1A = 0x3D08;==1sec
	
    TCCR1B |= (1 << WGM12);
    // Mode 4, CTC on OCR1A

    TIMSK1 |= (1 << OCIE1A);
    //Set interrupt on compare match

    TCCR1B |= (1 << CS12) | (1 << CS10);
    // set prescaler to 1024 and start the timer
	
	 /* init display, set default orientation (optional) */
	LCD_init();
	LCD_Orientation(LCD_ROT_180);
	LCD_FillScreen( LCD_RGB(255,255,255) ); /* white where R,G,B are at max. value 255 */
	
	//LCD_ShowImage( 0,0,64,64,(const unsigned char*)ili9163_image);/* ShowImage is for high/true color */
	temperature=0;
	pressure=0;
	humidity =0;
	altitude=0;
	flag_backlight=1;

	// init sensor
	bme280_init();
	// setup uart 
	uart_init();
	sei();//enable global interrupts

  
	while(1)
	{
		
		
		temperature = bme280_readTemperature(); // in °C
		pressure = bme280_readPressure()/100; // in mbar
		humidity = bme280_readHumidity(); // in %
		altitude = bme280_readAltitude(102000); // 
		
		
			if((logging==1)&&(logtimer==1))
			{
				logtimer=0;
				sprintf(sd_string,"%d.%2.2d", vor_komma(temperature), nach_komma(temperature));
				uart_puts((const char*)sd_string);
				sd_card((const char *)sd_string,0);//open / write to sd-card
			
				sprintf(sd_string,"\t%d.%2.2d", vor_komma(humidity), nach_komma(humidity));
				uart_puts((const char*)sd_string);
				sd_card((const char *)sd_string,0);//open / write to sd-card
				
				sprintf(sd_string,"\t%d.%2.2d\n", vor_komma(pressure), nach_komma(pressure));
				uart_puts((const char*)sd_string);
				sd_card((const char *)sd_string,0);//open / write to sd-card
			
			}
		
		itoa(humidity, string, 10);
		//LCD_Puts("Hum:",0,80,LCD_BLUE,LCD_WHITE);
		sprintf(string,"Hum : %d.%2.2d %%", vor_komma(humidity), nach_komma(humidity));
		LCD_Puts(string,3,60,LCD_BLUE,LCD_WHITE);
		
		sprintf(string,"Temp: %d.%2.2d C", vor_komma(temperature), nach_komma(temperature));
		LCD_Puts(string,3,80,LCD_BLUE,LCD_WHITE);
		
		sprintf(string,"Pres: %ld hPa", pressure/100);
		LCD_Puts(string,3,100,LCD_BLUE,LCD_WHITE);
		
		if(T_BLUE)
		{
			entprell=RELOAD_ENTPRELL;
			logging = 1;//switch on logging
			//uart_puts("Taster 1\n");
			sprintf(sd_string,"Logger Test Temperature\n");
			sd_card((const char *)sd_string,0);//open / write to sd-card
			
			sprintf(string,"start logging");
			LCD_Puts(string,3,30,LCD_BLUE,LCD_WHITE);
		}
		if(T_GREEN)
		{
			entprell=RELOAD_ENTPRELL;
			uart_puts("Taster 2\n");
			if(flag_backlight==1)
			{
				flag_backlight=0;
				PORTB &= ~(1<<PB2);	//Backlight on
			}else 
			{
					PORTB |= (1<<PB2);	//Backlight on
					flag_backlight=1;
			}
		}
		if(T_YELLOW)
		{
			entprell=RELOAD_ENTPRELL;
			logging=0; //switch off logging
			sprintf(string,"stop logging");
			LCD_Puts(string,3,30,LCD_BLUE,LCD_WHITE);
			sd_card((const char *)string,1);//close sd-card
		}
	}//end of while
	return 0;
}//End of main

uint32_t strtolong(const char* str)
{
    uint32_t l = 0;
    while(*str >= '0' && *str <= '9')
        l = l * 10 + (*str++ - '0');

    return l;
}
uint8_t find_file_in_dir(struct fat_fs_struct* fs, struct fat_dir_struct* dd, const char* name, struct fat_dir_entry_struct* dir_entry)
{
    while(fat_read_dir(dd, dir_entry))
    {
        if(strcmp(dir_entry->long_name, name) == 0)
        {
            fat_reset_dir(dd);
            return 1;
        }
    }

    return 0;
}
struct fat_file_struct* open_file_in_dir(struct fat_fs_struct* fs, struct fat_dir_struct* dd, const char* name)
{
    struct fat_dir_entry_struct file_entry;
    if(!find_file_in_dir(fs, dd, name, &file_entry))
        return 0;

    return fat_open_file(fs, &file_entry);
}
uint8_t print_disk_info(const struct fat_fs_struct* fs)
{
    if(!fs)
        return 0;

    struct sd_raw_info disk_info;
    if(!sd_raw_get_info(&disk_info))
        return 0;

    uart_puts_p(PSTR("manuf:  0x")); uart_putc_hex(disk_info.manufacturer); uart_putc('\n');
    uart_puts_p(PSTR("oem:    ")); uart_puts((char*) disk_info.oem); uart_putc('\n');
    uart_puts_p(PSTR("prod:   ")); uart_puts((char*) disk_info.product); uart_putc('\n');
    uart_puts_p(PSTR("rev:    ")); uart_putc_hex(disk_info.revision); uart_putc('\n');
    uart_puts_p(PSTR("serial: 0x")); uart_putdw_hex(disk_info.serial); uart_putc('\n');
    uart_puts_p(PSTR("date:   ")); uart_putw_dec(disk_info.manufacturing_month); uart_putc('/');
                                   uart_putw_dec(disk_info.manufacturing_year); uart_putc('\n');
    uart_puts_p(PSTR("size:   ")); uart_putdw_dec(disk_info.capacity / 1024 / 1024); uart_puts_p(PSTR("MB\n"));
    uart_puts_p(PSTR("copy:   ")); uart_putw_dec(disk_info.flag_copy); uart_putc('\n');
    uart_puts_p(PSTR("wr.pr.: ")); uart_putw_dec(disk_info.flag_write_protect_temp); uart_putc('/');
                                   uart_putw_dec(disk_info.flag_write_protect); uart_putc('\n');
    uart_puts_p(PSTR("format: ")); uart_putw_dec(disk_info.format); uart_putc('\n');
    uart_puts_p(PSTR("free:   ")); uart_putdw_dec(fat_get_fs_free(fs)); uart_putc('/');
                                   uart_putdw_dec(fat_get_fs_size(fs)); uart_putc('\n');

    return 1;
}
void get_datetime(uint16_t* year, uint8_t* month, uint8_t* day, uint8_t* hour, uint8_t* min, uint8_t* sec)
{
    *year = 2007;
    *month = 1;
    *day = 1;
    *hour = 0;
    *min = 0;
    *sec = 0;
}
void sd_card(const char * sddata, uint8_t close)
{
	// GRN May 2019
	//when close != 0, sd_card can be closed
	//else sd_card can be opened or be written to
	
	static struct partition_struct* partition;
	static struct fat_fs_struct* fs;
	static struct fat_dir_struct* dd;
	static struct fat_file_struct* fd;
	static uint8_t action=0;
	uint8_t str_len=0;//length of string
	
	#define SD_OPEN  0
	#define SD_WRITE 1
	#define SD_CLOSE 2
	
	if(close)action=SD_CLOSE;//close sd-card if not 0
	
	switch(action)
	{
		case SD_OPEN:	// setup sd card slot
						if(!sd_raw_init())
						{
							LCD_Puts("Init failed",3,40,LCD_BLUE,LCD_WHITE);
						}

						// open first partition 
						partition = partition_open(sd_raw_read,sd_raw_read_interval,sd_raw_write,sd_raw_write_interval,0);
						if(!partition)
						{
							// If the partition did not open, assume the storage device
							// is a "superfloppy", i.e. has no MBR.
							partition = partition_open(sd_raw_read,sd_raw_read_interval,sd_raw_write,sd_raw_write_interval,-1);
							if(!partition)
							{
								LCD_Puts("partition failed",3,40,LCD_BLUE,LCD_WHITE);
							}
						} 
						 /* open file system */
						fs = fat_open(partition);
						if(!fs)
						{
							LCD_Puts("FS failed",3,40,LCD_BLUE,LCD_WHITE);
						}
						/* open root directory */
						struct fat_dir_entry_struct directory;
						fat_get_dir_entry_of_path(fs, "/", &directory);
						dd = fat_open_dir(fs, &directory);
						if(!dd)
						{
							LCD_Puts("root failed",3,40,LCD_BLUE,LCD_WHITE);
						}
						/* print some card information as a boot message */
						print_disk_info(fs);
						fd = open_file_in_dir(fs, dd, "data.log");
						if(!fd)
						{
							uart_puts("could not open test.txt\n");
						}
						uart_puts("SD is ready...\n");
						action=SD_WRITE;//sd_card is opened, next step is sd_write
						break;
		case SD_WRITE:	// file_pos now contains the absolute file position
						//sprintf(string,"eins");
						str_len=strlen((const char *)sddata);
						fat_write_file(fd,(const uint8_t*)sddata,str_len);
						sd_raw_sync();
						//uart_puts("  writing sucessfull\n");
						break;
		case SD_CLOSE:	/* close directory */
						fat_close_dir(dd);
						/* close file system */
						fat_close(fs);
						/* close partition */
						partition_close(partition);
						action=SD_OPEN; //sd_card was closed. Next call is opening again
						uart_puts("SD is closed...\n");
						break;
	}//end of switch
}//end of sd_card()
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
