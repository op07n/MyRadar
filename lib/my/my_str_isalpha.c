/*
** EPITECH PROJECT, 2019
** ISALPHA
** File description:
** verify if only alpha
*/

int my_str_isalpha(char const *str)
{
    if (str[0] != 0) {
        if ((64 < str[0] && str[0] < 91) || (96 < str[0] && str[0] < 123)) {
            return my_str_isalpha(str + 1);
        } else {
            return (0);
        }
    } else {
        return (1);
    }
}
