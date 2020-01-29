/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_bootstrap_2019
** File description:
** my_strtol.c
*/
#include "my.h"
#include "my_macros.h"

int my_strtol(char *str, char **endptr)
{
    int nbr = 0;
    int is_neg = 1;

    for (; !is_num(*str); str++) {
        is_neg = (*str == '-') ? is_neg * (-1) : is_neg;
    }
    for (; *str != 0 && is_num(*str); str++) {
        nbr = nbr * 10 + ATN(*str);
    }
    *endptr = str;
    if (*endptr[0] == 0 && nbr == 0)
        return (84);
    return (nbr * is_neg);
}
