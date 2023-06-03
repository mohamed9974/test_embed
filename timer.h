/*
 * File:   timer.h
 * Author: ceng33620232
 *
 * Created on June 3, 2023, 11:09 AM
 */

#ifndef TIMER_H
#define TIMER_H

#ifdef __cplusplus
extern "C" {
#endif

// Prototype function definitions
void initTimer0(unsigned char prescaler, unsigned char preloadedValue);
void initTimer1(unsigned char prescaler, unsigned int preloadedValue);
void startTimer0(void);
void stopTimer0(void);
void startTimer1(void);
void stopTimer1(void);

#ifdef __cplusplus
}
#endif

#endif /* TIMER_H */
