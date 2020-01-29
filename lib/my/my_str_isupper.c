/*
** EPITECH PROJECT, 2019
** STR_ISUPPER
** File description:
** verify if only uppercase alpha chars
*/

int my_str_isupper(char const *str)
{
    if (str[0] != 0) {
        if (64 < str[0] && str[0] < 91) {
            return my_str_isupper(str + 1);
        } else {
            return (0);
        }
    } else {
        return (1);
    }
}
