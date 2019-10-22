/*
** ETNA PROJECT, 08/01/2019 by anago_b
** my_putnbr_base_hex_bin_octet
** File description:
**      putnbr base
*/

#include "../../lib/lib.h"

int unsigned_octal_hex(unsigned int n, char *base, int type)
{
    int *tab = malloc(sizeof(int));
    int i = 0;
    int j;
    int temp;

    while (n > 0) {
        tab[i] = base[n % type];
        n /= type;
        i++;
    }
    temp = i;
    for (j = i - 1; j >= 0; j--)
        my_putchar(tab[j]);
    free(tab);
    return (temp);
}

int unsigned_octal(unsigned int n, char *base)
{
    int type = my_strlen(base);
    int x;

    x = unsigned_octal_hex(n, base, type);
    return (x);
}
