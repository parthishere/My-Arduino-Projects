int led5 = 13, led4 = 12, led3 = 11, led2 = 10, led1 = 9, trig = 5, echo = 6, max_dis;
int flag;
void setup() {
  // put your setup code here, to run once:
  pinMode(led5, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, 0);
  delayMicroseconds(5);
  digitalWrite(trig, 1);
  delayMicroseconds(10);
  digitalWrite(trig, 0);

  int  duration = pulseIn(echo, HIGH);
  int  distance = (duration/2) /29.1;
  int timing = millis();
  if(timing <4000){
    flag = 1;
    max_dis = distance;
  }
  
 
  

      if (distance <20 && distance >16){
        digitalWrite(led5, 1);
        digitalWrite(led4, 0);
        digitalWrite(led3, 0);
        digitalWrite(led2, 0);
        digitalWrite(led1, 0);
      }

      else if (distance <16 && distance >12){
        digitalWrite(led5, 0);
        digitalWrite(led4, 1);
        digitalWrite(led3, 0);
        digitalWrite(led2, 0);
        digitalWrite(led1, 0);
      }


      else if (distance <12 && distance >8){
        digitalWrite(led5, 0);
        digitalWrite(led4, 0);
        digitalWrite(led3, 1);
        digitalWrite(led2, 0);
        digitalWrite(led1, 0);
      }


      else if (distance <8 && distance >5){
        digitalWrite(led5, 0);
        digitalWrite(led4, 0);
        digitalWrite(led3, 0);
        digitalWrite(led2, 1);
        digitalWrite(led1, 0);
      }


      else if (distance <5 && distance >0){
        digitalWrite(led5, 0);
        digitalWrite(led4, 0);
        digitalWrite(led3, 0);
        digitalWrite(led2, 0);
        digitalWrite(led1, 1);
      }
    
      int diff;
      if(timing > 4000){
        flag = 0;
        diff = max_dis - distance;
        Serial.println(diff);
      }
   
   distance = 0;
   
   } 


 
