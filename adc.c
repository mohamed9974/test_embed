#include <xc.h>
#include "adc.h"


void initADC(){
    TRISAbits.RA0 = 1;
    ADCON1bits.PCFG = 0b1110;
    
    ADCON0bits.CHS = 0 ;
    ADCON0bits.ADON = 0 ;
    ADCON2bits.ADFM = 1 ;
    ADCON2bits.ACQT = 2 ;
    ADCON2bits.ADCS = 6 ;
   
    PIE1bits.ADIE = 1;

}

int readADChannel(){
    ADCON0bits.GO =1;
    return (ADRESH << 8) | ADRESL;
}


