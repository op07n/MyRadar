/*
** EPITECH PROJECT, 2019
** STRNCMP
** File description:
** compare n char between S1 & S2
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i;

    for (i = 0; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n; i++);
    if (s1[i] - s2[i] == 0)
        return (s1[i] - s2[i]);
    else if (s1[i] - s2[i] < 0)
        return (-1);
    else
        return (1);
}
