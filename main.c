/*
 * File:   main.c
 * Author: ceng33620232
 *
 * Created on June 2, 2023, 8:59 PM
 */

#include "adc.h"
#include "sevenSeg.h"
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
int result = 0;

void __interrupt() ISR() {
  if (ADIF) {
    result = readADCResult();
    ADIF = 0;
  }
  if (PIR1bits.TMR1IF) {
    // Timer1 interrupt has occurred

    // Add your code here

    PIR1bits.TMR1IF = 0; // Clear the Timer1 interrupt flag
  }
  if (INTCONbits.TMR0IF) {
    // Timer0 interrupt has occurred

    // Add your code here

    INTCONbits.TMR0IF = 0; // Clear the Timer0 interrupt flag
  }
  if (INTCONbits.RBIF) {
    // PORTB change interrupt has occurred

    if (!PORTBbits.RB0) {
      // START/STOP button has been pressed

      // Add your code here
    } else if (!PORTBbits.RB1) {
      // RESET button has been pressed

      // Add your code here
    } else if (!PORTBbits.RB2) {
      // INCREASE button has been pressed

      // Add your code here
    } else if (!PORTBbits.RB3) {
      // DECREASE button has been pressed

      // Add your code here
    }

    INTCONbits.RBIF = 0; // Clear the PORTB change interrupt flag
  }
}

/*
 *
 */
int main(int argc, char **argv) {
  initADC();
  initSevenSeg();

  INTCONbits.PEIE = 1;
  INTCONbits.GIE = 1;

  while (1) {
    startADCConversion(); // Start the ADC conversion
    // Here you can do something with result, such as print it out
    updateDisplay(result);
  }
  return (EXIT_SUCCESS);
}
