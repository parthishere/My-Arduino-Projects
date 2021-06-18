int VRX=A0, VRY = A1, led = 13, valx, valy; 

void setup() {
 Serial.begin(9600);
 pinMode(VRX, INPUT);
 pinMode(VRY, INPUT);
 pinMode(led, OUTPUT);

}

void loop() {
  valx = analogRead(VRX);
  valy = analogRead(VRY);
 if(valx>500 && valx<550 && valy>500 && valy<550){
  digitalWrite(led, 0);
 }
 else{
  digitalWrite(led, 1);
 }

}
