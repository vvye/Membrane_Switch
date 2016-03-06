#include "keypad.h"


void Keypad_Init()
{
    PINSEL0 = 0;

    GPIO_InitPin(0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    GPIO_InitPin(1, ROW_1, ROW_2, ROW_3, ROW_4);
}


char Keypad_WaitAndGetKey()
{
    while (true) {

        // prepare for row 4
        GPIO_SetPinValue(1, 1, ROW_4);
        GPIO_SetPinValue(1, 0, ROW_1, ROW_2, ROW_3);

        // check keys in row 4
        if (!GPIO_GetPinValue(1, (COL_4))) {
            // don't return until key is released
            while (!GPIO_GetPinValue(1, (COL_4)));
            return 'D';
        }
        if (!GPIO_GetPinValue(1, (COL_3))) {
            while (!GPIO_GetPinValue(1, (COL_3)));
            return '#';
        }
        if (!GPIO_GetPinValue(1, (COL_2))) {
            while (!GPIO_GetPinValue(1, (COL_2)));
            return '0';
        }
        if (!GPIO_GetPinValue(1, (COL_1))) {
            while (!GPIO_GetPinValue(1, (COL_1)));
            return '*';
        }

        // prepare for row 3
        GPIO_SetPinValue(1, 1, ROW_3);
        GPIO_SetPinValue(1, 0, ROW_1, ROW_2, ROW_4);

        // check keys in row 3
        if (!GPIO_GetPinValue(1, (COL_4))) {
            while (!GPIO_GetPinValue(1, (COL_4)));
            return 'C';
        }
        if (!GPIO_GetPinValue(1, (COL_3))) {
            while (!GPIO_GetPinValue(1, (COL_3)));
            return '9';
        }
        if (!GPIO_GetPinValue(1, (COL_2))) {
            while (!GPIO_GetPinValue(1, (COL_2)));
            return '8';
        }
        if (!GPIO_GetPinValue(1, (COL_1))) {
            while (!GPIO_GetPinValue(1, (COL_1)));
            return '7';
        }

        // prepare for row 2
        GPIO_SetPinValue(1, 1, ROW_2);
        GPIO_SetPinValue(1, 0, ROW_1, ROW_3, ROW_4);

        // check keys in row 2
        if (!GPIO_GetPinValue(1, (COL_4))) {
            while (!GPIO_GetPinValue(1, (COL_4)));
            return 'B';
        }
        if (!GPIO_GetPinValue(1, (COL_3))) {
            while (!GPIO_GetPinValue(1, (COL_3)));
            return '6';
        }
        if (!GPIO_GetPinValue(1, (COL_2))) {
            while (!GPIO_GetPinValue(1, (COL_2)));
            return '5';
        }
        if (!GPIO_GetPinValue(1, (COL_1))) {
            while (!GPIO_GetPinValue(1, (COL_1)));
            return '4';
        }

        // prepare for row 1
        GPIO_SetPinValue(1, 1, ROW_1);
        GPIO_SetPinValue(1, 0, ROW_2, ROW_3, ROW_4);

        // check keys in row 1
        if (!GPIO_GetPinValue(1, (COL_4))) {
            while (!GPIO_GetPinValue(1, (COL_4)));
            return 'A';
        }
        if (!GPIO_GetPinValue(1, (COL_3))) {
            while (!GPIO_GetPinValue(1, (COL_3)));
            return '3';
        }
        if (!GPIO_GetPinValue(1, (COL_2))) {
            while (!GPIO_GetPinValue(1, (COL_2)));
            return '2';
        }
        if (!GPIO_GetPinValue(1, (COL_1))) {
            while (!GPIO_GetPinValue(1, (COL_1)));
            return '1';
        }
    }
}