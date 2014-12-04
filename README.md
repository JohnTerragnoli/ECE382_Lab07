Robot and Sensors (ECE382_Lab07)
=================================

| Item                   | Grade                                                                                                                   | Points | Out of | Date | Due     |
|------------------------|-------------------------------------------------------------------------------------------------------------------------|--------|--------|------|---------|
| Prelab                 | On-Time: 0 ---- Check Minus ---- Check ---- Check Plus                                                                  |        | 10     |      | BOC L37 |
| Required Functionality | On-Time ------------------------------------------------------------------ Late: 1Day ---- 2Days ---- 3Days ---- 4+Days |        | 40     |      | COB L38 |
| B Functionality        | On-Time ------------------------------------------------------------------ Late: 1Day ---- 2Days ---- 3Days ---- 4+Days |        | 10     |      | COB L38 |
| A Functionality        | On-Time ------------------------------------------------------------------ Late: 1Day ---- 2Days ---- 3Days ---- 4+Days |        | 10     |      | COB L38 |
| Use of Git / Github    | On-Time: 0 ---- Check Minus ---- Check ---- Check Plus ---- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days                |        | 10     |      | COB L40 |
| Code Style             | On-Time: 0 ---- Check Minus ---- Check ---- Check Plus ---- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days                |        | 10     |      | COB L40 |
| README                 | On-Time: 0 ---- Check Minus ---- Check ---- Check Plus ---- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days                |        | 10     |      | COB L40 |
| Total                  |                                                                                                                         |        | 100    |      |         |


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
If for some reason this proves problematic, then I will change them later.  



**Pinout**
Overall, this was the same pinout as in lab06, except with the 3 wire inputs into the sensor.  The inputs will be for P1.4, P1.5, and P1.6 for left, center, and right, respectively.  There really is no need for an additional external hardware schematic.  If the design becomes more difficult later, I will add one in.  


##5 Block/Interrupt

I plan on using block, as in my code above for attaining distances.  Variables within the while loop will be set each time we walk through the while loop and the distances change, and these variables will be changed to turn the light on or off when needed.  
