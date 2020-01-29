/*
** EPITECH PROJECT, 2019
** my_printf.c
** File description:
** my_printf.c
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"
#include "printf.h"

void print_binary(va_list args, flag **flags, int precision, int width)
{
    unsigned int u;
    u = va_arg(args, unsigned int);
    my_putnbr_base(u, "01");
}

void (*get_print_func(char const c))(va_list args, flag **flags, int
precision, int width)
{
    int i;

    for (i = 0; TAGS[i].tag != c && TAGS[i].tag != -1; i += 1);
    return TAGS[i].func;
}

void free_flags(flag** FLAGS)
{
    free(FLAGS[0]);
    free(FLAGS[1]);
    free(FLAGS[2]);
    free(FLAGS[3]);
    free(FLAGS);
}

int select_tag(char **str, va_list args)
{
    char *endptr = NULL;
    void (*func)();
    int size = 4, precision;
    flag **FLAGS = create_flags_table(size);
    int length_flags = detect_flags(str, FLAGS, size);
    int width = get_width_or_precision((*str) + length_flags, &endptr);
    precision = manage_precision(&endptr);
    func = get_print_func(endptr[0]);
    if (func != 0) {
        (*func)(args, FLAGS, precision, width);
        (*str) = endptr;
    } else {
        my_putchar((*str)[0]);
        my_putchar((*str)[1]);
        (*str) += 1;
    }
    free_flags(FLAGS);
    return (0);
}

int my_printf(char const *str, ...)
{
    int count;
    va_list args;
    char *parcours = my_strdup(str);
    char *tmp = parcours;

    va_start(args, str);
    for (; *parcours != 0; parcours += 1) {
        if (*parcours == '%') {
            select_tag(&parcours, args);
        } else {
            my_putchar(*parcours);
        }
    }
    free(tmp);
    return (0);
}
