/*
** EPITECH PROJECT, 2019
** MY_SHOWMEM
** File description:
** show memory representation of a string
*/
#include "my.h"

int my_putnbr_base_without_zero(int nbr, char const *base)
{
    int i;

    if (nbr < 0) {
        nbr *= (-1);
        my_putchar('-');
    }
    for (i = 0; base[i] != 0; i++);
    if (nbr > i - 1)
        my_putnbr_base_without_zero(nbr / i, base);
    if (nbr % 10 >= 0)
        my_putchar(base[nbr % i]);
    return (0);
}

int add_spaces_and_zero(char const *str, int j)
{
    if (j % 2 == 0)
        my_putchar(' ');
    if (str[j] < 16)
        my_putchar('0');
    return (0);
}

void set_alignment(int spaces)
{
    for (int j = 0; j <= spaces; j++)
        my_putchar(' ');
}

void show_line(char const *str, int size)
{
    int j, spaces = 16 * 2;

    my_putnbr_base_without_zero(str, "0123456789ABCDEF");
    for (j = 0; j < size; j++) {
        add_spaces_and_zero(str, j);
        my_putnbr_base_without_zero(str[j], "0123456789abcdef");
        spaces -= 2;
    }
    set_alignment(spaces);
    for (j = 0; j < size; j++) {
        if (str[j] > 31)
            my_putchar(str[j]);
        else
            my_putchar('.');
    }
    my_putchar('\n');
}

int my_showmem(char const *str, int size)
{
    while (size > 0) {
        if (size >= 16)
            show_line(str, 16);
        else
            show_line(str, size);
        str += 16;
        size -= 16;
    }
    return (0);
}
