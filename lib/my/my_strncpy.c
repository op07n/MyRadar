/*
** EPITECH PROJECT, 2019
** my strncpy
** File description:
** copy n char from a source string
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (int x = 0; dest[x] != 0; x++)
        dest[x] = 0;
    while (src[i] != 0 && i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[i+1] = 0;
    return dest;
}
