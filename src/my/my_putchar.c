/*
** ETNA PROJECT, 10/01/2019 by anago_b
** function for my_printf
** File description:
**     putchar function
*/

#include "../../lib/lib.h"

void my_putchar(char c)
{
    char debug;
    debug = write(1, &c, 1);
    debug++;
}
