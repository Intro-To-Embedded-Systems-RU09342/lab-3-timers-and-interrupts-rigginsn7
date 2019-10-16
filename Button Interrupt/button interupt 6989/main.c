/* Author : Nicholas Riggins
 * Date: October 2019
 * Button Interrupt lab3
 * board MSP430FR6989
 * Will blink led 1.0 but instead of running it on a loop
 * it will wait till the button is pressed to act
 *
 */
#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  P1DIR |= BIT0;                            // Set P1.0 to output direction
  P1IE |=  BIT1;                            // P1.1 interrupt enabled
  P1IES |= BIT1;                            // P1.1 Hi/lo edge
  P1REN |= BIT1;                            // Enable Pull Up on SW2 (P1.1)
  P1IFG &= ~BIT1;                           // P1.1 IFG cleared
                                            //BIT1 on Port 1 can be used as Switch2

  PM5CTL0 &= ~LOCKLPM5;                     // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

  __bis_SR_register(LPM4_bits + GIE);       // Enter LPM4 w/interrupt
}

// Port 1 interrupt service routine
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)

#endif
{
  P1OUT ^= BIT0;                            // P1.0 = toggle
  P1IFG &= ~BIT1;                           // P1.1 IFG cleared
}
