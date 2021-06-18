#define F_CPU 8000000UL    
#include <avr/io.h>   
#include <util/delay.h>  


int main(void)
{
  DDRB |= (1<<PB1); /* Make OC1A pin as output */ 
//  TCNT1 = 0;    /* Set timer1 count zero */
  ICR1 = 2499;    /* Set TOP count for timer1 in ICR1 register */

  /* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match */
  TCCR1A = (1<<WGM11)|(1<<COM1A1)|(1 << COM1A0);
  TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)| (1 << CS11);
  OCR1A = ICR1 - 249;
  while(1)
  {

    OCR1A = ICR1 - 249;  
    _delay_ms(1500);
    OCR1A = ICR1 - 120;  
    _delay_ms(1500);

  }
}
