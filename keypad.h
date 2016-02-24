/**
    Keypad driver
*/


#include "gpio.h"

#include <targets/LPC2000.h>
#include <stdbool.h>


void init_keypad();

char wait_and_get_key();