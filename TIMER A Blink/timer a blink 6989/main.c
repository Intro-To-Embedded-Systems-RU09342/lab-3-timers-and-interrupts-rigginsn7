/* Author : Nicholas Riggins
 * Date: October 2019
 * Timer A blink lab3
 * board MSP430FR6989
 * Will blink led 1.0 and 9.7 but instead of using delay cycles
 * you utilize the processors timer
 *
 */
#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer


  P1DIR |= BIT0;  // set output direction
  P9DIR |= BIT7;

  P1OUT |= ~BIT0; //clears the LED
  P9OUT |= ~BIT7;

  PM5CTL0 &= ~LOCKLPM5;   // Disable the GPIO power-on default high-impedance mode
                          // to activate previously configured port settings

      TA0CCTL0 = CCIE; // Enable interrupt in compare mode
      TA0CTL = TASSEL_2 + MC_1 + ID_2; // SMCLK/4, Up
      TA0CCR0 = 250000/ 5; // 250000 / 10 = 25000, (10^6 [Hz] / 4) / (25000) = 10Hz

      TA1CCTL0 = CCIE; // Enable interrupt in compare mode
      TA1CTL = TASSEL_2 + MC_1 + ID_2; // SMCLK/4, Up
      TA1CCR0 = 250000/ 10; // 250000 / 10 = 25000, (10^6 [Hz] / 4) / (25000) = 10Hz


  __enable_interrupt();  // enables the interrupts

  __bis_SR_register(LPM0 + GIE);
}


#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER_A0(void)

{
  P1OUT ^= BIT0;  // P1.0 toggles

}

#pragma vector=TIMER1_A0_VECTOR
__interrupt void TIMER_A1(void)

{
  P9OUT ^= BIT7;  // P9.7 toggles
}
