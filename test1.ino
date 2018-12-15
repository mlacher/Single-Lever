/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.
9V ->>> 1900
 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 
const int analogInPin = A3;  
int sensorValue;
int i;
int i_case = 0;;
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);
} 
 
void loop() 
{ 
  sensorValue = analogRead(analogInPin);
 Serial.println(sensorValue);
if (sensorValue > 350){
  if (i_case ==0){
  for(pos = 75; pos >= 10; pos -= 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  i_case = 1;
  delay(500);
  }
}
else {
  if (i_case ==0){
    delay(200);}
  if (i_case ==1){
     for(pos = 10; pos<=75; pos+=1){                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);
    }
    i_case =0;
  }
}
  
}
