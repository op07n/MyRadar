/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/radar.h"

int help(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        my_printf("Simulated Air Traffic 2D Visualizer\n"
        "USAGE\n"
        "\t./my_radar script\n\n"
        "DESCRIPTION\n"
        "\tscript : Path to the script describing the traffic\n\n"
        "USER INTERACTIONS\n"
        "\tM : Display/Hide map\n"
        "\tL : Display/Hide plane hitbox\n"
        "\tK : Display/Hide plane sprite\n\n");
        return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (help(ac, av))
        return (EXIT_SUCCESS);
    if (ac < 2) {
        print_error("No script precised. Get help with -h option !\n");
        return (EXIT_FAIL);
    }
    if (run_radar(av[1]) == 84)
        return (EXIT_FAIL);
    return (EXIT_SUCCESS);
}