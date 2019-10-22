/*
** ETNA PROJECT, 10/01/2019 by anago_b
** function for my_printf
** File description:
**      flac spet1
*/

#include "../../lib/lib.h"

int flags_c(va_list list)
{
    char c = va_arg(list, int);

    my_putchar(c);
    return (1);
}

int flags_s(va_list list)
{
    char *str = va_arg(list, char *);

    my_putstr(str);
    return (my_strlen(str));
}

int flags_d(va_list list)
{
    int nbr = va_arg(list, int);

    my_putnbr(nbr);
    return (my_nbrlen(nbr));
}

int flags_i(va_list list)
{
    int nbr = va_arg(list, int);

    my_putnbr(nbr);
    return (my_nbrlen(nbr));
}
