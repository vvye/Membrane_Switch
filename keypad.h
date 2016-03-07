/*
    The keypad driver.
*/


#include "Membrane_Switch/gpio.h"

#include <targets/LPC2000.h>
#include <stdbool.h>

/**
	The keypad pins.
	These are the pins corresponding to the rows and columns of the keypad. There is one pin corresponding to each row and to each column respectively. The configuration depends on which pins the keypad is connected to. This is implemented as an enum to make it easily changeable.
*/
typedef enum {
    COL_4 = 18,			/**< The pin for column 4. */
    COL_3 = COL_4 + 1,	/**< The pin for column 3. */
    COL_2,				/**< The pin for column 2. */
    COL_1,				/**< The pin for column 1. */
    ROW_4,				/**< The pin for row 4. */
    ROW_3,				/**< The pin for row 3. */
    ROW_2,				/**< The pin for row 2. */
    ROW_1				/**< The pin for row 1. */
} KEYPAD_PIN;


void Keypad_Init();

char Keypad_WaitAndGetKey();