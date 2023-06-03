
#include "buttons.h"
#include <xc.h>
void initButtons(void) {
  TRISB = 0x0F; // Set RB0, RB1, RB2 and RB3 as inputs

  INTCON2bits.RBPU = 0; // Enable PORTB pull-ups
  INTCONbits.RBIE = 1;  // Enable PORTB change interrupt
  INTCON2bits.RBIP = 1; // Set PORTB interrupt to high priority
}
