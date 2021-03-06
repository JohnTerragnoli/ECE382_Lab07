README for how the Robot Senses Direction
==========================================

The purpose of this README is to organize the files which help the robot sense direction.  The three main files are located below:

1. [main.c](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab07/master/1.%20Code/B%20Functionality/main.c)  Calls the commands to sense the left, center, and right direction.  When an object is near in one of these directions, then either the left, both, or the right LED will turn on.  
2. [implementation.c](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab07/master/1.%20Code/B%20Functionality/Implementation.c) Contains the actual work to convert the sensor signal from analog to digital, as well as turn on the LEDs when a certain threshold is passed.  
3. [header.h](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab07/master/1.%20Code/B%20Functionality/header.h) Links the main.c and implementation.c file so they can interact and make the robot operate.  



