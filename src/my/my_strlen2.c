/*
** ETNA PROJECT, 21/02/2019 by anago_b
** my_strlen2.c
** File description:
**      my_strlen2
*/

int my_strlen2(char *str)
{
    int i = 0;
    while (str[i] != ' ' && str[i] != '\n' )
        i++;
    return (i);
}