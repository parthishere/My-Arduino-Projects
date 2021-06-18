int in1 = 13, in2 = 12, in3 = 11, in4 = 9, en1 = 8, en2 = 7, trig = 6, echo = 5, duration, distance;
void setup() {
  // put your setup code here, to run once:
   pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(en1, 1);
  digitalWrite(en2, 1);
  
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, 1);
  delayMicroseconds(10);
  digitalWrite(trig, 0);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 29.1;
  if(distance<0){
    distance = -1*distance;
  }
  Serial.println(distance);


  if(distance >= 20){
    digitalWrite(in1, 1);
    digitalWrite(in2, 0);
    digitalWrite(in3, 1);
    digitalWrite(in4, 0);
  }

  else if(distance < 20){
    digitalWrite(in1, 0);
    digitalWrite(in2, 0);
    digitalWrite(in3, 0);
    digitalWrite(in4, 0);
  }

}
