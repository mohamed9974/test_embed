#include <xc.h>
#include "adc.h"

void initADC(){
    TRISAbits.RA0 = 1;
    ADCON1bits.PCFG = 0b1110;
    
    ADCON0bits.CHS = 0 ;
    ADCON0bits.ADON = 1 ;
    ADCON2bits.ADFM = 1 ;
    ADCON2bits.ACQT = 2 ;
    ADCON2bits.ADCS = 6 ;
}

void startADCConversion(){
    ADCON0bits.GO = 1;
}

int isADCConversionComplete(){
    return !ADCON0bits.GO;
}

int readADCResult(){
    return (ADRESH << 8) | ADRESL;
}
