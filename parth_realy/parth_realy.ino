int relay = 12;
void setup(){
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
}

void loop(){
  digitalWrite(relay, 1);
  delay(2000);
  digitalWrite(relay, 0);
  delay(2000);
}
