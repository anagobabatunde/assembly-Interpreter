/*
** ETNA PROJECT, 08/01/2019 by anago_b
** my_putnbr_base_hex_bin_octet
** File description:
**      putnbr base
*/

#include "../../lib/lib.h"

int unsigned_hex_hex(unsigned int n, char *base, int type)
{
    char tab[16];
    int i = 0;
    int j;

    while (n > 0) {
        tab[i] = base[n % type];
        n /= type;
        i++;
    }
    for (j = i - 1; j >= 0; j--)
        my_putchar(tab[j]);

    return (my_strlen(tab));
}

int unsigned_hexadecimal(unsigned int n, char *base)
{
    int type = my_strlen(base);
    int x = 0;

    if (type)
        x = unsigned_hex_hex(n, base, type);
    return (x);
}
