int ldr = A0, en1 = 13, en2 = 12, vcc_l293d = 11, m1in1= 10, m1in2 = 9, m2in1 = 8, m2in2 = 7; 
void setup() {
  // put your setup code here, to run once:
  pinMode(ldr, INPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(vcc_l293d, OUTPUT);
  pinMode(m1in1, OUTPUT);
  pinMode(m1in2, OUTPUT);
  pinMode(m2in1, OUTPUT);
  pinMode(m2in2, OUTPUT);
  
  digitalWrite(en1, 1);
  digitalWrite(en2, 1);
  digitalWrite(vcc_l293d, 1);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(ldr);
  Serial.println(x);

  if(x> 300 && x<500){
    digitalWrite(m1in1, 1);
    digitalWrite(m1in2, 0);
    digitalWrite(m2in1, 1);
    digitalWrite(m2in2, 0);
  }

   else if(x > 500){
    digitalWrite(m1in1, 0);
    digitalWrite(m1in2, 0);
    digitalWrite(m2in1, 0);
    digitalWrite(m2in2, 0);
  }

}
