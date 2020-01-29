/*
** EPITECH PROJECT, 2019
** STRCAT
** File description:
** CONCAT 2 STRING
*/
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i;
    int len = my_strlen(dest);

    for (i = 0; src[i] != 0; i++) {
        dest[len + i] = src[i];
    }
    dest[len + i + 1] = '\0';
    return dest;
}
