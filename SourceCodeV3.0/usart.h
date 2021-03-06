/*----------------------------------------------------------------------------
 Copyright:      Radig Ulrich  mailto: mail@ulrichradig.de
 Author:         Radig Ulrich
 Remarks:        
 known Problems: none
 Version:        24.10.2007
 Description:    RS232 Routinen

 Dieses Programm ist freie Software. Sie k�nnen es unter den Bedingungen der 
 GNU General Public License, wie von der Free Software Foundation ver�ffentlicht, 
 weitergeben und/oder modifizieren, entweder gem�� Version 2 der Lizenz oder 
 (nach Ihrer Option) jeder sp�teren Version. 

 Die Ver�ffentlichung dieses Programms erfolgt in der Hoffnung, 
 da� es Ihnen von Nutzen sein wird, aber OHNE IRGENDEINE GARANTIE, 
 sogar ohne die implizite Garantie der MARKTREIFE oder der VERWENDBARKEIT 
 F�R EINEN BESTIMMTEN ZWECK. Details finden Sie in der GNU General Public License. 

 Sie sollten eine Kopie der GNU General Public License zusammen mit diesem 
 Programm erhalten haben. 
 Falls nicht, schreiben Sie an die Free Software Foundation, 
 Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA. 
------------------------------------------------------------------------------*/
#ifndef _UART_H
	#define _UART_H

	//----------------------------------------------------------------------------
	#include <stdlib.h>
	#include <stdarg.h>
	#include <ctype.h>
	#include <string.h>
	#include <avr/io.h>
	#include <avr/pgmspace.h>
	
	//----------------------------------------------------------------------------
	
	//Die Quarzfrequenz auf dem Board
	#ifndef F_CPU
			#define F_CPU 14745600UL
	#endif //SYSCLK	
	
	//Anpassen der seriellen Schnittstellen Register wenn ein ATMega128 benutzt wird
	
		#define USR UCSR0A
		#define UCR UCSR0B
		#define UBRR UBRR0L
		#define TXEN TXEN0
		#define UDR UDR0
		#define UDRE UDRE0

	//----------------------------------------------------------------------------
	
	void usart_init(unsigned long baudrate); 
	void usart_write_char(char c);
	void usart_write_str(char *str);
	
	void usart_write_P (const char *Buffer,...);
	#define usart_write(format, args...)   usart_write_P(PSTR(format) , ## args)
	
	//----------------------------------------------------------------------------

#endif //_UART_H
