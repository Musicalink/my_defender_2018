/*
** EPITECH PROJECT, 2018
** CPool_2018
** File description:
** Maxence Carpentier
*/

#include "my.h"
#include <stdlib.h>

char *my_itoa(int nb)
{
    char *str;
    int incrementer = 0;
    int buffer = nb;

    str = malloc(sizeof(char) * my_intlen(nb) + (nb < 0) ? 2 : 1);
    nb *= (nb < 0) ? -1 : 1;
    if (nb == 0)
        return ("0");
    for (int i = 0; nb != 0; i++) {
        str[incrementer] = (char)(nb % 10 + '0');
        nb /= 10;
        incrementer++;
    }
    if (buffer < 0) {
        str[incrementer] = '-';
        incrementer++;
    }
    str[incrementer] = '\0';
    return (my_revstr(str));
}
