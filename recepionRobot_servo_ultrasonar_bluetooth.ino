#include <Servo.h>

#include <SoftwareSerial.h>
SoftwareSerial blue (1,0);
int m=0;
float distance;
unsigned long x ;
int trg = 8 ;
float ech = 7 ;

//servo defenition 
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;

void setup() {
  // put your setup code here, to run once:
pinMode(8,OUTPUT);
pinMode(7,INPUT);
blue.begin(9600);

myservo1.attach(3);
myservo2.attach(5);
myservo3.attach(6);
myservo4.attach(9);
myservo5.attach(10);
myservo6.attach(11);

 myservo1.write(90);
  myservo2.write(90);
  myservo3.write(180);
  myservo4.write(90);
  myservo5.write(90);
  myservo6.write(180);  
}

void loop() {
  // put your main code here, to run repeatedly:
if (blue.available()){  
digitalWrite(8,LOW);
delay(500);
digitalWrite(8,HIGH);
delayMicroseconds(2);
digitalWrite(8,LOW);
  
x= pulseIn(7,HIGH);
distance= x*0.034/2; 
if ( distance <=70){
 m=m+1;
  delay(700); 
 if ( m == 3){
  blue.print(1);
  myservo1.write(45);
  myservo2.write(90);
  myservo3.write(90);
  myservo4.write(45);
  myservo5.write(90);
  myservo6.write(90);
 
  } 
  
}
else {
if(m!= 0){
  
  myservo1.write(90);
  myservo2.write(90);
  myservo3.write(180);
  myservo4.write(90);
  myservo5.write(90);
  myservo6.write(180);
    
  m=0;
   blue.print(0);
  
}
}
}

}
