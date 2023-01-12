#define M1 7
#define M2 6
#define M3 3
#define M4 2

const int echoPin=4;
const int pingPin=5;

#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 2,1,0,4,5,6,7,3,POSITIVE);

void setup() {
   pinMode(M1,OUTPUT); 
   pinMode(M2,OUTPUT);
   pinMode(M3,OUTPUT); 
   pinMode(M4,OUTPUT);
   
   lcd.begin(16,2);
   //lcd.backlight();
  
   Serial.begin(9600);
   pinMode(pingPin,OUTPUT);
   pinMode(echoPin,INPUT);
}

void loop(){
    loop1();
    loop2();
    loop3();
  }

void loop1() {
   digitalWrite(M1,HIGH) ;
   digitalWrite(M2,LOW) ;
   digitalWrite(M1,LOW) ;
   digitalWrite(M2,HIGH) ;

   digitalWrite(M3,HIGH) ;
   digitalWrite(M4,LOW) ;
   digitalWrite(M3,LOW) ;
   digitalWrite(M4,HIGH) ;
}

void loop2(){
   int pirState=digitalRead(A1);
   lcd.setCursor(0,0);
   lcd.print("HELLO");
   if (pirState==LOW){
   lcd.setCursor(0,1);
   lcd.print("No human Detected");
   delay(500);
   lcd.clear();
  }
   else if (pirState==HIGH){
    lcd.setCursor(0,1);
    lcd.print("Human detected");
    delay(500);
    lcd.clear();
   }   
}

void loop3(){
  long duration, inches, cm;
  
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(pingPin, LOW);
  
  duration = pulseIn(echoPin, HIGH); // using pulsin function to determine total time
  inches = microsecondsToInches(duration); // calling method
  cm = microsecondsToCentimeters(duration); // calling method
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(100);
}


long microsecondsToInches(long microseconds){ // method to covert microsec to inches 
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds){ // method to covert microsec to centimeters
  return microseconds / 29 / 2;
}
