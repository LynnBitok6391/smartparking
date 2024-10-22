# include <Servo.h>
# include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
Servo servo1;//name your objects
Servo servo2;

//pin declaration
int pushButton=10;
int led1=22;
int led2=24;
int led3 =26;
int led4=8;
int led5=9;
int led6=36;
int led7=34;
int IR1=48;
int IR2=46;
int IR3=32;
int IR4=28;
int trigpin1=3;
int echopin1=2;
int trigpin2=5;
int echopin2=4;
int trigpin3=7;
int echopin3=6;

//variable declaration
int distance1,distance2,distance3,duration;
int IR1state,IR2state,IR3state,IR4state;
int count=0;
int state,slot1,slot2,slot3,slots;
int Bstate;
int Pstate1=0, Pstate2=0, Pstate3=0 ,parkingState;
int Cstate1, Cstate2, Cstate3;
int lstate1,lstate2,lstate3,lstate4,Tstate;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//initializing serial communication giving band rate of 9600
  servo1.attach(52);//attaching to respective pin 
  servo2.attach(50);
 lcd.init();
 lcd.backlight();
 lcd.setCursor(0,0);
 lcd.print("GALAXY PARK       GALAXY PARK        GALAXY PARK  ");
 
 // initialization of pin as output/input
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  pinMode(led7,OUTPUT);
  pinMode(IR1,INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3,INPUT);
  pinMode(IR4, INPUT);
  pinMode(trigpin1,OUTPUT);
  pinMode(echopin1,INPUT);
  pinMode(trigpin2,OUTPUT);
  pinMode(echopin2,INPUT);
  pinMode(trigpin3,OUTPUT);
  pinMode(echopin3,INPUT);
  pinMode(pushButton,INPUT);
  //servo position that write when the program start 
  servo1.write(175);
  servo2.write(90);
 
}


void ultrasonic1(){ 
   // Clears the trigPin condition
  digitalWrite(trigpin1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigpin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin1, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echopin1, HIGH);
  // Calculating the distance
  distance1 = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  //Serial.print("Distance1: ");
  //Serial.print(distance1);
  //Serial.println(" cm");
  
  }
  void ultrasonic2(){
   // Clears the trigPin condition
  digitalWrite(trigpin2, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigpin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin2, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echopin2, HIGH);
  // Calculating the distance
  distance2 = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  //Serial.print("Distance2: ");
  //Serial.print(distance2);
  //Serial.println(" cm");
  
  }
    void ultrasonic3(){
   // Clears the trigPin condition
  digitalWrite(trigpin3, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigpin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin3, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echopin3, HIGH);
  // Calculating the distance
  distance3 = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  //Serial.print("Distance3: ");
  //Serial.print(distance3);
  //Serial.println(" cm");
  
    }

  
void IRstate(){
  IR1state=digitalRead(IR1);
  IR2state=digitalRead(IR2);
  IR3state=digitalRead(IR3);
  IR4state=digitalRead(IR4);
 Serial.print("IR1state=  ");
  Serial.println(IR1state);
  Serial.print("IR2state=   ");
  Serial.println(IR2state);
  Serial.print("IR3state=  ");
  Serial.println(IR3state);
  Serial.print("IR4state=   ");
  Serial.println(IR4state);

  
  
  }
  void entrance(){
 
     IR1state=digitalRead(IR1);
     Serial.print( "IR1state=");
     Serial.println( IR1state);
     IR3state=digitalRead(IR3);
    Serial.print( "IR3state=");
     Serial.println( IR3state);
    Serial.print( "lstate=");
          Serial.println( lstate1);
         Serial.print( "lstate2=");
         Serial.println( lstate2);
     
   if (IR1state == 0 && lstate1==0 ){
     for (int b=180;b >=90;b--){
      servo1.write(b);
      Serial.print(b);
      delay(5);
    
      }
    Serial.print("********");
      lstate1 = 1;
   }
   
        while( IR3state == 0){
        Serial.print("in while loop");
         lstate2 = 1;
          IR3state=digitalRead(IR3);
        }
 

  
   if (lstate1==1  && lstate2==1 && IR3state==1 ){  
     for (int b=90;b <=180;b++){
      servo1.write(b);
      //Serial.print(b);
      delay(5);
      }
      lstate1=0;
      lstate2=0;
   }
     
   }
      
    
    

    void exitt(){
     
     IR2state=digitalRead(IR2);
    // Serial.println( IR2state);
     IR4state=digitalRead(IR4);
     //Serial.println( IR4state);
    
       if (IR2state == 0 && lstate3==0){
           for (int b=90;b >=0;b--){
           servo2.write(b);
          // Serial.print(b);
           delay(15);}
          // Serial.print("'''''''");
           lstate3=1;
       }
  if (lstate3==1&&lstate4==0 ){
      digitalWrite(led6,LOW);
      analogWrite(led7,200);
      }    
     
   while(IR4state ==0 && lstate3==1){
    //Serial.print ("in while loop");
    lstate4=1;
    IR4state=digitalRead(IR4);
       }
 
       
  if (IR4state ==1 && lstate3 == 1 && lstate4 ==1){
      analogWrite(led6,200);
      analogWrite(led7,0);
    for (int b=0;b <=90;b++){
      servo2.write(b);
      //Serial.print(b);
      delay(15);
      }
   lstate3=0;
   lstate4=0;
   Tstate=0;
   parkingState=0;
  }
      count--;
      if (count < 0){
        count=0;        }
   



 
      
    
    }
    void Scheck(){
  ultrasonic1();
  ultrasonic2();
  ultrasonic3();
  if (distance1 <=8){
    digitalWrite(led1,LOW);
   // Serial.print("slot1 occupied");
    Cstate1=1;
  }
     if (distance1 >8){
    digitalWrite(led1,HIGH);
    //Serial.print("slot1 available");
    
    Cstate1=0;
     }
    if (distance2 <=8){
    digitalWrite(led2,LOW);
   // Serial.print("slot2 occupied");
    Cstate2=1;
    }
         if (distance2 >8){
    digitalWrite(led2,HIGH);
    //Serial.print("slot2 available");
    Cstate2=0;
         }
    if (distance3 <=8){
    digitalWrite(led3,LOW);
   // Serial.print("slot3 occupied");
    Cstate3=1;
    }
         if (distance3 >8){
    digitalWrite(led3,HIGH);
    //Serial.print("slot3 available");
    Cstate3=0;
    }}
    
    void ledd(){
  // function to bling led for parking full indicatio
  //analogWrite(led6,200);
   Scheck();
      if (Cstate1 == 1 && Cstate2 == 1 && Cstate3 == 1 ){
        analogWrite(led4,200);
        analogWrite(led5,200);
        delay(200);
        analogWrite(led4,0);
        analogWrite(led5,0);
        delay(200);
        }
  else{
    // when parking is not fully the two led to be high
        analogWrite(led4,200);
        analogWrite(led5,200);
    }
  }

     void park(){
      Scheck();
      if (Cstate1 == 0 || Cstate2 == 0 || Cstate3 ==0 ){
         entrance();
        }

        
      }

      void Button(){
       
      Bstate=digitalRead(pushButton);
      //Serial.print("button state= ");
      //Serial.println(Bstate);
      if (Bstate == 1){
        parkingState = 1;
        //Serial.print("parking state=");
        //Serial.println(parkingState);
      }
        while (parkingState == 1 && IR2state == 1){ 
                 IRstate();
                // Serial.print("IR2 state= ");
                // Serial.println(IR2state);
                 analogWrite(led6,200);
                 delay(200);
                 analogWrite(led6,0);
                 delay(200);
                 
          }
          if (parkingState == 1 && IR2state == 0){
             Tstate=1;
          }
     if (parkingState == 1 && Tstate ==1){
      exitt();
      }  
          
       
      
        }
void scrollText(String text, int delayTime) {
  // Set the cursor position to the second column and first row
  lcd.setCursor(0, 1);
  
  // Print the text to the second column of the LCD
  lcd.print(text);
  
  // Wait for a short period of time
  delay(delayTime);
  
  // Scroll the text to the left by one character
  lcd.setCursor(0, 1);
  lcd.scrollDisplayLeft();
}


    void lcddisplay(){
      Scheck();
      String slot1="";
      String slot2="";
      String slot3="";
      String slot4="";
      String text="";
      char myArray[24];
      if (Cstate1==0){
     slot1="slot1 Available";
        
        }
     if (Cstate1==1){
     slot1="slot1 allocated";
        
        }

      if (Cstate2==0){
slot2="slot2 Available"; 
        
      
        }        
    if (Cstate2==1){
     slot2="slot2 allocated";}    

      if (Cstate3==0){
slot3="slot3 available";
        }
   if (Cstate3==1){
     slot3="slot3 allocated"; }    
      if (Cstate1==1 && Cstate2==1&&Cstate3==1){
slot4="PARKING FULL"; 
        
        }
  text= slot1   +slot2   +slot3   +slot4;

text.toCharArray(myArray,24);
Serial.print("my array=");

  Serial.println (myArray[0]);
  Serial.println(text); 
  for (int i =0; i<=24;i++){
    lcd.setCursor(0,1);
     lcd.scrollDisplayLeft();
     lcd.print(text);
      park();
      Button();
      ledd();
     delay(500);
    }
      
       
  }
  
  

  
 
    
void autocontrol(){
 park();
  Button();
  ledd();
  lcddisplay();
  }     
       
   
    

void loop() {
  // put your main code here, to run repeatedly:

    lcddisplay();    
}


  
  
