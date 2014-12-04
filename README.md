Robot and Sensors (ECE382_Lab07)
=================================



#Prelab Requiremenets: 

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
This will be setup by wiring the sensors as three different inputs to the MSP430.  
Registers to use: 

