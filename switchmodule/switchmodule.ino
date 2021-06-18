int led1=13,led2=12,led3=11,led4=10,led5=9,pm=8;
void setup(){
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(pm,INPUT);
}

void loop(){
  int val=analogRead(pm);
  Serial.println(val);
  if(val>1000)
  {
    digitalWrite(led1,1);
    digitalWrite(led3,1);
    digitalWrite(led5,1);
    digitalWrite(led2,0);
    digitalWrite(led4,0);
    
  }
  if()
  {
    digitalWrite(led1,0);
    digitalWrite(led3,0);
    digitalWrite(led5,0);
    digitalWrite(led2,1);
    digitalWrite(led4,1);
    
  }
   if()
  {
    digitalWrite(led1,1);
    digitalWrite(led3,1);
    digitalWrite(led5,1);
    digitalWrite(led2,0);
    digitalWrite(led4,0);
    
  }
   if()
  {
    digitalWrite(led1,1);
    digitalWrite(led3,1);
    digitalWrite(led5,1);
    digitalWrite(led2,0);
    digitalWrite(led4,0);
    
  }
   if()
  {
    digitalWrite(led1,1);
    digitalWrite(led3,1);
    digitalWrite(led5,1);
    digitalWrite(led2,0);
    digitalWrite(led4,0);
    
  }
   if()
  {
    digitalWrite(led1,1);
    digitalWrite(led3,1);
    digitalWrite(led5,1);
    digitalWrite(led2,0);
    digitalWrite(led4,0);
    
  }
}
