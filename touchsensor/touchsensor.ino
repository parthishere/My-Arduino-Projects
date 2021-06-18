int touch = 2;
void setup() {
  // put your setup code here, to run once:
  pinMode(touch, INPUT);
  digitalWrite(3, 1);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = digitalRead(touch);
  Serial.println(val);
  if(val == 1){
    digitalWrite(13, 1);
  }
  else{
    digitalWrite(13, 0);
  }
}
