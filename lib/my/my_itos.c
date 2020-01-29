/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_itos.c
*/

#include <stdlib.h>
#include "my.h"
#include "my_macros.h"

char *my_itos(int i)
{
    char *str;
    int nb_char = 1;
    int is_neg = (i < 0) ? 1 : 0;

    i = ABS(i);
    for (int tmp = i; tmp >= 10; nb_char += 1, tmp /= 10);
    if (is_neg)
        nb_char += 1;
    str = malloc(sizeof(char) * (nb_char + 1));
    my_memset(str, '\0', nb_char + 1);
    for (int j = 0; j < nb_char; j += 1) {
        str[j] = NTA(i % 10);
        i /= 10;
    }
    return (my_revstr(str));
}
