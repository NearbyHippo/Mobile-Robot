 

Mobile Robot
Stephen Foley
MAE 476
GitHub 

Introduction
The mobile robot is a mechatronic system that avoids obstacles in its environment. 
The mobile robot is controlled using an Arduino UNO board. 
The robot uses three ultrasonic sensors facing left, right, and forwards to detect objects around it. 
Based on the input from each sensor the robot decides which direction to travel to not crash. 
The robot is driven by two DC motors. Both motors are controlled using an L293D motor driver.
 
Hardware & Mechanical Components
•	ELEGOO UNO R3 Board
•	ATmega328P MCU
•	Wires
•	L293D motor driver
•	9V Battery
•	4X mini breadboards
•	Robot car chassis kit Robot Car Chassis Kit 
•	3X HC-SRO4 Ultrasonic Sensors
•	4X AA Batteries
Soldering station and basic tools required for assembly


Software
The robot’s software was developed in C++. The PlatformIO extension for VScode was also used.

Limitations
•	Sensor direction: The ultrasonic sensors onboard the robot point straight outwards. The robot cannot detect objects that are low to the ground.
This causes the robot to occasionally become caught on an object just below the sensor
•	The robot cannot tell when it is stuck: If an instance were to occur where the robot crashed into something, the robot would simply continue driving forward.
•	The robot does not go backwards. 
If the robot enters a very narrow area, it will crash because it will try to turn either left or right instead of backing out of the area leading to a crash.


References
www.cirkitdesigner.com
Robot Car Chassis Kit
https://projecthub.arduino.cc/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-7cabe1
