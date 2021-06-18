/*
 * ultrasonic_my_estyle.c
 *
 * Created: 08-01-2021 15:19:51
 *  Author: parth
 */ 


#include <avr/io.h>
#include <util/delay.h>


#define echo_pin PL1
#define trig_pin PL3


long int captured_value_one = 0;
long int captured_value_two = 0;
long int final_ticks = 0;
float  distance = 0;



void setup()
{
  Serial.begin(9600);
  DDRL  |=
      0
      | (0 << echo_pin)
      | (1 << trig_pin)
      ;
  
      
  TCCR5A = 0;
        
}


void loop()
{
  digitalWrite(46, 0);
  delayMicroseconds(2);
  digitalWrite(46, 1);
  delayMicroseconds(10);
  digitalWrite(46 , 0);

  
  TCCR5B  |=
   (1 << ICES5)
  | ( 1 << CS51)
  ;
  while(TIFR5 & (1<<ICF5)==0);
  captured_value_one = ICR5;
  TIFR5 = (1 << ICF5);
  
  TCCR5B  |=
   (0 << ICES5)
  | ( 1 << CS51)
  ;
  while(TIFR5 & (1<<ICF5)==0)
  captured_value_two = ICR5 - captured_value_one;
  TIFR5 = (1 << ICF5);

  Serial.println(captured_value_two);
distance = final_ticks*552 / 0.0552;

}
