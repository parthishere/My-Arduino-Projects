int duty = 50;

void setup() {
  // put your setup code here, to run once:
PWM_init();
  }

void loop() {
  // put your main code here, to run repeatedly:
OCR0B=duty;
}


void PWM_init()
{
  /*set fast PWM mode with non-inverted output*/
  TCCR0A = (1<<WGM00) | (1<<WGM01) | (1<<COM0B1) | (1<<CS00);
  DDRG|=(1<<PG5);  /*set OC0 pin as output*/
}
