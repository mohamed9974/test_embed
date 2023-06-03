#include "timer.h"
#include <xc.h>
void initTimer0(unsigned char prescaler, unsigned char preloadedValue) {
  T0CONbits.TMR0ON = 0;       // Turn off Timer0
  T0CONbits.T08BIT = 1;       // Configure Timer0 for 8-bit mode
  T0CONbits.T0CS = 0;         // Select internal instruction cycle clock
  T0CONbits.PSA = 0;          // Prescaler is assigned to the Timer0 module
  T0CONbits.T0PS = prescaler; // Set prescaler value
  TMR0L = preloadedValue;     // Set preloaded value

  INTCONbits.TMR0IE = 1;  // Enable Timer0 interrupt
  INTCON2bits.TMR0IP = 1; // Set Timer0 interrupt to high priority
}

void initTimer1(unsigned char prescaler, unsigned int preloadedValue) {
  T1CONbits.TMR1ON = 0;         // Turn off Timer1
  T1CONbits.TMR1CS = 0;         // Select internal instruction cycle clock
  T1CONbits.T1CKPS = prescaler; // Set prescaler value
  TMR1 = preloadedValue;        // Set preloaded value

  PIE1bits.TMR1IE = 1; // Enable Timer1 interrupt
  IPR1bits.TMR1IP = 0; // Set Timer1 interrupt to low priority
}

void startTimer0(void) {
  T0CONbits.TMR0ON = 1; // Turn on Timer0
}

void stopTimer0(void) {
  T0CONbits.TMR0ON = 0; // Turn off Timer0
}

void startTimer1(void) {
  T1CONbits.TMR1ON = 1; // Turn on Timer1
}

void stopTimer1(void) {
  T1CONbits.TMR1ON = 0; // Turn off Timer1
}
