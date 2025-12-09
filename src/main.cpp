#include <Arduino.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

const int frontTrigger = 2;
const int frontEcho = 3;
const int leftTrigger = 6;
const int leftEcho = 7;
const int rightTrigger = 4;
const int rightEcho = 5;
long frontDistance;
long leftDistance;
long rightDistance;
const int rightEnable = 9;
const int leftEnable = 11;
const int leftWheel1 = 13;
const int leftWheel2 = 10;
const int rightWheel1 = 12;
const int rightWheel2 = 8;

void setup() {

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

  Serial.begin(9600);

}

void loop() {

  // From Arduino Project Hub: the distance of an object in centimeters is the pulse duration * 0.0343/2 https://projecthub.arduino.cc/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-7cabe1
  digitalWrite(frontTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(frontTrigger, HIGH);
  delayMicroseconds(10); // https://projecthub.arduino.cc/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-7cabe1
  digitalWrite(frontTrigger, LOW);
  frontDistance = pulseIn(frontEcho, HIGH);

  digitalWrite(rightTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(rightTrigger, HIGH);
  delayMicroseconds(10);
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

    digitalWrite(rightEnable, HIGH);
    digitalWrite(leftEnable,HIGH);


    digitalWrite(leftWheel2, HIGH);
    digitalWrite(rightWheel2, HIGH);

      if(rightDistance < 1000){

      digitalWrite(leftWheel2, LOW);
      delay(1000);

      }
      

      else if(leftDistance < 1000){

      digitalWrite(rightWheel2, LOW);
      delay(1000);

      }

  }

  if(frontDistance < 2000){

   digitalWrite(leftWheel2, LOW);
   digitalWrite(rightWheel2, LOW);

   if(leftDistance < rightDistance){

    digitalWrite(leftWheel2, HIGH);
    delay(1000);
    digitalWrite(leftWheel2, LOW);

   }
   else if(leftDistance> rightDistance){

    digitalWrite(rightWheel2, HIGH);
    delay(1000);
    digitalWrite(rightWheel2,LOW);
   }
  }
  

}