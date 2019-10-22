/*
** ETNA PROJECT, 10/01/2019 by anago_b
** function for my_printf
** File description:
**     flag func 2
*/

#include "../../lib/lib.h"

int flags_o(va_list list)
{
    int nbr = va_arg(list, int);
    int x = 0;

    x = unsigned_octal(nbr, "01234567");
    return (x);
}

int flags_u(va_list list)
{
    int nbr = va_arg(list, int);

    my_putnbr_unsigned(nbr);
    return (my_nbrlen(nbr));
}

int flags_x(va_list list)
{
    int nbr = va_arg(list, int);
    int n = 0;

    n = unsigned_hexadecimal(nbr, "0123456789abcdef");
    return (n);
}

int flags_upper_x(va_list list)
{
    int nbr = va_arg(list, int);
    int n = 0;

    n = unsigned_hexadecimal(nbr, "0123456789ABCDEF");
    return (n);
}