/*
** EPITECH PROJECT, 2019
** My sort int array
** File description:
** Ascending array int
*/

#include "my.h"

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int x = 0;

    while (i < size) {
        if (i > 0) {
            x = i;
        }
        while (x < size) {
            if (array[i] > array[x]) {
                my_swap(&array[i], &array[x]);
            }
            x += 1;
        }
        i += 1;
    }
}
