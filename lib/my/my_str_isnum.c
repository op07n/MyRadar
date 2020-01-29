/*
** EPITECH PROJECT, 2019
** MY ISNUM
** File description:
** verify if str only contains digits
*/
#include "my.h"

int eval(char const *str)
{
    for (int i = 1; str[i] != 0; i++) {
        if (!is_num(str[i]))
            return (0);
    }
    return (1);
}

int my_str_isnum(char const *str)
{
    if (str[0] == '-') {
        if (!eval(str))
            return (0);
    } else if (is_num(str[0])) {
        if (!eval(str))
            return (0);
    } else {
        return (0);
    }
    return (1);
}
