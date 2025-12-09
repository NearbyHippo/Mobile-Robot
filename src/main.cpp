#include <Arduino.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

// Define pins to control ultrasonic sensors

const int frontTrigger = 2;
const int frontEcho = 3;
const int leftTrigger = 6;
const int leftEcho = 7;
const int rightTrigger = 4;
const int rightEcho = 5;
// These variables will store the output from the ultrasonic sensors
long frontDistance;
long leftDistance;
long rightDistance;

// Define pins to control motors
const int rightEnable = 9;
const int leftEnable = 11;
const int leftWheel1 = 13;
const int leftWheel2 = 10;
const int rightWheel1 = 12;
const int rightWheel2 = 8;

void setup() {

    // Set pin behaviors

  pinMode(frontTrigger, OUTPUT);
  pinMode(frontEcho, INPUT);
  pinMode(leftTrigger, OUTPUT);
  pinMode(leftEcho, INPUT);
  pinMode(rightTrigger, OUTPUT);
  pinMode(rightEcho, INPUT);
  pinMode(rightEnable, OUTPUT);
  pinMode(leftEnable, OUTPUT);
  pinMode(leftWheel1, OUTPUT);
  pinMode(leftWheel2, OUTPUT);
  pinMode(rightWheel1, OUTPUT);
  pinMode(rightWheel2, OUTPUT);

    // Serial monitor for debugging

  Serial.begin(9600);

}

void loop() {

  // From Arduino Project Hub: the distance of an object in centimeters is the pulse duration * 0.0343/2 https://projecthub.arduino.cc/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-7cabe1
  digitalWrite(frontTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(frontTrigger, HIGH);// tells front sensor to send a pulse
  delayMicroseconds(10); // https://projecthub.arduino.cc/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-7cabe1
  digitalWrite(frontTrigger, LOW);
  frontDistance = pulseIn(frontEcho, HIGH);// gets distance from pulse

  digitalWrite(rightTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(rightTrigger, HIGH);
  delayMicroseconds(10);// allows for soundwaves to travel
  digitalWrite(rightTrigger, LOW);
  rightDistance = pulseIn(rightEcho, HIGH);

  digitalWrite(leftTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(leftTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(leftTrigger, LOW);
  leftDistance = pulseIn(leftEcho, HIGH);

  Serial.println(frontDistance);
  Serial.println(leftDistance);
  Serial.println(rightDistance);

  if(frontDistance > 2000){

    digitalWrite(rightEnable, HIGH); // enable pins are left high allowing for motor control
    digitalWrite(leftEnable,HIGH);


    digitalWrite(leftWheel2, HIGH); // if there are no objects in the car's immediate vicinity it will drive forward
    digitalWrite(rightWheel2, HIGH);

      if(rightDistance < 1000){

      digitalWrite(leftWheel2, LOW); // if there is an object to the car's right it turns left by stopping the left wheel briefly, then continues forward
      delay(1000);

      }
      

      else if(leftDistance < 1000){

      digitalWrite(rightWheel2, LOW);// if there is an object to the car's left it turns right by stopping the right wheel briefly, then continues forward
      delay(1000);

      }

  }

  if(frontDistance < 2000){

   digitalWrite(leftWheel2, LOW); // if there is an object in front of the car it stops
   digitalWrite(rightWheel2, LOW);

   if(leftDistance < rightDistance){ // the car decides which way to go

    digitalWrite(leftWheel2, HIGH);// if there is an object closer to the left it will go right
    delay(1000);
    digitalWrite(leftWheel2, LOW);

   }
   else if(leftDistance> rightDistance){// if there is an object closer to the right it will go left

    digitalWrite(rightWheel2, HIGH);
    delay(1000);
    digitalWrite(rightWheel2,LOW);
   }
  }
  

}
