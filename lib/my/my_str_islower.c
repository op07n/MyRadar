/*
** EPITECH PROJECT, 2019
** My ISLOWER
** File description:
** verify if only lowercase alpha char
*/

int my_str_islower(char const *str)
{
    if (str[0] != 0) {
        if (96 < str[0] && str[0] < 123) {
            return my_str_islower(str + 1);
        } else {
            return (0);
        }
    } else {
        return (1);
    }
}
