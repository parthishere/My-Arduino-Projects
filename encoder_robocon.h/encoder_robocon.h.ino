/*
 * Rotary_Encoder.c
 *
 * Created: 21-12-2020 01:05:16
 *  Author: parth
 */ 
# include <avr/io.h>
# include <util/delay.h>
# include <avr/interrupt.h>

# define ENCODER_1_A_REGISTER DDRE // PIN 3
# define ENCODER_1_A_PORT PORTE    
# define ENCODER_1_A_INPUT PINE
# define ENCODER_1_A_PIN PE5

# define ENCODER_1_B_REGISTER DDRA // PIN   22
# define ENCODER_1_B_PORT PORTA
# define ENCODER_1_B_INPUT PINA
# define ENCODER_1_B_PIN PA0     //pin 22

# define ENCODER_2_A_REGISTER DDRE  // 
# define ENCODER_2_A_PORT PORTE
# define ENCODER_2_A_INPUT PINE
# define ENCODER_2_A_PIN PE4 //pin 2

# define ENCODER_2_B_REGISTER DDRA // 
# define ENCODER_2_B_PORT PORTA
# define ENCODER_2_B_INPUT PINA
# define ENCODER_2_B_PIN PA2    // 24


int countEncoderOne = 0;
int countEncoderTwo = 0;

int encoder_1_init();
int encoder_2_init();

void setup()
{
  Serial.begin(9600);
  encoder_1_init();
  encoder_2_init();
  
}


void loop()
{
  Serial.println(encoder);
  _delay_ms(1);
}


int encoder_1_init()
{
  ENCODER_1_A_REGISTER |=
                        0
                        | (0 << ENCODER_1_A_PIN)
                        ;
  ENCODER_1_B_REGISTER |=
                        0
                        | (0 << ENCODER_1_B_PIN)
                        ;


  ENCODER_1_A_PORT |=
                        0
                        | (1 << ENCODER_1_A_PIN)
                        ;
  ENCODER_1_B_PORT |=
                        0
                        | (1 << ENCODER_1_B_PIN)
                        ;
                        
  EIMSK |=
         0
         |(1 << INT5)
         ;
  EICRB |=
         0
         | (1 << ISC50) // INT5 : ANY EDGE WILL GENRATE INTURRUPT 
         | (0 << ISC51) 
         ;
  sei();
}


int encoder_2_init()
{
  ENCODER_2_A_REGISTER |=
                  0
                  | (0 << ENCODER_2_A_PIN)
                  ;
  ENCODER_2_B_REGISTER |=
                  0 
                  | (0 << ENCODER_2_B_PIN)
                  ;

  ENCODER_2_A_PORT |=
                        0
                        | (1 << ENCODER_2_A_PIN)
                        ;
  ENCODER_2_B_PORT |=
                        0
                        | (1 << ENCODER_2_B_PIN)
                        ;
  EIMSK |=
         0
         |(1 << INT4)
         ;
  EICRB |=
         0
         | (1 << ISC40) // INT5 : ANY EDGE WILL GENRATE INTURRUPT 
         | (0 << ISC41) 
         ;
  sei(); 
}

ISR (INT5_vect)
{
    if (ENCODER_1_A_INPUT & (1<<ENCODER_1_A_PIN))    //C1_HIGH
      {
        if (ENCODER_1_B_INPUT & (1<<ENCODER_1_B_PIN))    //C2_HIGH
        {
          countEncoderOne--;        //B_5
        }
        else    //C2_LOW
        {
          countEncoderOne++;        //A_1
        }
      }
      else if(~(ENCODER_1_A_INPUT & (1<<ENCODER_1_A_PIN)))    //C1_LOW
      {
        if (ENCODER_1_B_INPUT & (1<<ENCODER_1_B_PIN))    //C2_HIGH
        {
          countEncoderOne++;    //A_2
        }
        else    //C2_LOW
        {
          countEncoderOne--;    //B_6
        }
      }
      
      else if (ENCODER_1_A_INPUT & (1<<ENCODER_1_A_PIN))    //C2_HIGH
      {
        if (ENCODER_1_B_INPUT & (1<<ENCODER_1_B_PIN))    //C1_HIGH
        {
          countEncoderOne++;    //A_3
        }
        else    //C1_LOW
        {
          countEncoderOne--;    //B_7
        }
      }
      else    //C2_LOW
      {
        if (ENCODER_1_B_INPUT & (1<<ENCODER_1_B_PIN))    //C1_HIGH
        {
          countEncoderOne--;    //B_8
        }
        else    //C1_LOW
        {
          countEncoderOne++;    //A_4
        }
      }
}

 


ISR (INT4_vect)
{
  
  if (ENCODER_2_A_INPUT & (1<<ENCODER_2_A_PIN))    //C1_HIGH
      {
        if (ENCODER_2_B_INPUT & (1<<ENCODER_2_B_PIN))    //C2_HIGH
        {
          countEncoderTwo--;        //B_5
        }
        else    //C2_LOW
        {
          countEncoderTwo++;        //A_1
        }
      }
      else if(~(ENCODER_2_A_INPUT & (1<<ENCODER_2_A_PIN)))    //C1_LOW
      {
        if (ENCODER_2_B_INPUT & (1<<ENCODER_2_B_PIN))    //C2_HIGH
        {
          countEncoderTwo++;    //A_2
        }
        else    //C2_LOW
        {
          countEncoderTwo--;    //B_6
        }
      }
      
      else if (ENCODER_2_A_INPUT & (1<<ENCODER_2_A_PIN))    //C2_HIGH
      {
        if (ENCODER_2_B_INPUT & (1<<ENCODER_2_B_PIN))    //C1_HIGH
        {
          countEncoderTwo++;    //A_3
        }
        else    //C1_LOW
        {
          countEncoderTwo--;    //B_7
        }
      }
      else    //C2_LOW
      {
        if (ENCODER_2_B_INPUT & (1<<ENCODER_2_B_PIN))    //C1_HIGH
        {
          countEncoderTwo--;    //B_8
        }
        else    //C1_LOW
        {
          countEncoderTwo++;    //A_4
        }
      }
}
