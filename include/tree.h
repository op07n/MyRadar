/*
** EPITECH PROJECT, 2019
** QuadTree
** File description:
** tree.h
*/

#ifndef QUADTREE_TREE_H
#define QUADTREE_TREE_H

#include <SFML/Graphics.h>
#define LIMITED_SPACE 10

#include "radar.h"
#include "rect.h"
#include "entities.h"

typedef struct QuadTree
{
    sfFloatRect* area;
    aircraft_list_t* aircrafts;
    tower_list_t* towers;
    int divided;
    struct QuadTree* nw;
    struct QuadTree* ne;
    struct QuadTree* sw;
    struct QuadTree* se;
} Grid;


Grid* create_tree(float x, float y, float w, float h);
void grid_destroy(Grid* qtree);
void grid_reset(Grid* qtree);
void insert_tower(Grid* qtree, tower_t *new_tower);
void insert_aircraft(Grid* qtree, aircraft_t *new_aircraft);
void subdivide_tree(Grid* qtree);
void show_grid(Grid* qtree, int depth);
void draw_grid(sfRenderWindow *window, Grid* qtree, const int *options);
aircraft_list_t *qtree_query(Grid* qtree, sfFloatRect* range);
aircraft_list_t *tower_query(Grid* qtree, tower_t *tower);
void grid_insert(Grid* qtree, tower_list_t *towers, aircraft_list_t*);
aircraft_list_t* get_controled_planes(Grid* qtree, tower_list_t *towers);
aircraft_list_t *get_uncontroled_planes(Grid*, aircraft_list_t**,
tower_list_t **);
void manage_collisions(Grid* qtree, aircraft_list_t *out, sfTime globalt);
#endif
