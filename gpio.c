/*
	The GPIO driver.
*/


#include "gpio.h"


/**
	Initializes one or more pins.
	This function sets the corresponding bits in the IODIR register.
	@param high Whether to target pins starting with 0 or with 1.
	@param ... The number(s) of the pin(s) to be initialized.
*/
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


/**
	Returns the value of a pin.
	The pin(s) need to be initialized using GPIO_InitPin first.
	@param high Whether to target a pin starting with 0 or with 1.
	@param pin The number of the pin.
	@return The value of the pin (0 or 1).
	@see GPIO_InitPin
*/
int GPIO_GetPinValue(int high, int pin)
{
    return *(high ? &IO1PIN : &IO0PIN) & (1 << pin);
}


/**
	Sets the value of one or more pins.
	The pin(s) need to be initialized using GPIO_InitPin first.
	@param high Whether to target a pin starting with 0 or with 1.
	@param status The value to set the pin(s) to (0 or 1).
	@param ... The number(s) of the pin(s) to be set.
	@see GPIO_InitPin
*/
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