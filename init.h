#ifndef INIT_H
#define INIT_H

#include <stdint.h>

extern volatile uint8_t rxCount;
extern volatile uint8_t rxDone;

void initialize();
void send_get_flySky_info();



#endif