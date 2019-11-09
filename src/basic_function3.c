/*
** ETNA PROJECT, 08/11/2019 by talamo_a
** basic_function3.c
** File description:
**      third and last part of fucntions
*/

#include "../lib/lib.h"

int assert(elem_t **pile, int value)
{
    elem_t *tmp;
    tmp = *pile;
    if (tmp->value == value)
        return (0);
    return (1);
}