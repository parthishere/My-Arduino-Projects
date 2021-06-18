int l1=13, l2=12, l3=11, l4=10, l5=9, sw=8, count=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(l5, OUTPUT);
  pinMode(sw, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i = digitalRead(sw);
  if(i == 1){
    delay(250);
    count++;
  }
  Serial.println(count);
}
