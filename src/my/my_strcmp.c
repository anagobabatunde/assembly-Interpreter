/*
** ETNA PROJECT, 27/09/2018 by talamo_a
** my_strcmp.c
** File description:
**      d04ex01
*/

#include "../../lib/lib.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while ((s1[i] != '\0' || s2[i] != '\0' ) && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}
