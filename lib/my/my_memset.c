/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_memset.c
*/

void *my_memset(char *pointer, int value, int count)
{
    for (int i = 0; i < count; i += 1) {
        pointer[i] = value;
    }
}
