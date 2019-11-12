/*
** ETNA PROJECT, 21/02/2019 by anago_b
** my_getnbr2.c
** File description:
**      Getnbr modifie pour parser
*/

int my_getnbr2(char *str, int *i)
{
    int isneg = 1;
    int res = 0;

    while (str[*i] == 43 || str[*i] == 45 ){
        if (str[*i] == 45)
            isneg *= -1;
        *i += 1;
    }
    while (str[*i] >= 48 && str[*i] <= 57){
        res *= 10;
        res += str[*i] - 48;
        *i += 1;
    }
    return (isneg * res);
}
