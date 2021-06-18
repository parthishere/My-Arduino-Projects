int VRX=A0,VRY=A1,led1=13,led2=12,led3=11,led4=10,led5=9;

void setup(){
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(VRX,INPUT);
  pinMode(VRY,INPUT);
}

void loop(){
  int x = analogRead(VRX);
  int y = analogRead(VRY);
  //stable
if((x>490 && x<530) && (y>490 && y<530)){
    digitalWrite(led1, 1);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
    digitalWrite(led5, 0);
  }
  
  // forward
  if((x>950 && x<1023) && (y>450 && y<523)){
    digitalWrite(led1, 0);
    digitalWrite(led2, 1);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
    digitalWrite(led5, 0);
  }
  
  //backward
  if(x>0 && x<90 && y>450 && y<550){
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 1);
    digitalWrite(led4, 0);
    digitalWrite(led5, 0);
  }
  
  //left
  if(x>450 && x<550 && y>0 && y<100){
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 1);
    digitalWrite(led5, 0);
  }
  
  //right
  if(x>450 && x<530 && y>950 && y<1023){
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
    digitalWrite(led5, 1);
  }


}
