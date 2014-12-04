Robot and Sensors (ECE382_Lab07)
=================================



#Prelab Requirements: 

1. Paste the grading section in your lab notebook as the first page of this lab.

2. Test your sensors with a DMM. Ensure they are functional. What would good reference values be?

3. Consider how you'll setup the ADC10 subsystem. What are the registers you'll need to use? Which bits in those registers are important? What's the initialization sequence you'll need?

4. Consider the hardware interface. Which ADC10 channels will you use? Which pins correspond to those channels?

5. Consider the interface you'll create to your sensors. Will you block or use interrupts? Will you convert one sensor at a time or multiple?

6. Include whatever information from this lab you think will be useful in creating your program.



##1 Grading Sheet, shown below: 


##2 Test Sensors
Hooked it up to ground and power. 
DMM to ground and each of the three different sensors.  Placed objects certain distances away from the sensor to watch the voltage rise when it got closer to a wall. This worked for all three sensors.  

##3 ADC10 subsystem
This will be setup by wiring the sensors as three different inputs to the MSP430 via the ADC10 (analog to digital converter).  This is a type of chip inside the actual MSP430.  To start off, [Dr. Coulston's code](http://ecse.bd.psu.edu/cmpen352/lecture/code/lec36.c) will be used.  This code is only built for one sensor.  It will be altered appropriately to account for all three sensors on my robot.  


**Major registers** to use to interact with the MSP430 and the sensor: 

P1DIR //makes LED and output.
P1OUT//turns the LED on or off as desired.
ADC10CTL0// Turn off ADC subsystem
ADC10CTL1// Channel 4, ADC10CLK/4
ADC10AE0// Make P1.4 analog input for the sensor
ADC10SC//starts conversion from analog to digital
ADC10BUSY// determines if the chip is busy converting a signal
ADC10MEM//stores the 10 bit value coming in.

Their functions are described in the comments of the code included above.  

**Specific Pins**
As for the specific pins, I will use the empty ones available on port 1, namely 4,5,and 6.  
If for some reason this proves problematic, then I will change them later.  



**Pinout**
Overall, this was the same pinout as in lab06, except with the 3 wire inputs into the sensor.  The inputs will be for P1.4, P1.5, and P1.6 for left, center, and right, respectively.  There really is no need for an additional external hardware schematic.  If the design becomes more difficult later, I will add one in.  

