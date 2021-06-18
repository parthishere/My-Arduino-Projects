/*
 * ultrasonic_my_estyle.c
 *
 * Created: 08-01-2021 13:19:41
 *  Author: parth
 */ 

#define _DISABLE_ARDUINO_TIMER0_INTERRUPT_HANDLER_
#include <wiring.c>

#include <avr/io.h>
#define echo_pin PD2
#define trigger_pin PD0

int overFlow = 0, total_ticks = 0;

int captured_value_one = 0;
int captured_value_two = 0;
int final_ticks=0;
void setup()
{
  Serial.begin(9600);
  sei();
  DDRD  |=
      0
      | (0 << echo_pin)
      | (1 << trigger_pin)
      ;
      
  EIMSK |=
    0
    | (1 << INT0)
    ;
  EICRA |=
    0
    | (1 << ISC00) 
    | (0 << ISC01)
    ; 
  
    
  TCCR0A = 0;
  TCCR0A |=
    0
    | (0 << WGM00)
    ;
    
//  TIMSK0 |=
//    0
//    | (1 << TOIE0);
//    ;
    
  TCCR0B |=
    0
    | (1 << CS00)
    ;
  
  
      
 

}


void loop()
{
  PORTD = (1 << trigger_pin);
  _delay_us(10);
  PORTD |= (1 << trigger_pin);
  Serial.println(final_ticks);
  delay(100); 
}


ISR (INT0_vect)
{
  if (!bit_is_clear(PINB, echo_pin))
  {
    captured_value_one = TCNT1 + total_ticks;  
  }
  else
  {
    captured_value_two = TCNT1 + total_ticks;
  }   
  if(captured_value_two > captured_value_one)
  {
    final_ticks = captured_value_two - captured_value_one;
  }
  
}



//#ifndef _DISABLE_ARDUINO_TIMER0_INTERRUPT_HANDLER_
//ISR(TIMER0_OVF_vect)
//{
//  
//  if(captured_value_one != 0 | captured_value_two !=0)
//  {
//    overFlow++;
//    total_ticks = overFlow*255;
//  }
//  else
//  {}
//}
//#endif
