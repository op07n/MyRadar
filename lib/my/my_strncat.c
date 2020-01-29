/*
** EPITECH PROJECT, 2019
** STRNCAR
** File description:
** strcat for n chars of src
*/
#include "my.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int i;
    int len = my_strlen(dest);

    for (i = 0; src[i] != 0 && i < n; i++) {
        dest[len + i] = src[i];
    }
    dest[len + i + 1] = '\0';
    return dest;
}
