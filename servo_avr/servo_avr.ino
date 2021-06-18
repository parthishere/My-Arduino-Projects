
/*
 * servoMotor.c
 *
 * Created: 13-12-2020 03:19:44
 *  Author: parth
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

void setup()
{
  DDRB |= 0xFF;
  TCCR1A |= 1<<WGM11 | 1<<COM1A1 | 1<<COM1A0;
  TCCR1B |= 1<<WGM13 | 1<<WGM12 | 1<<CS10;
  ICR1 = 19999;
  
  OCR1A = ICR1 - 2000; //18000
   
}



void loop()
{
    //TODO:: Please write your application code 
  OCR1A = ICR1 - 2000; // 2 ms not max but still max in many sevros
  _delay_ms(1000);
  
  OCR1A = ICR1 - 900; // 0.9 ms minimum
  _delay_ms(1000);
}
