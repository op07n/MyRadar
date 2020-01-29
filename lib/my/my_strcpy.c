/*
** EPITECH PROJECT, 2019
** My Strcpy
** File description:
** Copy str
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    for (int x = 0; dest[x] != 0; x++)
        dest[x] = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i + 1] = '\0';
    return dest;
}
