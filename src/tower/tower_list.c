/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** tower_list.c
*/

#include "../../include/my.h"
#include "../../include/radar.h"

void add_tower(tower_list_t **list, tower_t *tower)
{
    tower_list_t *element = malloc(sizeof(*element));

    element->tower = tower;
    element->next = *list;
    *list = element;
}

void show_towers(tower_list_t *list, int depth)
{
    while (list != NULL) {
        for (int i = 0; i < depth; i += 1)
            my_printf("\t");
        my_printf("Tower - X : %d, Y : %d, radius : %d\n",
        (int) list->tower->pos->x, (int) list->tower->pos->y,
        list->tower->radius);
        list = list->next;
    }
}

int get_nb_towers(tower_list_t *list)
{
    int i;
    for (i = 0; list != NULL; list = list->next, i += 1);
    return (i);
}

void tower_list_destroy(tower_list_t *list)
{
    tower_list_t *tmp;

    while (list != NULL) {
        tmp = list->next;
        tower_destroy(list->tower);
        free(list);
        list = tmp;
    }
}