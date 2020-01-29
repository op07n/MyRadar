/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** display numbers
*/

#include "my.h"

long long int mpow(long n, long p)
{
    if (p == 0)
        return (1);
    return (n * mpow(n, p -1));
}

int my_put_nbr(long long int i, int precision)
{
    int mult = 1;
    long long int to_display = 0;

    if (i < 0) {
        my_putchar('-');
        i = i * (-1);
    }
    for (int temp = i; temp >= 10; temp /= 10)
        mult += 1;
    for (int i = 0; mult + i < precision; i += 1)
        my_putchar('0');
    while ( mult > 0 ) {
        to_display = i / mpow(10, mult - 1);
        my_putchar(to_display + '0');
        i %= mpow(10, mult - 1);
        mult -= 1;
    }
    return (0);
}
