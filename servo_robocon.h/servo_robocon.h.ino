#define F_CPU 8000000UL    
#include <avr/io.h>   
#include <util/delay.h>  

int degree_to_ticks(int degree);
int ticks = 0, i;
int main(void)
{
  uint8_t sreg = SREG;
  cli();
  
  TCCR1B = 0;
      /* Set TOP count for timer1 in ICR1 registr |(1<<CS10)| (1 << CS11) */

  /* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match */
  TCCR1A |=
    0
    | (1 << WGM11)    // fast PWM config. 14
    | (1 << COM1A1)
    | (1 << COM1A0) // inverting mode
    ;
    
  TCCR1B |=
    0
    | (1 << WGM12)    // fast PWM config. 14
    | (1 << WGM13)
    ;
    
    
  ICR1 = 19999;  
  OCR1A = ICR1 - 2000;

  DDRB |= (1 << PB1);

  TCCR1B |=
    0
//    | (1 << CS10)
    | (1 << CS11) 
    ;

  SREG = sreg;
  while(1)
  {

    OCR1A = ICR1 - 2000;  
    _delay_ms(1500);

    OCR1A = ICR1 - 1600;  
    _delay_ms(1500);
    
    OCR1A = ICR1 - 1400;  
    _delay_ms(1500);
    
    OCR1A = ICR1 - 1200;  
    _delay_ms(1500);
    
    OCR1A = ICR1 - 1000;  
    _delay_ms(1500);

  }
}



int degree_to_ticks(int degree)
{
  if(degree > 180) { degree = 180; }
  if(degree < 0) { degree = 0; }
  
  ticks = ((degree * 4600) / 180);
  return ticks;
}
