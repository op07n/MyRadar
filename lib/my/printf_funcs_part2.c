/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** printf_funcs_part2.c
*/

#include <stddef.h>
#include <stdarg.h>
#include "my.h"
#include "printf.h"

void print_str(va_list args, flag **flags, int precision, int width)
{
    char *s;

    s = va_arg(args, char *);
    my_putstr(s);
}

void print_unprint_str(va_list args, flag **flags, int precision, int width)
{
    char *s;

    s = va_arg(args, char *);
    for (int i = 0; s[i] != 0; i += 1) {
        if (is_alpha(s[i])) {
            my_putchar(s[i]);
        } else {
            my_putchar('\\');
            my_put_octal(s[i]);
        }
    }
}

void print_pointer(va_list args, flag **flags, int precision, int width)
{
    void *p;
    p = va_arg(args, void *);
    if (p == NULL)
        my_putstr("(null)");
    else {
        my_putstr("0x");
        my_putnbr_base(p, "0123456789abcdef");
    }
}

void print_unsigned(va_list args, flag **flags, int precision, int width)
{
    unsigned int u;

    u = va_arg(args, unsigned int);
    my_put_nbr(u, 0);
}
