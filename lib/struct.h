/*
** ETNA PROJECT, 08/11/2019 by talamo_a
** struct.h
** File description:
**      my_printf struct
*/

#include "./lib.h"

typedef struct list {
    char c;
    int (*ptrf)(va_list);
} list_t;