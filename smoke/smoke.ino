int gas_val = A0, led1 = 13, led2 = 12, led3 = 11, led4 = 10, led5 = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(gas_val, INPUT);
 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
 
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(gas_val);
  Serial.println(val);
  if(val>100 && val<120){
    digitalWrite(led1, 1);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
    digitalWrite(led5, 0);
  }
  else if(val>120 && val<140){
    digitalWrite(led1, 0);
    digitalWrite(led2, 1);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
    digitalWrite(led5, 0);
  }
  else if(val>140 && val<160){
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 1);
    digitalWrite(led4, 0);
    digitalWrite(led5, 0);
  }
  else if(val>160 && val<180){
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 1);
    digitalWrite(led5, 0);
  }
  else if(val>180 && val>200){
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
    digitalWrite(led5, 1);
  }

}
