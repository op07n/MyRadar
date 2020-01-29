/*
** EPITECH PROJECT, 2019
** ISPRINTABLE
** File description:
** verify if only printable chars
*/

int my_str_isprintable(char const *str)
{
    if (str[0] != 0) {
        if (31 < str[0]) {
            return my_str_isprintable(str + 1);
        } else {
            return (0);
        }
    } else {
        return (1);
    }
}
