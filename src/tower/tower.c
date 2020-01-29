/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** tower.c
*/

#include <stdlib.h>
#include "../../include/my.h"
#include "../../include/radar.h"
#include "../../include/tree.h"

sfCircleShape* init_control_area(sfVector2f* pos, float radius)
{
    sfVector2f begin_circle = {
    pos->x - radius + ((float) TOWER_SIZE) / 2,
    pos->y - radius + ((float) TOWER_SIZE) / 2
    };
    sfCircleShape* area = sfCircleShape_create();
    sfCircleShape_setOutlineColor(area, sfBlue);
    sfCircleShape_setFillColor(area, sfTransparent);
    sfCircleShape_setOutlineThickness(area, 3);
    sfCircleShape_setPosition(area, begin_circle);
    sfCircleShape_setRadius(area, radius);
    return (area);
}

tower_t *create_tower(char **entity_data)
{
    tower_t *tower = malloc(sizeof(tower_t));
    sfVector2f* pos = create_vector(
    (float) my_getnbr(entity_data[1]) - (float) TOWER_SIZE / 2,
    (float) my_getnbr(entity_data[2]) - (float) TOWER_SIZE / 2);
    float radius = (float) my_getnbr(entity_data[3]) / 100 * WIDTH;
    sfTexture *txt = sfTexture_createFromFile(TOWER_IMG, NULL);
    sfSprite *sprite = sfSprite_create();
    sfCircleShape* area = init_control_area(pos, radius);

    sfSprite_setPosition(sprite, *pos);
    sfSprite_setTexture(sprite, txt, sfTrue);
    tower->sprite = sprite;
    tower->txt = txt;
    tower->pos = pos;
    tower->radius = radius;
    tower->control_area = area;
    return (tower);
}

void insert_tower(Grid* qtree, tower_t *new_tower)
{
    if (!rect_contains(qtree->area, new_tower->pos->x, new_tower->pos->y))
        return;
    if (get_nb_towers(qtree->towers) < LIMITED_SPACE)
        add_tower(&qtree->towers, new_tower);
    else {
        if (!qtree->divided)
            subdivide_tree(qtree);
        insert_tower(qtree->nw, new_tower);
        insert_tower(qtree->ne, new_tower);
        insert_tower(qtree->sw, new_tower);
        insert_tower(qtree->se, new_tower);
    }
}

void tower_destroy(tower_t *tower)
{
    sfTexture_destroy(tower->txt);
    sfSprite_destroy(tower->sprite);
    sfCircleShape_destroy(tower->control_area);
    free(tower->pos);
    free(tower);
}

aircraft_list_t *tower_query(Grid* qtree, tower_t *tower)
{
    aircraft_list_t *potentially = NULL;
    aircraft_list_t *result = NULL;
    sfVector2f pos_area = sfCircleShape_getPosition(tower->control_area);
    sfFloatRect* query_area = create_rect(
        pos_area.x,
        pos_area.y,
        2 * dist(pos_area, *tower->pos) / sqrt(2),
        2 * dist(pos_area, *tower->pos) / sqrt(2)
    );
    potentially = qtree_query(qtree, query_area);
    while (potentially != NULL) {
        if (circle_intersects(tower->control_area, tower->pos,
        potentially->plane, tower->radius))
            add_aircraft(&result, potentially->plane);
        potentially = potentially->next;
    }
    return (result);
}