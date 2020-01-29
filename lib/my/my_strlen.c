/*
** EPITECH PROJECT, 2019
** My strlen
** File description:
** calcule longueur str
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != 0) {
        i++;
    }
    return i;
}
