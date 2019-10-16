# TIMER A Blink
This part of the Lab I utilized the timer peripheral. In the previous lab I had multiple LEDs blinking on the board at different rates. In the last lab this was done using delay cycles. For this lab I used the built in timer peripheral on the board. I had to use 2 different timers so the LED would run at different rates.

## Processors Utilized
MSP430FR6989
MSP430G2553

## Dependencies
The only dependency is the library called MSP430.h. this is used for all TI MSP 430 processors.

## Differences in the Processors
For the MSP430FR6989 I had to disable the GPIO power on default high impedence mode. This allowed me to activate previously configured port settings. If you don't do this you can not use the on board LEDs. The only other difference in the code is the pin assignments specific to each board
