int X = A0, Y = A1, sw = 12, vcc2 = 11; 
void setup() {
  // put your setup code here, to run once:
  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  
  pinMode(sw, INPUT);
  pinMode(13, OUTPUT);
  pinMode(vcc2, OUTPUT);
  digitalWrite(vcc2, 1);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(X);
  int y = analogRead(Y);
  int val_sw = digitalRead(sw);
 

  if((x>500 && x<525 && y>505 && y<530) || val_sw==0){
    digitalWrite(13, 0);
  }
//////////// forward
  if((x>960 && x<=1023 && y>505 && y<530) || val_sw==1){
    digitalWrite(13, 1);
  }
/////////// backward
  if((x>=0 && x<20 && y>505 && y<535) || val_sw==1){
    digitalWrite(13, 1);
  }
/////////// left
  if((x>505 && x<535 && y>=0 && y<20) || val_sw==1){
    digitalWrite(13, 1);
  }
/////////// right
  if((x>505 && x<535 && y>970 && y<=1023) || val_sw==1){
    digitalWrite(13, 1);
  }

}
