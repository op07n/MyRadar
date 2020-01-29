/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** radar.c
*/

#include "../include/my.h"
#include "../include/radar.h"

int run_radar(char *filepath)
{
    tower_list_t *towers = NULL;
    aircraft_list_t *aircrafts = NULL;
    img_list_t *imgs = NULL;

    if (!parse_file(filepath, &towers, &aircrafts))
        return (EXIT_FAIL);
    render(&towers, &aircrafts, &imgs);
    aircraft_list_destroy(aircrafts);
    tower_list_destroy(towers);
    return (RETURN_GOOD);
}

void print_framerate(void)
{
    static int first = 1;
    static sfClock *clock ;
    static int fps = 0;
    if (first == 1) {
        clock = sfClock_create();
        first = 0;
    }
    sfTime elapsed = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed) >= 1) {
        printf("%3d FPS \r", fps);
        fflush(stdout);
        fps = 0;
        sfClock_restart(clock);
    } else
         fps++;
}
