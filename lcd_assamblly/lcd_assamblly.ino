/*
 * LCD_interfacing.c
 *
 * Created: 30-11-2020 14:30:46
 *  Author: parth
 */ 
 
#include <avr/io.h>
#include <util/delay.h>

#define LCD_control_direction_register DDRC
#define LCD_data_direction_register DDRB
#define LCD_control_port PORTC
#define LCD_data_port PORTB

#define RegisterSelect PC0
#define ReadWrite PC1
#define Enable PC2


void LCD_init();
void flash_enable_pin();
void check_LCD_is_busy();
void send_command(unsigned char cmd);
void send_character(unsigned char character);
void send_string(char *str);

void setup()
{
  LCD_init();
  send_character(0x38);
   
}

void loop(){
   
}

void LCD_init()
{
  LCD_control_direction_register = (1 << Enable) | (1 << ReadWrite) | (1 << RegisterSelect);
  
  
  send_command (0x38);  /* Initialization of 16X2 LCD in 8bit mode */
  _delay_us(50);
  send_command (0x0C);  /*   Display ON Cursor OFF */
  _delay_us(50);
  send_command (0x06);  /* Auto Increment cursor */
  _delay_us(50);
  send_command (0x01);  /* clear display */
  _delay_us(50);
  send_command (0x80);  /* cursor at home position */
  _delay_us(50);
  
}



void check_LCD_is_busy()
{
  LCD_data_port = 0;
  LCD_control_port |= (1 << ReadWrite);
  LCD_control_port &= ~(1 << Enable);
  while((LCD_data_port & 0x80) == 0x80) // A7 will one if its not busy and its one that means it is Busy // ( 7th bit ) 
  {
    flash_enable_pin();
  }
  LCD_data_port = 0xFF;
}

void flash_enable_pin()
{
  LCD_control_port |= (1 << Enable);
  asm volatile ("nop");
  asm volatile ("nop");
  LCD_control_port &= ~(1 << Enable);
  
}

void send_command(unsigned char cmd)
{
  check_LCD_is_busy();
  LCD_data_port = cmd;
  LCD_control_port &= ~((1 << ReadWrite) | (1 << RegisterSelect));
  flash_enable_pin();
  LCD_data_port =  0; 
}

void send_character(unsigned char character)
{
  check_LCD_is_busy();
  LCD_data_port = character;
  LCD_control_port &= ~(1 << ReadWrite);
  LCD_control_port |= (1 << RegisterSelect);
  flash_enable_pin();
  LCD_data_port =  0; 
}

void send_string(char *str)
{
  for (int i=0; str[i]!=0; i++)
  {
    send_character(str[i]);
  }
  
}
