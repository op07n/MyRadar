/*
** EPITECH PROJECT, 2019
** is_prime
** File description:
** verify if it s prime
*/

int my_is_prime(int nb)
{
    if (nb <= 3) {
        if (nb > 1)
            return (1);
        else
            return (0);
    } else if ( nb % 2 == 0 || nb % 3 == 0 ) {
        return (0);
    }

    int i = 5;
    while (i * i <= nb) {
        if (nb % i == 0 || nb % (i + 2) == 0 ) {
            return (0);
        }
        i += 6;
    }
    return (1);
}
