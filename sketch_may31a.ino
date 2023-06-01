#include <Servo.h> 
char state = 0;
// Declare the Servo pin 
int servoPin = 10; 
// Create a servo object 
Servo Servo1;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  Servo1.attach(servoPin); 

  int state = 0;
  Serial.begin(9600); // bluetooth
}

void loop() {
  if(Serial.available() > 0){ 
    state = Serial.read();
 }
 Serial.println(state);
 if(state == 'S'){
  //Stop
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
 }
 else if(state == 'F'){
  //forward
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
 }
 else if(state == 'B'){
  //backward
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
 }
 else if(state == 'L'){
  //right
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
 }
 else if(state == 'R'){
  //left
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
 }

 if(state == 'W'){
  //Motor

  // Make servo go to 0 degrees 
   Servo1.write(60); 
   delay(650); 
   // Make servo go to 90 degrees 
   Servo1.write(90); 
   delay(500); 
   // Make servo go to 180 degrees 
   Servo1.write(160); 
   delay(650); 
   Servo1.write(90); 
   delay (500);
 }
}