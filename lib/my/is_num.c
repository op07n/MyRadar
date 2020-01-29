/*
** EPITECH PROJECT, 2019
** is num
** File description:
** detect if char is num
*/

int is_num(char const c)
{
    if (c > 47 && c < 58)
        return (1);
    return (0);
}
