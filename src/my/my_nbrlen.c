/*
** ETNA PROJECT, 28/09/2018 by anago_b
** nbr len
** File description:
**      len nbr
*/

#include "../../lib/lib.h"

int my_nbrlen(int n)
{
    int compteur = 0;

    if (n < 0) {
        n = n * (-1);
        compteur++;
    }
    if (n == 0)
        return (1);
    while (n != 0) {
        n /= 10;
        compteur++;
    }
    return (compteur);
}