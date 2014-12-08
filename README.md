Robot and Sensors (ECE382_Lab07)
=================================


#Prelab Requirements: 

1. Paste the grading section in your lab notebook as the first page of this lab.

2. Test your sensors with a DMM. Ensure they are functional. What would good reference values be?

3. Consider how you'll setup the ADC10 subsystem. What are the registers you'll need to use? Which bits in those registers are important? What's the initialization sequence you'll need?

4. Consider the hardware interface. Which ADC10 channels will you use? Which pins correspond to those channels?

5. Consider the interface you'll create to your sensors. Will you block or use interrupts? Will you convert one sensor at a time or multiple?

6. Include whatever information from this lab you think will be useful in creating your program.



##1 Grading Sheet, shown at top: 


##2 Test Sensors
Hooked it up to ground and power. 
DMM to ground and each of the three different sensors.  Placed objects certain distances away from the sensor to watch the voltage rise when it got closer to a wall. This worked for all three sensors.  
As for reference values, I am not exactly sure.  I will like to find a value at which a wall is 8 inches away, record that voltage, and make that the critical voltage at which the car will response.  This is an idea length for turning.  Unfortunately I have not been able to do this because my robot has been moved...I did the basic test if the sensor's worked because Sabin Park temporarily gave me permission to use his robot.  I am sorry, I left it in locker 11 before I left for Japan, and when I came back I could not find it in any of the lockers.  

##3 ADC10 subsystem
This will be setup by wiring the sensors as three different inputs to the MSP430 via the ADC10 (analog to digital converter).  This is a type of chip inside the actual MSP430.  To start off, [Dr. Coulston's code](http://ecse.bd.psu.edu/cmpen352/lecture/code/lec36.c) will be used.  This code is only built for one sensor.  It will be altered appropriately to account for all three sensors on my robot.  


**Major registers** to use to interact with the MSP430 and the sensor: 

```
P1DIR //makes LED and output.
P1OUT//turns the LED on or off as desired.
ADC10CTL0// Turn off ADC subsystem
ADC10CTL1// Channel 4, ADC10CLK/4
ADC10AE0// Make P1.4 analog input for the sensor
ADC10SC//starts conversion from analog to digital
ADC10BUSY// determines if the chip is busy converting a signal
ADC10MEM//stores the 10 bit value coming in.
```

Their functions are described in the comments of the code included above.  

**Initialization Sequence**
The initialization sequence for one bit is included in Dr. Coulston's code.  The basic idea can be seen below in my general code skeleton for attaining distances:

```
stop ADC so we can set up
make port input
set the appropriate inputs for the left, center, and right sensors


//repeat
start up ADC for left
enable conversion for left
start conversion for left
wait while it finishes left
attain distance from left 

start up ADC for center
enable conversion for center
start conversion for center
wait while it finishes center
attain distance from center 

start up ADC for right
enable conversion for right
start conversion for right
wait while it finishes right
attain distance from right 

compare distances for left, center, and right
use the comparisons to determine which LED turns on
or which direction the car will turn. 

loop back to "repeat"

```


##4 Hardward Interface

**Specific Pins**
As for the specific pins, I will use the empty ones available on port 1, namely 4,5,and 6.  
If for some reason this proves problematic, then I will change them later.  Anything more specific can be referenced in the [MSP430 Family User Guide](http://www.ece382.com/datasheets/msp430_msp430x2xx_family_users_guide.pdf)  I do no anticipate this being too difficult.  



**Pinout**
Overall, this was the same pinout as in lab06, except with the 3 wire inputs into the sensor.  The inputs will be for P1.4, P1.5, and P1.6 for left, center, and right, respectively.  There really is no need for an additional external hardware schematic.  If the design becomes more difficult later, I will add one in.  


##5 Block/Interrupt

I plan on using block, as in my code above for attaining distances.  Variables within the while loop will be set each time we walk through the while loop and the distances change, and these variables will be changed to turn the light on or off when needed.  Interrupts will not be used, as the distances will be checked periodically.  That way I do not have to deal with the priority of interrupts and such.  Simplicity is the ultimate sophistication (Da Vinci).  

If nothing is done with the variables when they are compared, they will reset to the max distance before the next time.  

#Basic Functionality

Basic Functionality was achieved on 7 Dec 2014, a day which will not live in infamy.  

The video is posted on youTube [here](https://www.youtube.com/watch?v=Bm2mYJ4hcjk&feature=youtu.be)

#B Functionality
The library/folder for B Functionality can be seen [here](https://github.com/JohnTerragnoli/ECE382_Lab07/tree/master/1.%20Code/B%20Functionality).  

It includes the [main](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab07/master/1.%20Code/B%20Functionality/main.c) file, the [header](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab07/master/1.%20Code/B%20Functionality/header.h) file, and the [implementation](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab07/master/1.%20Code/B%20Functionality/Implementation.c) file.  The implementation file contains the ATD code in it, and they are reduced to simple commands, which are called in three lines in the main.c file. 

#A Functionality

The values for this have been measured and recorded.  The file can be seen [here](https://github.com/JohnTerragnoli/ECE382_Lab07/blob/master/3.%20Files/A%20Functionality/Sensor%20Characterization.xlsx).

Pictures of the spreadsheet are reproduced below.  

![alt tag](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab07/master/2.%20Photos/A%20Functionality/Data%20and%20Conversion%20Chart.PNG "Sensor Data")

![alt tag](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab07/master/2.%20Photos/A%20Functionality/Voltage%20Output.PNG "Voltage/distance curve")

Legend:
  blue = left sensor
  red = center sensor
  green = right sensor



#Documentation:
C2C Sabin Park told me that I needed to adjust the blinders on my IR sensors so that it was picking up things behind the sensor, or the top of my robot platform.  


#To do:

1. Add a picture of the pinout to get back the point on the pinout.  
2. 
