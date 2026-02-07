/*
 * File:   main.c
 * Author: iyanu
 *
 * Created on January 21, 2026, 1:30 PM
 */


#include <xc.h>

void main(void)
{
    TRISAbits.TRISA0 = 0; // Set pin A0 to an output.
    ANSELAbits.ANSA0 = 0; // Set the pin to digital.
    
    TRISAbits.TRISA1 = 0; // Set pin A1 to an output.
    ANSELAbits.ANSA1 = 0; // Set the pin to digital.
    
    TRISAbits.TRISA2 = 0; // Set pin A2 to an output.
    ANSELAbits.ANSA2 = 0; // Set the pin to digital.
    
    TRISAbits.TRISA3 = 0; // Set pin A3 to an output.
    ANSELAbits.ANSA3 = 0; // Set the pin to digital.
    
    TRISAbits.TRISA5 = 1; // Set pin A5 to an input.
    ANSELAbits.ANSA5 = 0; // Set the pin to digital.
    
    while (1) {
        if (PORTAbits.RA5 == 1) {
            LATAbits.LATA0 = 0; // Set Pin A0 to 1.
            LATAbits.LATA1 = 0; // Set Pin A1 to 1.
            LATAbits.LATA2 = 0; // Set Pin A2 to 1.
            LATAbits.LATA3 = 0; // Set Pin A3 to 1.
        }
        else {
            LATAbits.LATA0 = 1; // Set Pin A0 to 0.
            LATAbits.LATA1 = 1; // Set Pin A1 to 0.
            LATAbits.LATA2 = 1; // Set Pin A2 to 0.
            LATAbits.LATA3 = 1; // Set Pin A3 to 0.
        }
    }
    
}
