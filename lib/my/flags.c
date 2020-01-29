/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** flags.c
*/

#include <stdarg.h>
#include "printf.h"

int is_flag(char const c)
{
    if (c == '-' || c == '+' || c == ' ' || c == '0')
        return (1);
    return (0);
}

void active_minus_flag(flag** flags, char c)
{
    if (c == '-') {
        flags[0]->exist = 1;
    }
}

void active_plus_flag(flag** flags, char c)
{
    if (c == '+') {
        flags[1]->exist = 1;
    }
}

void active_space_flag(flag** flags, char c)
{
    if (c == ' ') {
        flags[2]->exist = 1;
    }
}

void active_zero_flag(flag** flags, char c)
{
    if (c == '0') {
        flags[3]->exist = 1;
    }
}