

int flag1=0,flag2=0,flag3=0,flag4=0,flag5=0;
int led1=13,led2=12,led3=11,led4=10,led5=9;
char x;




void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
      x = Serial.read();


      if(x=='a'){
         if(flag1==0){
           digitalWrite(led1, 1);
           flag1 =1;
         }
         else if(flag1==1){
          digitalWrite(led1,0);
          flag1 = 0;
         }
        }
        

        
        else if(x=='b'){
          if(flag2==0){
             digitalWrite(led2, 1);
             flag2 = 1;
          }
          else if(flag2==1){
            digitalWrite(led2, 0);
            flag2 = 0;
          }
         }
        

        
        if(x=='c'){
          if(flag3==0){
             digitalWrite(led3, 1);
             flag3 = 1;
          }
          else if(flag3==1){
            digitalWrite(led3, 0);
            flag3 = 0;
          }
        }
        

        
        if(x=='d'){
          if(flag4==0){
            digitalWrite(led4, 1);
            flag4 = 1;
          }
          else if(flag4==1){
            digitalWrite(led4, 0);
            flag4 = 0;
          }
        }
       
        
        if(x=='e'){
          if(flag5==0){
            digitalWrite(led5, 1);
            flag5 = 1;
          }
          else if(flag5==1){
            digitalWrite(led5, 0);
            flag5 = 0;
          }
        }
      
      
     }
  
  
        
       

}
