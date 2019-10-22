/*
** ETNA PROJECT, 10/01/2019 by anago_b
** function for my_printf
** File description:
**     my_printf function
*/

#include "../../lib/lib.h"

int my_printf(const char *format, ...)
{
    va_list list;
    int length = 0;

    va_start(list, format);
    length = main_function(format, list);
    va_end(list);
    return (length);
}