int soil_moisture = A0, relay = 12;
void setup() {
  // put your setup code here, to run once:
  pinMode(soil_moisture, INPUT);
  pinMode(relay, OUTPUT);
  
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(soil_moisture);
  int y = map(x, 250, 1023, 100, 0);
  Serial.print(y); Serial.println(" %");
  if(x < 800 ){
    digitalWrite(relay, LOW);
  }
  else if(x > 800){
    digitalWrite(relay, HIGH);
  }
  delay(100); 

}
