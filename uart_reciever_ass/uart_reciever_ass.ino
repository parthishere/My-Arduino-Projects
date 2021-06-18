/*
 * uart_reciver.c
 *
 * Created: 02-12-2020 13:31:16
 *  Author: parth
 */ 


#include <avr/io.h>
#include <util/delay.h>

#define  BAUD_RATE 9600
#define BAUD_COUNT ((F_CPU/16/BAUD_RATE) - 1)

unsigned char UART_RxChar();

void setup()
{
  UBRR0H = (BAUD_COUNT >> 8);
  UBRR0L = BAUD_COUNT;
  
  UCSR0B = (1 << RXEN0);
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
  
  DDRB = 0xFF; 
  PORTB = 0x00;
    
}

void loop()
{

        //TODO:: Please write your application code 
   PORTB = UART_RxChar();

}


unsigned char UART_RxChar()
{
  while ((UCSR0A & (1 << RXC0)) == 0);/* Wait till data is received */
  return(UDR0);     /* Return the byte*/
}
