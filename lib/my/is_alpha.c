/*
** EPITECH PROJECT, 2019
** is_alpha
** File description:
** verify if a char is alpha
*/

int is_alpha(char c)
{
    if ((c > 64 && c < 91) || (c > 96 && c < 123))
        return (1);
    else
        return (0);
}
