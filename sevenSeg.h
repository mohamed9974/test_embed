/* 
 * File:   sevenSeg.h
 * Author: ceng33620232
 *
 * Created on June 2, 2023, 9:46 PM
 */

#ifndef SEVENSEG_H
#define	SEVENSEG_H
#define _XTAL_FREQ 40000000L
#ifdef	__cplusplus
extern "C" {
#endif

    void initSevenSeg();
    void updateDisplay(int value);


#ifdef	__cplusplus
}
#endif

#endif	/* SEVENSEG_H */

