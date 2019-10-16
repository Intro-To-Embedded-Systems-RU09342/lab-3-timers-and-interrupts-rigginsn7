# Button Interrupt
In the previous lab the button was utilized by putting the program in a continious loop that ran indefintly and is constantly checking if the button is being pressed and acting upon that. So for this lab I utilized the GPIO peripherial so instead of running a continious loop you use interrupts to enable and clear flags using pragma vectors to tell the compiler when the interrupt occurs. 

## Processors Utilized
MSP430FR6989
MSP430G2553

## Dependencies
The only dependency is the library called MSP430.h. this is used for all TI MSP 430 processors.

## Differences in the Processors
For the MSP430FR6989 I had to disable the GPIO power on default high impedence mode. This allowed me to activate previously configured port settings. If you don't do this you can not use the on board LEDs. The only other difference in the code is the pin assignments specific to each board
