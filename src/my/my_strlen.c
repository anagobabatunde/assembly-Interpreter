/*
** ETNA PROJECT, 26/09/2018 by anago_b
** my_strlen
** File description:
**      str len
*/

#include "../../lib/lib.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}