/*
** EPITECH PROJECT, 2019
** Power
** File description:
** recursive version
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return (1);
    if (p < 0 || p > 12)
        return (0);
    return (nb * my_compute_power_rec(nb, p - 1));
}
