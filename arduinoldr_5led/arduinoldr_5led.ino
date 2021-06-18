int led1 = 13, led2 = 12, led3 = 11, led4 = 10, led5 = 9, buz = 8, ldr = A0, count = 1,  val;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(buz, OUTPUT);
  pinMode(ldr, INPUT);
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(ldr);
  Serial.println(val);
  if(val < 100){
    switch(count%6){
      case 1:
        digitalWrite(led1, 1);
        digitalWrite(led2, 0);
        digitalWrite(led3, 0);
        digitalWrite(led4, 0);
        digitalWrite(led5, 0);
        digitalWrite(buz, 1);
        delay(1000);
        count++;
        break;
      case 2:
        digitalWrite(led1, 0);
        digitalWrite(led2, 1);
        digitalWrite(led3, 0);
        digitalWrite(led4, 0);
        digitalWrite(led5, 0);
        digitalWrite(buz, 1);
        delay(1000);
        count++;
        break;
      case 3:
        digitalWrite(led1, 0);
        digitalWrite(led2, 0);
        digitalWrite(led3, 1);
        digitalWrite(led4, 0);
        digitalWrite(led5, 0);
        digitalWrite(buz, 1);
        delay(1000);
        count++;
        break;
      case 4:
        digitalWrite(led1, 0);
        digitalWrite(led2, 0);
        digitalWrite(led3, 0);
        digitalWrite(led4, 1);
        digitalWrite(led5, 0);
        digitalWrite(buz, 1);
        delay(1000);
        count++;
        break;
      case 5:
        digitalWrite(led1, 0);
        digitalWrite(led2, 0);
        digitalWrite(led3, 0);
        digitalWrite(led4, 0);
        digitalWrite(led5, 1);
        digitalWrite(buz, 1);
        delay(1000);
        count++;
        break;
      
    }
  }

  else{
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
    digitalWrite(led5, 0);
    digitalWrite(buz, 0);
  }

}
