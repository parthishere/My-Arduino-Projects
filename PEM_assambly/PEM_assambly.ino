/*zz
 * PWM.c
 *
 * Created: 27-11-2020 02:23:08
 *  Author: parth
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int pin = 9;
float duty_cycle = 0;
void PWM_init();

void setup()
{
  PWM_init();
  
}

void loop()
{
//     for(duty_cycle=0; duty_cycle<=255; duty_cycle++){
//      OCR1A = duty_cycle;
//     }
//
//      for(duty_cycle=255; duty_cycle>=0;duty_cycle--){
//        OCR1A = duty_cycle;
//      }
        
                
}

void PWM_init()
{
  /*set fast PWM mode with non-inverted output*/
  DDRB |= 0b00000010;  /*set OCR0A pin as output*/
  
  TIMSK1 = (1 << TOIE0); 
  
  OCR1A = (duty_cycle/100)*255;
  
  sei();
  
  TCCR1A = (1<<WGM10) | (1<<WGM11) | (1<<COM1A1);
  TCCR1B = (1<<CS10) | (1 << WGM12) | (1 << WGM13);
  
}



ISR (TIMER1_OVF_vect)
{
  set_duty_cycle();  
  OCR1A = (duty_cycle/100)*256;
}


void set_duty_cycle(){
    duty_cycle += 5;
     if (duty_cycle>=100)
     {
       duty_cycle = 0;
     }
}
