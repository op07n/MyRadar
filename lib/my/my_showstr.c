/*
** EPITECH PROJECT, 2019
** MY_SHOWSTR
** File description:
** show str with hexadecimal unprintable character
*/

#include "my.h"

int my_putnbr_base(int nbr, char const *base)
{
    int i;

    if (nbr < 0) {
        nbr *= (-1);
        my_putchar('-');
    }
    for (i = 0; base[i] != 0; i++);
    if (nbr > i - 1)
        my_putnbr_base(nbr / i, base);
    if (nbr % 10 >= 0)
        my_putchar(base[nbr % i]);
    return (0);
}

int my_showstr(char const *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] < 32) {
            my_putchar('\\');
            my_putnbr_base(str[i], "0123456789abcdef");
        } else {
            my_putchar(str[i]);
        }
    }
    return (0);
}
