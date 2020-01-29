/*
** EPITECH PROJECT, 2019
** print_error
** File description:
** print error
*/

#include <unistd.h>

int print_error(char const *error)
{
    for (int i = 0; error[i] != 0; i++)
        write(2, error + i, 1);
    return (0);
}
