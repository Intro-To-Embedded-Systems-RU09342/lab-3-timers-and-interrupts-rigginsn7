/* Author : Nicholas Riggins
 * Date: October 2019
 * Timer A blink lab3
 * board MSP430G2553
 * Will blink led 1.0 and 1.6 but instead of using delay cycles
 * you utilize the processors timer
 *
 */

#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  P1SEL &= ~(BIT0 + BIT6);                  // Select I/O direction for P1.0 and P1.6
  P1DIR |= (BIT0 + BIT6);                    // Set P1.0 and P1.6 to output direction
  P1OUT |= ~(BIT0 + BIT6);                   // Clears the LEDs off



      TA0CCTL0 = CCIE; // Enable interrupt in compare mode
      TA0CTL = TASSEL_2 + MC_1 + ID_2; // SMCLK/4, Up
      TA0CCR0 = 250000/ 5; // 250000 / 10 = 25000, (10^6 [Hz] / 4) / (25000) = 10Hz

      TA1CCTL0 = CCIE; // Enable interrupt in compare mode
      TA1CTL = TASSEL_2 + MC_1 + ID_2; // SMCLK/4, Up
      TA1CCR0 = 250000/ 10; // 250000 / 10 = 25000, (10^6 [Hz] / 4) / (25000) = 10Hz


  __enable_interrupt(); // enables the interupts

  __bis_SR_register(LPM0 + GIE);
}


#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER_A0(void)

{
  P1OUT ^= BIT0;                     // P1.0 toggle

}

#pragma vector=TIMER1_A0_VECTOR
__interrupt void TIMER_A1(void)

{
  P1OUT ^= BIT6;                     // P1.6 toggle
}

