#include <xc.h>
#include "sevenSeg.h"

unsigned char lookup_table[10]={
    0b00111111,
    0b00111111,
    0b00111111,
    0b00111111,
    0b00111111,
    0b00111111,
    0b00111111,
    0b00111111,
    0b00111111,
    0b00111111
};
void initSevenSeg(){
    TRISAbits.RA3 = 0;
    TRISAbits.RA4 = 0;
    TRISAbits.RA5 = 0;
    
    TRISD = 0;
}


void updateDisplay(int value){
    LATA = LATD = 0;
    LATA = 1 << 3;
    int hundreds = (int) value/100;
    LATD = lookup_table[hundreds];
    __delay_ms(1);
    LATA = LATD = 0;
    LATA = 1 << 4;
    int tens = (int) (value%100)/10;
    LATD = lookup_table[tens];
    __delay_ms(1);
    LATA = LATD = 0;
    LATA = 1 << 5;
    LATD = lookup_table[value % 10];
    __delay_ms(1);    
}