/*
 * I2C_protocol.c
 *
 * Created: 14-12-2020 12:34:08
 *  Author: parth
 */ 


#define SCL_CLK 20000UL
#define BITRATE(TWSR) ((F_CPU/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1)))))
  

#include <avr/io.h>
#include <util/delay.h>

void I2C_init();
uint8_t I2C_start_condition(char address);
void I2C_repeated_start_condition(char address);
uint8_t I2C_write(char data);
unsigned char I2C_read_ack();
void I2C_stop_condition();

#define Write_Address    0x68
#define Read_Address   0x3B

char data_x;

void setup()
{
  Serial.begin(9600);
  I2C_init();
  /************************************************************************/
  /*  READING FORM I2C                                                    */
  /************************************************************************/
}
void loop()
{
  I2C_start_condition(Write_Address);
//  I2C_write(0x00);
  I2C_repeated_start_condition(Read_Address);
  data_x = I2C_read_ack();
  I2C_stop_condition();

  Serial.println(data_x);  
  
}

void I2C_init()
{
  TWSR = 0x00;  // prescaler = 0
  TWBR = BITRATE(TWSR=0x00);
  TWCR = (1 << TWEN);
}


uint8_t I2C_start_condition(char address)
{
  uint8_t status;
  TWCR = (1 << TWEN) | (1 << TWSTA) | (1 << TWINT);
  while(TWCR & (1 << TWINT) == 0);
  status=(TWSR & 0xF8);   /* Read TWI status register */
  if(status!=0x08)    /* Check weather START transmitted or not */ 
  {   
    return 0;   /* Return 0 to indicate start condition fail */
  }     
  TWDR = address;
  
}


void I2C_repeated_start_condition(char r_address)  // address must be read address 
{
  TWCR = (1 << TWSTA) | (1 << TWEN) | (1 << TWINT);
  while(!(TWCR & (1 << TWINT)));
  TWDR = r_address; 
}



uint8_t I2C_write(char data)
{
  uint8_t status;
  
  TWDR = data;
  TWCR = (1 << TWEN) | (1 << TWINT);
  while(!(TWCR & (1 << TWINT)));
  if(status==0x28)
  {   /* Check for data transmitted & ACK received */
    return 0;
  }   
}


unsigned char I2C_read_ack() 
{
  /* This function is with ACK means it will read full data if you don't enable the ACK it will read only one bit out of TWBR register */
  
  TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWEA);
  while(!(TWCR&(1<<TWINT)));
  return TWDR;
}


void I2C_stop_condition()
{
  TWCR = (1 << TWSTO) | (1 << TWINT) | (1 << TWEN);
  while(TWCR & (1 << TWSTO));
}
