/*
** EPITECH PROJECT, 2019
** STRSTR
** File description:
** find a string into another
*/

char *my_strstr(char *str, char const *to_find)
{
    int x = 0;
    int i;
    int match = 0;
    while (str[x] != 0) {
        for (i = 0; to_find[i] != 0; i++) {
            if (str[i + x] == to_find[i]) {
                match = 1;
            } else {
                match = 0;
                break;
            }
        }
        if (match)
            return (char *) str + x;
        x++;
    }
    return "NULL";
}
