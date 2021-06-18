int vcc1 = 13, vcc2 = 12, en1 = 11, en2 = 10, m1in1 = 9, m1in2 = 8, m2in1 = 7, m2in2 = 6, irleft = A0, irright = A1,gnd = 5;
void setup() {
  // put your setup code here, to run once:
  pinMode(vcc1, OUTPUT);
  pinMode(vcc2, OUTPUT);
  pinMode(gnd, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(m1in1, OUTPUT);
  pinMode(m2in1, OUTPUT);
  pinMode(m1in2, OUTPUT);
  pinMode(m2in2, OUTPUT);
  pinMode(irleft, INPUT);
  pinMode(irright, INPUT);
  digitalWrite(vcc1, 1);
  digitalWrite(vcc2, 1);
  digitalWrite(gnd, 0);
  digitalWrite(en1, 1);
  digitalWrite(en2, 1);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int left = analogRead(irleft);
  int right = analogRead(irright);

  
  Serial.print("left: ");Serial.println(left);
  Serial.print("right: ");Serial.println(right);


////////// no ir in black strip
  if(left<50 && right<50){
    digitalWrite(m1in1, 1);
    digitalWrite(m1in2, 0);
    digitalWrite(m2in1, 1);
    digitalWrite(m2in2, 0);
  }

////////// right side in black strip
  else if(left<50 && right>100){
    digitalWrite(m1in1, 1);
    digitalWrite(m1in2, 0);
    digitalWrite(m2in1, 0);
    digitalWrite(m2in2, 0);
  }

///////// left side in black strip
  else if(left>100 && right<50){
    digitalWrite(m1in1, 0);
    digitalWrite(m1in2, 0);
    digitalWrite(m2in1, 1);
    digitalWrite(m2in2, 0);
  }

   
  
}
