/*
** EPITECH PROJECT, 2019
** STRCAPITALIZE
** File description:
** capitalize the first letter  of each word
*/
#include "my.h"

char *my_strcapitalize(char *str)
{
    int is_word = 1;

    my_strlowcase(str);
    for (int i = 0; str[i] != 0; i++) {
        if ((is_alpha(str[i]) || is_num(str[i])) && is_word) {
            if (is_alpha(str[i]))
                str[i] -= 32;
            is_word = 0;
        }
        if (str[i] == ' ' || str[i] == '-' || str[i] == '+') {
            is_word = 1;
        }
    }
    return (str);
}
