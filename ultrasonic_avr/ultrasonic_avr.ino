/*
 * ultrasonic_my_estyle.c
 *
 * Created: 08-01-2021 13:19:41
 *  Author: parth
 */ 


#include <avr/io.h>
#define echo_pin PB0
#define trigger_pin PB1


int captured_value_one = 0;
int captured_value_two = 0;
int final_ticks=0;
void setup()
{
  Serial.begin(9600);
  DDRB  |=
      0
      | (0 << echo_pin)
      | (1 << trigger_pin)
      ;
      
  TCCR1A  = 0;
  
  TIFR1   |=
      0
      | (1 << ICF1)
      ;  
  sei();
      
  TCCR1B  |=
      0
      | (1 << ICES1)
      ; 

}


void loop()
{
  PORTB = (1 << trigger_pin);
  _delay_us(10);
  PORTB |= (1 << trigger_pin);
  Serial.println(captured_value_one);
  delay(100); 
}


ISR (TIMER1_CAPT_vect)
{
  if (!bit_is_clear(PINB, echo_pin))
  {
    captured_value_one = ICR1;  
    TCCR1A = 0;

    TCCR1B  |=
    0
    | (0 << ICES1)
    ;
  }
  else
  {
    captured_value_two = ICR1;
    TCCR1A = 0;

    TCCR1B  |=
    0
    | (0 << ICES1)
    ;
  }   
  if(captured_value_two > captured_value_one)
  {
    final_ticks = captured_value_two - captured_value_one;
  }
  

}
