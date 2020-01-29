/*
** EPITECH PROJECT, 2019
** my PUTCHAR
** File description:
** display one char
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
