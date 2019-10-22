/*
** ETNA PROJECT, 09/01/2019 by anago_b
** put nbr
** File description:
**      nbr put unsi
*/

#include "../../lib/lib.h"

void my_putnbr_unsigned(unsigned int n)
{
    if (n < 10)
        my_putchar(n + 48);
    else {
        my_putnbr(n / 10);
        my_putnbr(n % 10);
    }
}
