#include "gpio_driver.h"


void init_pin_0(int pin)
{
	IO0DIR |= (1 << pin);
}

void init_pin_1(int pin)
{
	IO1DIR |= (1 << pin);
}

int get_pin_value(int pin)
{
	return (IO0PIN & (1 << pin));
}

void set_pin_value(int pin, int status)
{
	if (status) {
		IO0CLR |= (1 << pin);
	} else {
		IO0SET |= (1 << pin);
	}
}