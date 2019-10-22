/*
** ETNA PROJECT, 28/09/2018 by anago_b
** put nbr
** File description:
**      nbr put
*/

#include "../../lib/lib.h"

void my_putnbr(int n)
{
    if (n >= 0 && n < 10)
        my_putchar(n + 48);
    else if (n < 0 && n > -2147483648) {
        my_putchar('-');
        n = n * (-1);
        my_putnbr(n);
    }
    else if (n == -2147483648) {
        my_putnbr(-214748364);
        my_putchar('8');
    }
    else {
        my_putnbr(n / 10);
        my_putnbr(n % 10);
    }
}