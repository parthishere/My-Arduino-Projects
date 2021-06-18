int in1 = 13, in2 = 12, in3 = 11, in4 = 10, en1 = 9, en2 = 8, jx = A0, jy = A1, vcc=7;
void setup() {
  // put your setup code here, to run once:
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(vcc, OUTPUT);
  pinMode(jx, INPUT);
  pinMode(jy, INPUT);
  digitalWrite(en1, 1);
  digitalWrite(en2, 1);
  digitalWrite(vcc, 1);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(jx);
  int y = analogRead(jy);

  Serial.print(x); Serial.print("   "); Serial.print(y);
  Serial.println(" ");

  
// stable
  if(x>500 && x<520 && y>460 && y<480){
    digitalWrite(in1, 1);
    digitalWrite(in2, 1);
    digitalWrite(in3, 1);
    digitalWrite(in4, 1);
  }


// forward
  if(x>1000 && x<1023 && y>460 && y<480){
    digitalWrite(in1, 1);
    digitalWrite(in2, 0);
    digitalWrite(in3, 1);
    digitalWrite(in4, 0);
  }




// backward
  if(x>=0 && x<15 && y>460 && y<480){
    digitalWrite(in1, 0);
    digitalWrite(in2, 1);
    digitalWrite(in3, 0);
    digitalWrite(in4, 1);
  }




// right
  if(x>500 && x<520 && y>1000 && y<=1023){
    digitalWrite(in1, 1);
    digitalWrite(in2, 0);
    digitalWrite(in3, 0);
    digitalWrite(in4, 1);
  }



// left
  if(x>500 && x<520 && y>=0 && y<10){
    digitalWrite(in1, 0);
    digitalWrite(in2, 1);
    digitalWrite(in3, 1);
    digitalWrite(in4, 0);
  }

}
