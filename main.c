/* 
 * File:   main.c
 * Author: ceng33620232
 *
 * Created on June 2, 2023, 8:59 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "adc.h"
#include "sevenSeg.h"
int result=0;

void __interrupt(high_priority) high_isr(){
    if (ADIF){
        result = readADChannel();
        ADIF = 0;
    }

}

void __interrupt(low_priority) low_isr(){
 
}
/*
 * 
 */
int main(int argc, char** argv) {
    initADC();
    initSevenSeg();
    
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;
    RCONbits.IPEN = 1;
    
    
    while(1){        
        startADCConversion();  // Start the ADC conversion
        while(!isADCConversionComplete());  // Wait for the conversion to complete
        result = readADCResult();  // Read the result
        // Here you can do something with result, such as print it out
        updateDisplay(result);
    }
    return (EXIT_SUCCESS);
}

