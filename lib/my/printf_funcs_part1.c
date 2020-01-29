/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** printf_functions
*/

#include <stdarg.h>
#include "my.h"
#include "printf.h"

void print_percent(va_list args, flag **flags, int precision, int width)
{
    my_putchar('%');
}

void print_dec(va_list args, flag **flags, int precision, int wid)
{
    long long int i;
    int x, s_len;

    i = va_arg(args, long long int);
    s_len = get_mult(i) + ((flags[1]->exist) ? 1 : 0);
    if (flags[3]->exist) {
        if (flags[2]->exist) {
            my_putchar(' ');
            wid -= 1;
        }
        for (x = 0; x < wid - s_len; x += 1)
            my_putchar('0');
    } else if (flags[2]->exist) {
        for (x = 0; x < wid - s_len; x += 1)
            my_putchar(' ');
    }
    if (flags[1]->exist && i >= 0)
        my_putchar('+');
    my_put_nbr(i, 0);
}

void print_double(va_list args, flag **flags, int precision, int wid)
{
    double d;
    int x, s_len;
    d = va_arg(args, double);
    s_len = get_mult((int) d) + ((flags[1]->exist) ? 1 : 0) + precision + 1;
    if (flags[3]->exist) {
        if (flags[2]->exist) {
            my_putchar(' ');
            wid -= 1;
        }
        for (x = 0; x < wid - s_len; x += 1)
            my_putchar('0');
    } else if (flags[2]->exist) {
        for (x = 0; x < wid - s_len; x += 1)
            my_putchar(' ');
    }
    if (flags[1]->exist && (int) d >= 0)
        my_putchar('+');
    if (precision != -1)
        my_put_double(d, precision);
    else
        my_put_double(d, 6);
}

void print_char(va_list args, flag **flags, int precision, int width)
{
    int c;

    c = (char) va_arg(args, int);
    my_putchar(c);
}

void print_hex(va_list args, flag **flags, int precision, int width)
{
    unsigned int u;

    u = va_arg(args, unsigned int);
    my_putnbr_base(u, "0123456789abcdef");
}