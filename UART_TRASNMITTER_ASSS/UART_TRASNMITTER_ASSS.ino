/*
 * uart_transmitter.c
 *
 * Created: 02-12-2020 13:03:27
 *  Author: parth
 */ 


#include <avr/io.h>
#include <util/delay.h>

#define  BAUD_RATE 9600
#define X ((F_CPU/16/BAUD_RATE) - 1)

int c;
void UART_TxChar(char ch);
//void UART_SendString(char *str);

void setup()
{

  UBRR0H = (X >> 8);
  UBRR0L = X;
  
  UCSR0B = (1 << TXEN0);
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
  
  DDRB  = 0x00;
    
}

void loop()
{   
  //TODO:: Please write your application code 
  c = PINB;
  UART_TxChar(c);

}


void UART_TxChar(char ch)
{
  while (! (UCSR0A & (1<<UDRE0)));  /* Wait for empty transmit buffer*/
  UDR0 = ch ;
}

void UART_SendString(char *str)
{
  unsigned char j=0;
  
  while (str[j]!=0)   /* Send string till null */
  {
    UART_TxChar(str[j]);
    j++;
  }
}
