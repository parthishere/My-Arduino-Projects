/*
 * Rotary_Encoder_Gray_Code_Style.c
 *
 * Created: 21-12-2020 03:04:05
 *  Author: parth
 */ 


#include <avr/io.h>

# define EncoderA PB0
# define EncoderB PB1

uint8_t prev_encoded_value, new_encoded_value;
int count=0;

uint8_t read_encoder_value();

void setup()
{
  Serial.begin(9600);
  
  
  DDRB = (0 << EncoderA) | (0 << EncoderB);
  PORTB = (1 << EncoderA) | (1 << EncoderB);
  
  prev_encoded_value = read_encoder_value();
  
}





void loop()
{
    new_encoded_value = read_encoder_value();
    if(prev_encoded_value != new_encoded_value)
    {

    /*  
      For clockwise direction 
      we have to check sequence
      11 > 01 or 00 > 10 ( (previous)11 and 01 for initial HIGH A & B and (previous)00 and 10 for initial LOW pin A & B
     */
      if ( (prev_encoded_value == 3 && new_encoded_value == 1) ||
        (prev_encoded_value == 0 && new_encoded_value == 2) )
      {
        count ++;
      }
    /*  
      For counter-clockwise direction 
      we have to check sequence
      10 > 00 or 00 > 11 ( (previous)10 and 00 for initial HIGH A & B and (previous)00 and 10 for initial LOW pin A & B
     */     
      if ( (prev_encoded_value == 3 && new_encoded_value == 2) ||
        (prev_encoded_value == 0 && new_encoded_value == 1) )
      {
        count --;
      } 
      
      prev_encoded_value = new_encoded_value;
            
    }
    Serial.println(count);
}





uint8_t read_encoder_value()
{
  uint8_t val=0; // 8 bit
  
  if(!bit_is_clear(PINB, EncoderA))
  {
    val |= (1 << 1);
  }
  
  if(!bit_is_clear(PINB, EncoderB))
  {
    val |= (1 << 0);
  }
  
  return val;
  
  /*                                                value of val
  if Encoder pin A is HIGH and Encoder pin B is LOW :   10
  if Encoder pin A is LOW and Encoder pin B is HIGH:    01
  if Encoder pin A is HIGH and Encoder pin B is HIGH:   11
  */
}
