#include "../lib/lib.h"

int assert(elem_t **pile, int value)
{
    elem_t *tmp;
    tmp = *pile;
    if (tmp->value == value)
        return (0);
    return (1);
}