/*
** EPITECH PROJECT, 2019
** my_put_float
** File description:
** display float number
*/

#include "my.h"

int my_put_double(double f, int precision)
{
    int i = 1, mult = 1, temp;
    long long decimal_part = (long long) (f * mpow(10, precision))
        % mpow(10, precision);
    my_put_nbr(f, 1);
    my_putchar('.');
    while (decimal_part < mpow(10, precision - i)
    && mpow(10, precision - i) != 1) {
        my_putchar('0');
        i += 1;
    };
    for (int temp = decimal_part; temp >= 10; temp /= 10)
        mult += 1;
    my_put_nbr(decimal_part, 0);
    for (int i = 0; mult + i < precision; i += 1)
        my_putchar('0');
    return (0);
}
