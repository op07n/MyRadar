/*
** EPITECH PROJECT, 2019
** my strdup
** File description:
** allocates memory and copy string
*/
#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *dest = malloc(sizeof(char) * len + 1);

    for (int i = 0; i <= len; i++)
        dest[i] = src[i];
    return dest;
}
