int relay = 12;
void setup(){
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
}

void loop(){
 if(Serial.available()){
  char x = Serial.read();

  if(x == 'o'){
    digitalWrite(relay, 1);
    
  }

  else{
    digitalWrite(relay, 0);
  }
 }

 
}
