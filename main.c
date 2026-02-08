#include "config.h"
#include "init.h"

void main() 
{    
    initialize();
    while (1) {
        
        rxCount = 0;
        rxDone = 0;
        
        send_get_flySky_info();
        while (!rxDone) {}
    }
}
