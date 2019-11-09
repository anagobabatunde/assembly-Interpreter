/*
** ETNA PROJECT, 21/02/2019 by anago_b
** my_strdup.c
** File description:
**      my_strdup
*/

#include "../../lib/lib.h"

char *my_strdup(char *str)
{
    char *s;
    s = malloc(my_strlen(str));

    if (s == 0) {
        return (0);
    }
    my_strcpy(s, str);
    return (s);
}