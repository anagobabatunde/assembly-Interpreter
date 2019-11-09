/*
** ETNA PROJECT, 21/02/2019 by anago_b
** my_strcpy.c
** File description:
**      my_strcpy
*/

#include "../../lib/lib.h"

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

    return (dest);
}