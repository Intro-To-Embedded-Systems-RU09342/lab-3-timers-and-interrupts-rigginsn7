
#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  P1DIR |= BIT0;                            // Set P1.0 to output direction
  P1IE |=  BIT1;                            // P1.3 interrupt enabled
  P1IES |= BIT1;                            // P1.3 Hi/lo edge
  P1REN |= BIT1;                            // Enable Pull Up on SW2 (P1.3)
  P1IFG &= ~BIT1;                           // P1.3 IFG cleared
                                            //BIT3 on Port 1 can be used as Switch2

  PM5CTL0 &= ~LOCKLPM5;

  __bis_SR_register(LPM4_bits + GIE);       // Enter LPM4 w/interrupt
}

// Port 1 interrupt service routine
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)

#endif
{
  P1OUT ^= BIT0;                            // P1.0 = toggle
  P1IFG &= ~BIT1;                           // P1.3 IFG cleared
}
