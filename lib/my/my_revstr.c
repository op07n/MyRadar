/*
** EPITECH PROJECT, 2019
** My revstr
** File description:
** reverse a string
*/

char *my_revstr(char *str)
{
    int length = 0;
    int i;
    char temp;

    for (i = 0; str[i] != '\0'; i++)
        length++;
    for (i = 0; i < length; i++) {
        temp  = *(str + i);
        *(str + i) = *(str + length - 1);
        *(str + length - 1) = temp;
        length--;
    }
    return str;
}
