/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** printf_funcs_part3.c
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"
#include "printf.h"

flag **create_flags_table(int size)
{
    flag *tmp;
    flag **flags = malloc(sizeof(flag*) * size);
    char f[4] = {'-', '+', ' ', '0'};

    if (flags == NULL)
        return ((flag**) 84);
    for (int i = 0; i < size; i += 1) {
        tmp = malloc(sizeof(flag));
        if (tmp == NULL)
            return ((flag**) 84);
        tmp->flag = f[i];
        tmp->exist = 0;
        tmp->width = -1;
        flags[i] = tmp;
    }
    return (flags);
}

int get_width_or_precision(char *str, char **endptr)
{
    int nb = 0;
    int i = 0;
    while (is_num(str[i]) && str[i] != '\0') {
        nb = nb * 10 + (str[i] - '0');
        i += 1;
    }
    *endptr = str + i;
    return (nb);
}

int detect_flags(char **str, flag** flags, int length)
{
    int i = 0;
    while (is_flag((*str)[i + 1])) {
        active_minus_flag(flags, (*str)[i + 1]);
        active_plus_flag(flags, (*str)[i + 1]);
        active_zero_flag(flags, (*str)[i + 1]);
        active_space_flag(flags, (*str)[i + 1]);
        i += 1;
    }
    return (i + 1);
}

int manage_precision(char **endptr)
{
    int precision = 0;
    if ((*endptr)[0] == '.') {
        precision = get_width_or_precision(*endptr + 1, endptr);
        return (precision);
    }
    return (-1);
}

void print_octal(va_list args, flag **flags, int precision, int width)
{
    int u;

    u = va_arg(args, int);
    my_putnbr_base(u, "01234567");
}