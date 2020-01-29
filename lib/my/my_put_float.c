/*
** EPITECH PROJECT, 2019
** my_put_float
** File description:
** display float number
*/

#include "my.h"

int my_put_float(float f)
{
    my_put_nbr(f);
    int decimal_part = (int) (f * 100) % 100;
    my_putchar('.');
    if (decimal_part < 10)
        my_putchar('0');
    my_put_nbr(decimal_part);
    return (0);
}
