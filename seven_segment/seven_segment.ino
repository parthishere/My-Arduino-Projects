int a = 13, b = 12, c = 11, d = 10, e = 9, f = 8, g = 7, h = 6, x=0; 
void setup() {
  // put your setup code here, to run once:
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(h, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  x = Serial.read();


  switch(x){


    case '1':
    
    ////////////////// 1
    digitalWrite(a, 1);
    digitalWrite(b, 1);
    digitalWrite(c, 0);
    digitalWrite(d, 1);
    digitalWrite(e, 1);
    digitalWrite(f, 0);
    digitalWrite(g, 1);
    digitalWrite(h, 1);
    delay(500);
    break;



    case '2':
      
    ////////////////// 2
      digitalWrite(a, 0);
      digitalWrite(b, 1);
      digitalWrite(c, 0);
      digitalWrite(d, 0);
      digitalWrite(e, 0);
      digitalWrite(f, 1);
      digitalWrite(g, 0);
      digitalWrite(h, 1);
      delay(500);
      break;

     case '3':
     ////////////////// 3
    
      digitalWrite(a, 0);
      digitalWrite(b, 1);
      digitalWrite(c, 0);
      digitalWrite(d, 0);
      digitalWrite(e, 1);
      digitalWrite(f, 0);
      digitalWrite(g, 0);
      digitalWrite(h, 1);
      delay(500);
      break;

      case '4':
      ////////////////// 4
      digitalWrite(a, 1);
      digitalWrite(b, 0);
      digitalWrite(c, 0);
      digitalWrite(d, 0);
      digitalWrite(e, 1);
      digitalWrite(f, 0);
      digitalWrite(g, 1);
      digitalWrite(h, 1);
      delay(500);
      break;


      case '5':
      
      ////////////////// 5
        digitalWrite(a, 0);
        digitalWrite(b, 0);
        digitalWrite(c, 1);
        digitalWrite(d, 0);
        digitalWrite(e, 1);
        digitalWrite(f, 0);
        digitalWrite(g, 0);
        digitalWrite(h, 1);
        delay(500);


        case '6':
        ////////////////// 6
        digitalWrite(a, 0);
        digitalWrite(b, 0);
        digitalWrite(c, 1);
        digitalWrite(d, 0);
        digitalWrite(e, 0);
        digitalWrite(f, 0);
        digitalWrite(g, 0);
        digitalWrite(h, 0);
        delay(500);
        break;

        case '7':
        
        ////////////////// 7
          digitalWrite(a, 0);
          digitalWrite(b, 1);
          digitalWrite(c, 0);
          digitalWrite(d, 1);
          digitalWrite(e, 1);
          digitalWrite(f, 0);
          digitalWrite(g, 1);
          digitalWrite(h, 1);
          delay(500);
          break;

         case '8':
         ////////////////// 8
          digitalWrite(a, 0);
          digitalWrite(b, 0);
          digitalWrite(c, 0);
          digitalWrite(d, 0);
          digitalWrite(e, 0);
          digitalWrite(f, 0);
          digitalWrite(g, 0);
          digitalWrite(h, 1);
          delay(500);
          break;

         case '9':
                   
          ////////////////// 9
            digitalWrite(a, 0);
            digitalWrite(b, 0);
            digitalWrite(c, 0);
            digitalWrite(d, 0);
            digitalWrite(e, 1);
            digitalWrite(f, 0);
            digitalWrite(g, 0);
            digitalWrite(h, 1);
            delay(500);
            break;

           case '0':
           
            ////////////////// 0
              digitalWrite(a, 0);
              digitalWrite(b, 0);
              digitalWrite(c, 0);
              digitalWrite(d, 1);
              digitalWrite(e, 0);
              digitalWrite(f, 0);
              digitalWrite(g, 0);
              digitalWrite(h, 1);
              delay(500);
              break;

    
  }





  












}
