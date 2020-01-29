/*
** EPITECH PROJECT, 2019
** My find prime sup
** File description:
** get the prime number the greater than, or equal to n
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int result = 0;
    int i = nb;

    if (nb <= 0)
        return (2);
    while (!my_is_prime(i)) {
        i++;
    }
    return (i);
}
