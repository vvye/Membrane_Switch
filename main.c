/**
    Keypad test
*/

#include "keypad.h"


int main()
{
    char c;

    init_keypad();
    while (true)
    {
        c = wait_and_get_key();
        debug_printf("%c", c);
    }
}