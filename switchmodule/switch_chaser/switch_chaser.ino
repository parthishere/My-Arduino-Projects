int led1=13,led2=12,led3=11,led4=10,led5=9,sw=8;
void setup(){
  
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(sw,INPUT);
}

void loop(){
  
  int on_off=digitalRead(sw);
  Serial.println(on_off);
  
  if(on_off==1)
  { 
    int on_off=digitalRead(sw);
    Serial.println(on_off);
    digitalWrite(led1,1);
    delay(100);
    digitalWrite(led1,0);
    delay(100);
    
    digitalWrite(led2,1);
    delay(100);
    digitalWrite(led2,0);
    delay(100);
    
    digitalWrite(led3,1);
    delay(100);
    digitalWrite(led3,0);
    delay(100);
    
    digitalWrite(led4,1);
    delay(100);
    digitalWrite(led4,0);
    delay(100);
    
    digitalWrite(led5,1);
    delay(100);
    digitalWrite(led5,0);
    delay(100);
  }
  if(on_off==0)
  {
    
    digitalWrite(led5,1);
    delay(1);
    digitalWrite(led5,0);
    delay(1);
    
    digitalWrite(led4,1);
    delay(1);
    digitalWrite(led4,0);
    delay(1);
    
    digitalWrite(led3,1);
    delay(1);
    digitalWrite(led3,0);
    delay(1);
    
    digitalWrite(led2,1);
    delay(1);
    digitalWrite(led2,0);
    delay(1);
    
    digitalWrite(led1,1);
    delay(1);
    digitalWrite(led1,0);
    delay(1);
    
  }
}
