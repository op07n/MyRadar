/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** printf_funcs_part4.c
*/

#include <stddef.h>
#include <stdarg.h>
#include "my.h"
#include "printf.h"

int get_mult(long long int i)
{
    int mult = 1;

    for (; i >= 10 ; mult += 1, i /= 10);
    return (mult);
}

int my_put_octal(int i)
{
    char const *b = "01234567";

    if (i < 100)
        my_putstr("0");
    if (i < 10)
        my_putstr("0");
    my_putnbr_base(i, b);
    return (0);
}