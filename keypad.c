#include "keypad.h"


void init_keypad()
{
    PINSEL0 = 0;
    // PINSEL2 = 0;

    IO0DIR = 0x000003FF;
    IO1DIR = 0x00780000;
}


/**
    TODO make this work right
*/
char wait_and_get_key()
{
    while (true)
    {
        IO1CLR |= (1 << 19); // "row 1 low"?
        IO1SET |= (1 << 20) | (1 << 21) | (1 << 22); // "rest 1"?

        if (!get_pin_value_1(16)) {
            while (!get_pin_value_1(16)); // don't return until key is released
            return '1';
        }
        if (!get_pin_value_1(17)) {
            while (!get_pin_value_1(17));
            return '2';
        }
        if (!get_pin_value_1(18)) {
            while (!get_pin_value_1(18));
            return '3';
        }

        IO1CLR |= (1 << 20);
        IO1SET |= (1 << 21) | (1 << 22) | (1 << 19);

        if (!get_pin_value_1(16)) {
            while (!get_pin_value_1(16));
            return '4';
        }
        if (!get_pin_value_1(17)) {
            while (!get_pin_value_1(17));
            return '5';
        }
        if (!get_pin_value_1(18)) {
            while (!get_pin_value_1(18));
            return '6';
        }

        IO1CLR |= (1 << 21);
        IO1SET |= (1 << 22) | (1 << 20) | (1 << 19);

        if (!get_pin_value_1(16)) {
            while (!get_pin_value_1(16));
            return '7';
        }
        if (!get_pin_value_1(17)) {
           while (!get_pin_value_1(17));
           return '8';
        }
        if (!get_pin_value_1(18)) {
            while (!get_pin_value_1(18));
            return '9';
        }

        IO1CLR |= (1 << 22);
        IO1SET |= (1 << 19) | (1 << 20) | (1 << 21);

        if (!get_pin_value_1(16)) {
            while (!get_pin_value_1(16));
            return '*';
        }
        if (!get_pin_value_1(17)) {
            while (!get_pin_value_1(17));
            return '0';
        }
        if (!get_pin_value_1(18)) {
            while (!get_pin_value_1(18));
            return '#';
        }
    }
}