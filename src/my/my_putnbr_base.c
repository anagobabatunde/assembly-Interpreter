/*
** ETNA PROJECT, 08/01/2019 by anago_b
** my_putnbr_base_hex_bin_octet
** File description:
**      putnbr base
*/

#include "../../lib/lib.h"

void my_putnbr_base(int n, char *base)
{
    int *tab = 0;
    int type = my_strlen(base);
    int i = 0;
    int j;

    tab = malloc(sizeof(int) * 32);
    if (n < 0) {
        n *= -1;
        my_putchar('-');
    }
    while (n > 0) {
        tab[i] = base[n % type];
        n /= type;
        i++;
    }
    for (j = i - 1; j >= 0; j--)
        my_putchar(tab[j]);
    free(tab);
}
