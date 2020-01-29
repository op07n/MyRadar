/*
** EPITECH PROJECT, 2019
** QuadTree
** File description:
** qtree.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../include/tree.h"
#include "../../include/my.h"

Grid* create_tree(float x, float y, float w, float h)
{
    sfFloatRect* area = create_rect(x, y, w, h);
    Grid* qtree = malloc(sizeof(*qtree));

    qtree->area = area;
    qtree->towers = NULL;
    qtree->aircrafts = NULL;
    qtree->divided = 0;
    qtree->nw = NULL;
    qtree->ne = NULL;
    qtree->sw = NULL;
    qtree->se = NULL;
    return (qtree);
}

void grid_destroy(Grid* qtree)
{
    if (qtree == NULL)
        return;
    rect_destroy(qtree->area);
    grid_destroy(qtree->nw);
    grid_destroy(qtree->ne);
    grid_destroy(qtree->sw);
    grid_destroy(qtree->se);
    free(qtree);
}

void grid_reset(Grid* qtree)
{
    if (qtree == NULL)
        return;
    grid_reset(qtree->nw);
    grid_reset(qtree->ne);
    grid_reset(qtree->sw);
    grid_reset(qtree->se);
    if (qtree->area->width != WIDTH) {
        rect_destroy(qtree->area);
        free(qtree);
    } else {
        qtree->divided = 0;
        qtree->nw = NULL;
        qtree->ne = NULL;
        qtree->sw = NULL;
        qtree->se = NULL;
    }
}

void subdivide_tree(Grid* qtree)
{
    float x = qtree->area->left;
    float y = qtree->area->top;
    float w = qtree->area->width;
    float h = qtree->area->height;

    qtree->divided = 1;
    qtree->nw = create_tree(x, y, x + w /2, y + h /2);
    qtree->ne = create_tree(x + w / 2, y, w /2, y + h /2);
    qtree->sw = create_tree(x, y + h / 2, w /2, y + h /2);
    qtree->se = create_tree(x + w / 2, y + h / 2, w /2, y + h /2);
}

void show_grid(Grid* qtree, int depth)
{
    if (qtree == NULL)
        return;
    for (int i = 0; i < depth; i += 1)
        my_printf("\t");
    my_printf("Rect with as origin (%d;%d) of size : %dx%d\n\n",
    qtree->area->left, qtree->area->top, qtree->area->width,
    qtree->area->width);
    if (get_nb_aircrafts(qtree->aircrafts) == 0)
        return;
    show_aircrafts(qtree->aircrafts, depth);
    show_towers(qtree->towers, depth);
    show_grid(qtree->nw, depth + 1);
    show_grid(qtree->ne, depth + 1);
    show_grid(qtree->sw, depth + 1);
    show_grid(qtree->se, depth + 1);
    my_printf("\n");
}

void draw_grid(sfRenderWindow *window, Grid* qtree, const int *options)
{
    if (qtree == NULL)
        return;
    tower_list_t *tmp_t = qtree->towers;
    aircraft_list_t *tmp_a = qtree->aircrafts;

    while (tmp_t != NULL) {
        sfRenderWindow_drawCircleShape(window, tmp_t->tower->control_area,
        NULL);
        sfRenderWindow_drawSprite(window, tmp_t->tower->sprite, NULL);
        tmp_t = tmp_t->next;
    }
    while (tmp_a != NULL) {
        if (options[1])
            sfRenderWindow_drawRectangleShape(window, tmp_a->plane->box, NULL);
        if (options[0])
            sfRenderWindow_drawSprite(window, tmp_a->plane->sprite, NULL);
        tmp_a = tmp_a->next;
    }
    draw_grid(window, qtree->nw, options);
    draw_grid(window, qtree->ne, options);
    draw_grid(window, qtree->sw, options);
    draw_grid(window, qtree->se, options);
}

aircraft_list_t *qtree_query(Grid* qtree, sfFloatRect* range)
{
    aircraft_list_t *aircrafts = qtree->aircrafts;
    aircraft_list_t *insides = NULL;
    sfFloatRect* bounds;
    if (!rect_intersects(qtree->area, range))
        return insides;
    while (aircrafts != NULL) {
        bounds = aircrafts->plane->bounds;
        if (rect_intersects(bounds, range))
            add_aircraft(&insides, aircrafts->plane);
        aircrafts = aircrafts->next;
    }
    if (!qtree->divided)
        return (insides);
    concat_aircraft_lists(&insides, qtree_query(qtree->nw, range));
    concat_aircraft_lists(&insides, qtree_query(qtree->ne, range));
    concat_aircraft_lists(&insides, qtree_query(qtree->sw, range));
    concat_aircraft_lists(&insides, qtree_query(qtree->se, range));
    return (insides);
}

void grid_insert(Grid* qtree, tower_list_t *towers, aircraft_list_t
*aircrafts)
{
    while (towers != NULL) {
        insert_tower(qtree, towers->tower);
        towers = towers->next;
    }
    while (aircrafts != NULL) {
            insert_aircraft(qtree, aircrafts->plane);
        aircrafts = aircrafts->next;
    }
}

void manage_collisions(Grid* qtree, aircraft_list_t *out, sfTime globalt)
{
    aircraft_list_t *potentially = NULL;
    sfFloatRect *range = NULL;
    sfFloatRect *bounds = NULL;
    int is_colliding;
    float t = TO_SECONDS(globalt.microseconds);

    while (out != NULL) {
        if (!out->plane->is_destroyed && !out->plane->is_arrived && t >
        (float) out->plane->take_off_time) {
            is_colliding = 0;
            bounds = out->plane->bounds;
            range = create_rect(
                bounds->left - bounds->width,
                bounds->top - bounds->height,
                bounds->width * 3,
                bounds->height * 3);
            potentially = qtree_query(qtree, range);
            while (potentially != NULL) {
                if (rect_intersects(out->plane->bounds,
                                    potentially->plane->bounds) &&
                    potentially->plane->id != out->plane->id &&
                    !potentially->plane->is_arrived &&
                    !potentially->plane->is_destroyed &&
                    (float) potentially->plane->take_off_time < t) {
                    potentially->plane->is_destroyed = 1;
                    change_texture(potentially->plane, DESTROY_IMG);
                    is_colliding = 1;
                }
                potentially = potentially->next;
            }
            if (is_colliding) {
                out->plane->is_destroyed = 1;
                change_texture(out->plane, DESTROY_IMG);
            }
        }
        out = out->next;

    }
}