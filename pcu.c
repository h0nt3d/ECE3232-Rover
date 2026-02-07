#include <xc.h>
#include "init.h"

volatile uint8_t get_pcu_info[6] = {0xFE, 0x19, 0x01, 0x04, 0x00, 0x00};

void send_get_pcu_info()
{
    for (int i = 0; i < 6; i++) {
        TX1REG = get_pcu_info[i];
        while (!TX1STAbits.TRMT) {} // wait until register is empty
    }
}


volatile uint8_t rxCount = 0;
volatile uint8_t rxDone = 0;

volatile uint8_t get_pcu_info_buf[12];


void __interrupt() ISR() 
{
    if (IOCAFbits.IOCAF5 == 1) {
        
        rxCount = 0;
        rxDone = 0;
        
        send_get_pcu_info();
        IOCAFbits.IOCAF5 = 0;  // Clear IOC flag
    } 
    
    if (PIE3bits.RCIE && PIR3bits.RCIF)
    {
        // handle overrun
        if (RC1STAbits.OERR)
        {
            RC1STAbits.CREN = 0;
            RC1STAbits.CREN = 1;
        }

        uint8_t b = RC1REG;    // reading clears RCIF

        if (!rxDone && rxCount < 12)
        {
            get_pcu_info[rxCount++] = b;
            if (rxCount == 12) rxDone = 1;
        }
    }
}