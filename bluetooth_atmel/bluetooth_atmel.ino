/*
 * Bluetooth_module.c
 *
 * Created: 21-12-2020 03:57:00
 *  Author: parth
 */ 


#include <avr/io.h>

#define  BAUD_RATE 9600
#define BAUD_COUNT ((F_CPU/16/BAUD_RATE) - 1)

char c;

unsigned char UART_RxChar();

void setup()
{
  Serial.begin(9600);
  
  UBRR0H = (BAUD_COUNT >> 8);
  UBRR0L = BAUD_COUNT;

  UCSR0B = (1 << RXEN0);
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
  
}

void loop()
{
  c=UART_RxChar();
  Serial.println(c);
}


unsigned char UART_RxChar()
{
  while ((UCSR0A & (1 << RXC0)) == 0);/* Wait till data is received */
  return(UDR0);      /* Return the byte*/
}
