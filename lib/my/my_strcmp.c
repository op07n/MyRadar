/*
** EPITECH PROJECT, 2019
** STRCMP
** File description:
** compare to string
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i;

    for (i = 0; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++);
    if (s1[i] - s2[i] == 0)
        return (s1[i] - s2[i]);
    else if (s1[i] - s2[i] < 0)
        return (-1);
    else
        return (1);
}
