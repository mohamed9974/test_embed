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

void __interrupt() ISR(){
    if (ADIF){
        result = readADCResult(); 
        ADIF = 0;
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    initADC();
    initSevenSeg();
    
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;
    
    
    while(1){        
        startADCConversion();  // Start the ADC conversion
        // Here you can do something with result, such as print it out
        updateDisplay(result);
    }
    return (EXIT_SUCCESS);
}

