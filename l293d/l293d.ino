int en1 = 13, in1 = 8, in2 = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(en1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in1, OUTPUT);
  digitalWrite(en1, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
}
