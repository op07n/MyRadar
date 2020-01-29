/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** img_list.c
*/

#include "../../include/radar.h"
#include "../../include/my.h"

void add_img(img_list_t **list, char *filepath)
{
    sfTexture *txt = sfTexture_createFromFile(filepath, NULL);
    sfSprite *sprite = sfSprite_create();
    img_list_t *element = malloc(sizeof(*element));

    sfSprite_setTexture(sprite, txt, sfTrue);
    element->sprite = sprite;
    element->txt = txt;
    element->next = *list;
    *list = element;
}

void imgs_destroy(img_list_t **list)
{
    img_list_t *tmp;

    while (*list != NULL) {
        tmp = (*list)->next;
        free(*list);
        *list = tmp;
    }
}