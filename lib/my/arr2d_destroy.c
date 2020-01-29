/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** arr2d_destroy.c
*/

#include <stdlib.h>

void arr2d_destroy(void **arr)
{
    for (int i = 0; arr[i] != NULL; i += 1)
        free(arr[i]);
    free(arr);
}