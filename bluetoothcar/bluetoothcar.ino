//int m1in_1 = 13, m1in_2=12, m2in_1=11, m2in_2=10, en1 = 7, en2 = 8, bluetooth_vcc = 7;
int x;
void setup() {
  // put your setup code here, to run once:
//  pinMode(m1in_1, OUTPUT);
//  pinMode(m1in_2, OUTPUT);
//  pinMode(m2in_1, OUTPUT);
//  pinMode(m2in_2, OUTPUT);
//  pinMode(bluetooth_vcc, OUTPUT);
//  digitalWrite(en1, 1);
//  digitalWrite(en2, 1);
//  digitalWrite(bluetooth_vcc, 1);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    x = Serial.read();
    Serial.println(x);
   
  }

//    if(x == '0'){
//      digitalWrite(m1in_1, 1);
//      digitalWrite(m1in_2, 1);
//      digitalWrite(m2in_1, 1);
//      digitalWrite(m2in_2, 1);
//      Serial.println("stable");
//    }
//    // forward
//    else if(x == '1'){
//      digitalWrite(m1in_1, 1);
//      digitalWrite(m1in_2, 0);
//      digitalWrite(m2in_1, 1);
//      digitalWrite(m2in_2, 0);
//      Serial.println("forward");
//    }
//    // b ackward
//    else if(x == '2'){
//      digitalWrite(m1in_1, 0);
//      digitalWrite(m1in_2, 1);
//      digitalWrite(m2in_1, 0);
//      digitalWrite(m2in_2, 1);
//      Serial.println("backward");
//    }
//    // right
//    else if(x == '3'){
//      digitalWrite(m1in_1, 1);
//      digitalWrite(m1in_2, 0);
//      digitalWrite(m2in_1, 0);
//      digitalWrite(m2in_2, 1);
//      Serial.println("right");
//    }
//    // left
//    else if(x == '4'){
//      digitalWrite(m1in_1, 0);
//      digitalWrite(m1in_2, 1);
//      digitalWrite(m2in_1, 1);
//      digitalWrite(m2in_2, 0);
//      Serial.println("left");
//    }
}
