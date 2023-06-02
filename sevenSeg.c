#include <xc.h>
#include "sevenSeg.h"

unsigned char lookup_table[10] = {
    0b00111111,  // 0
    0b00000110,  // 1
    0b01011011,  // 2
    0b01001111,  // 3
    0b01100110,  // 4
    0b01101101,  // 5
    0b01111101,  // 6
    0b00000111,  // 7
    0b01111111,  // 8
    0b01101111   // 9
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
