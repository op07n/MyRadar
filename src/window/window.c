/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** window.c
*/

#include <SFML/Graphics.h>
#include "../../include/window.h"
#include "../../include/my.h"

sfRenderWindow* create_window(int width, int height, char const* title)
{
    sfVideoMode mode = {width, height, BPP};
    sfRenderWindow* window = sfRenderWindow_create(
        mode,
        title,
        sfDefaultStyle,
        NULL);
    sfRenderWindow_setFramerateLimit(window,  100);
    return (window);
}

int is_open_window(sfRenderWindow* window)
{
    return sfRenderWindow_isOpen(window);
}