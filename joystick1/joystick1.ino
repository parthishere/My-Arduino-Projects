
int vrx = A0, vry = A1, valx, valy;
void setup() {
  Serial.begin(9600);
  pinMode(vrx, INPUT);
  pinMode(vry, INPUT);
}

void loop() {
  valx = analogRead(vrx);
  valy = analogRead(vry);
  Serial.print(valx);
  Serial.print(" ");
  Serial.print(" ");
  Serial.print(" ");
  Serial.print(valy);
  Serial.println("");

}
