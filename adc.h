/* 
 * File:   adc.h
 * Author: ceng33620232
 *
 * Created on June 2, 2023, 9:43 PM
 */

#ifndef ADC_H
#define	ADC_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    
void initADC();
int readADCResult();
int isADCConversionComplete();
void startADCConversion();


#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

