int ir = A0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ir, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(ir);
  Serial.println(x);
  if(x<50){
    digitalWrite(13, 1);
  }
  else{
    digitalWrite(13, 0);
  }

}
