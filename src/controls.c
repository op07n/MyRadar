/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** controls.c
*/

#include "../include/my.h"
#include "../include/radar.h"
#include "../include/tree.h"

void manage_keyboard(sfKeyCode code, int *show_sprite, int *show_hitbox)
{
    switch (code) {
        case sfKeyS:
            if (*show_sprite)
                *show_sprite = 0;
            else
                *show_sprite = 1;
            break;
        case sfKeyL:
            if (*show_hitbox)
                *show_hitbox = 0;
            else
                *show_hitbox = 1;
            break;
        default:
            break;

    }
}

void manage_events(sfRenderWindow *window, int *show_sprite, int *show_hitbox)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed)
            manage_keyboard(event.key.code, show_sprite, show_hitbox);
    }
}
