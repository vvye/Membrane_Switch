#include "gpio.h"


void GPIO_InitPin(int high, ...)
{
    volatile unsigned long *reg = (high ? &IO1DIR : &IO0DIR);

    int pin;
    va_list argp;
    va_start(argp, high);

    while ((pin = va_arg(argp, int)) != 0) {
        *reg |= (1 << pin);
    }

    va_end(argp);
}


int GPIO_GetPinValue(int high, int pin)
{
    return *(high ? &IO1PIN : &IO0PIN) & (1 << pin);
}


void GPIO_SetPinValue(int high, int status, ...)
{
    volatile unsigned long *reg = (high
    ? (status ? &IO1CLR : &IO1SET)
    : (status ? &IO0CLR : &IO0SET));

    int pin;
    va_list argp;
    va_start(argp, high);

    while ((pin = va_arg(argp, int)) != 0) {
        *reg |= (1 << pin);
    }

    va_end(argp);
}