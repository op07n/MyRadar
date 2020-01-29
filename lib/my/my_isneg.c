/*
** EPITECH PROJECT, 2019
** my_isneg
** File description:
** show 'N' if neg , show 'P' is pos
*/
#include "my.h"

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    return (0);
}
