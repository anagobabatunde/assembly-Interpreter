/*
** ETNA PROJECT, 26/09/2018 by anago_b
** my_putstr
** File description:
**      put str
*/

#include "../../lib/lib.h"

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}