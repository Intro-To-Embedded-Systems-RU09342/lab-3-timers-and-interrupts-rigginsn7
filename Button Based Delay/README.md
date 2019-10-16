# Button Based Delay
In this part of the lab I combined what I learn from Part 1 and 2. The goal was too have the delay in the timer equal the amount of time the button was pressed down for. So if the button was pressed down for 2 seconds then the delay between the blinks would be 2 seconds. 
## Processors Utilized 
MSP430FR6989
MSP430G2553

## Dependencies
The only dependency is the library called MSP430.h. this is used for all TI MSP 430 processors.

## Differenece in the Processors
For the MSP430FR6989 I had to disable the GPIO power on default high impedence mode. This allowed me to activate previously configured port settings. If you don't do this you can not use the on board LEDs. The only other difference in the code is the pin assignments specific to each board
