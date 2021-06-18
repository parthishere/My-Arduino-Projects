/*
 * Rotary_Encoder.c
 *
 * Created: 21-12-2020 01:05:16
 *  Author: parth
 */ 
# define INT0_PIN PD2
# define INT1_PIN PD3
# define INT2_PIN PB1 // PCINT1 

# include <avr/io.h>
# include <util/delay.h>
# include <avr/interrupt.h>

int count = 0;

void setup()
{
  Serial.begin(9600);
  SREG |= 0b10000000;
  DDRD &= ~((1 << INT0_PIN) | (1 << INT1_PIN)); // Enable external interrupts on INT0 and INT1 which are located in port D (0 , 1 pin)
  DDRB &= ~(1 << INT2_PIN);
  PORTD |= (1 << INT0_PIN) | (1 << INT1_PIN); // Enable Pull up
  PORTB |= (1 << INT2_PIN);

  PCMSK0 |= (1 << PCINT1); 
  PCICR |= (1 << PCIE0);
                            // PCINT1 enable 
  EIMSK |= (1 << INT0) | (1 << INT1); // Enable INT0 and INT1
  EICRA = (1 << ISC00) | (1 << ISC10) | (1 << ISC11); /* INT0 : Falling Edge (Because of Internal pull-up ) 
                             INT1 : Raising Edge (Because of Internal pull-up ) */
  sei();
  
}


void loop()
{
  Serial.println(count);
  _delay_ms(1);
}



ISR (INT0_vect)
{
  
  if(!bit_is_clear(PIND, INT1_PIN))
  {
    count ++;
  }
  else
  {
    count --;
  }
  
}

ISR (INT1_vect)
{
  
  if(!bit_is_clear(PIND, INT0_PIN))
  {
    count ++; 
  }
  else
  {
    count --;
  }
  
}


ISR (PCINT1_vect)
{
  
  count = 0;
  
}
