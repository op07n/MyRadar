/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** aircraft_list.c
*/

#include "../../include/my.h"
#include "../../include/radar.h"
#include "../../include/tree.h"

void add_aircraft(aircraft_list_t **list, aircraft_t *plane)
{
    aircraft_list_t *element = malloc(sizeof(*element));
    element->plane = plane;
    element->next = *list;
    *list = element;
}

void show_aircrafts(aircraft_list_t *list, int depth)
{
    while (list != NULL) {
        for (int i = 0; i < depth; i += 1)
            my_printf("\t");
        my_printf("Plane - %d, %d, Arrival : %d, %d, Speed : %d\n",
        (int) list->plane->actual_pos->x,
        (int) list->plane->actual_pos->y,
        (int) list->plane->arrival->x,
        (int) list->plane->arrival->y,
        list->plane->move_speed);
        list = list->next;
    }
}

void aircraft_remove(aircraft_list_t** list, aircraft_list_t *element)
{
    aircraft_list_t *current = *list;
    aircraft_list_t *prev = NULL, *next = NULL;

    while (current != NULL) {
        if (current->plane->id == element->plane->id) {
            next = current->next;
            if (prev != NULL) {
                prev->next = next;
            } else {
                *list = next;
            }
            aircraft_destroy(current->plane);
            break;
        } else {
            prev = current;
        }
        current = current->next;
    }

}

int get_nb_aircrafts(aircraft_list_t *list)
{
    int i;
    for (i = 0; list != NULL; list = list->next, i += 1);
    return (i);
}

void update_aircrafts(aircraft_list_t *list, sfClock* global, sfTime deltat)
{
    aircraft_list_t* tmp;
    sfTime time = sfClock_getElapsedTime(global);

    while (list != NULL) {
        if ((float) list->plane->take_off_time < sfTime_asSeconds(time))
            move_aircraft(list->plane, deltat);
        list = list->next;
    }
}

void concat_aircraft_lists(aircraft_list_t **l1, aircraft_list_t *l2)
{
    if (l2 == NULL)
        return;
    aircraft_list_t *tmp = l2;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = *l1;
    *l1 = l2;
}

void aircraft_list_destroy(aircraft_list_t *list)
{
    aircraft_list_t *tmp;

    while (list != NULL) {
        tmp = list->next;
        aircraft_destroy(list->plane);
        free(list);
        list = tmp;
    }
}

int is_in_list(aircraft_list_t *list, aircraft_list_t *element)
{
    while (list != NULL) {
        if (list->plane->id == element->plane->id) {
            return (1);
        }
        list = list->next;
    }
    return (0);
}

aircraft_list_t* get_controled_planes(Grid* qtree, tower_list_t *towers)
{
    aircraft_list_t *result = NULL;
    aircraft_list_t *tmp;
    while (towers != NULL) {
        tmp = tower_query(qtree, towers->tower);
        concat_aircraft_lists(&result, tmp);
        towers = towers->next;
    }
    return (result);
}

aircraft_list_t *get_uncontroled_planes(Grid* qtree, aircraft_list_t
**aircrafts, tower_list_t **towers)
{
    aircraft_list_t *result = NULL;
    aircraft_list_t *tmp = *aircrafts;
    aircraft_list_t *controled_planes = get_controled_planes(qtree, *towers);
    while (tmp != NULL) {
        if (!is_in_list(controled_planes, tmp) && !tmp->plane->is_destroyed
        && !tmp->plane->is_arrived)
            add_aircraft(&result, tmp->plane);
        else if (is_in_list(controled_planes, tmp))
            sfRectangleShape_setOutlineColor(tmp->plane->box, sfGreen);
        tmp = tmp->next;
    }
    return (result);
}