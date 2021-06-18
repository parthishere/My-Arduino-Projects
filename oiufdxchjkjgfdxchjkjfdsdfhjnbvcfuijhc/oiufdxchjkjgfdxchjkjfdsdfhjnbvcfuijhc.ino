/*
   ultrasonic.c

   Created: 29-12-2020 01:38:11
    Author: parth
*/


#include <avr/io.h>
#include <avr/interrupt.h>
#define PWM_REGISTER_1 DDRE   // for pin 5 // OC3A
#define PWM_PIN_1 PE3   // pin 5

#define INPUT_PIN PE4
#define INPUT_REGISTER PINE

int captured_value_two = 0;
int captured_value_one = 0;
int final_ticks = 0;

void PWM_1_init(float duty_cycle);

void setup()
{
  Serial.begin(9600);
  TCCR4A  = 0;

  TCCR4B  |=
    0
    | (1 << ICES4)
    ;

  TIFR4   |=
    0
    | (1 << ICF4)
    ;
  sei();

  TCCR4B  |= ( 1 << CS40);

}


void loop()
{

  PWM_1_init(10000);
  Serial.println(final_ticks);
}


ISR (INT0_vect)
{
  if (!bit_is_clear(INPUT_REGISTER, INPUT_PIN))
  {
    captured_value_one = ICR4;
    TCCR4A = 0;

    TCCR4B  |=
      0
      | (0 << ICES4)
      | (1 << CS40)
      ;
  }
  else
  {
    captured_value_two = ICR4;
    TCCR4A = 0;

    TCCR4B  |=
      0
      | (0 << ICES4)
      | (1 << CS40)
      ;
  }
  if (captured_value_two > captured_value_one)
  {
    final_ticks = captured_value_two - captured_value_one;
  }

}



void PWM_1_init(float duty_cycle)
{
  uint8_t sreg = SREG;
  cli();

  // Stop timer before configuring
  TCCR3B = 0;

  // TCCR3A – Timer/Counter1 Control Register A
  TCCR3A =
    0
    | (1 << COM3A1) | (0 << COM3A0)  // Clear OC3A on Compare Match, set OC1A at BOTTOM (non-inverting mode)
    | (1 << WGM31) | (0 << WGM30)    // Fast PWM mode 14 (TOP = ICR1)
    ;

  // TCCR1B – Timer/Counter1 Control Register B
  TCCR3B =
    0
    | (1 << WGM33) | (1 << WGM32)    // Fast PWM mode 14 (TOP = ICR1), part 2/2
    ;


  // Set TOP value
  ICR3 = 0xFFFF;

  //   "The OCR1X Register is double buffered when using any of the
  //   twelve Pulse Width Modulation (PWM) modes. For the Normal
  //   and Clear Timer on Compare (CTC) modes of operation, the
  //   double buffering is disabled."
  // If initializing OCR1A before configuring TCCR1A and TCCR1B to
  // a PWM mode the value is written to the non-buffered OCR1A
  // register and the buffered OCR1A register contains some "random",
  // unused garbage value. When later changing to PWM the buffered
  // register will be enabled, and its existing garbage value will
  // be used.

  //    OCR3A = ((duty_cycle/100)*ICR3);
  OCR3A = duty_cycle;

  // 14.4.3 DDRB – The Port B Data Direction Register
  PWM_REGISTER_1 =
    0
    | (1 << PWM_PIN_1) // (OC3A) as output - pin 9
    ;

  // Start the timer with no prescaler
  TCCR3B |= (0 << CS32) | (0 << CS31) | (1 << CS30);

  SREG = sreg;
}
