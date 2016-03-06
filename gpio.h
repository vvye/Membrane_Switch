/**
    GPIO driver
*/


#include <targets/LPC2000.h>
#include <stdarg.h>


void GPIO_InitPin(int high, ...);

int GPIO_GetPinValue(int high, int pin);

void GPIO_SetPinValue(int high, int status, ...);