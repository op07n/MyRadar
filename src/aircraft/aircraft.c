/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** aircraft.c
*/

#include "../../include/my.h"
#include "../../include/radar.h"
#include "../../include/tree.h"

sfVector2f** get_apexes(sfRectangleShape* box)
{
    sfTransform ts[] = {sfRectangleShape_getTransform(box),
    sfRectangleShape_getInverseTransform(box)};
    sfVector2f size = PLANE_SIZE_RECT, tmp;
    sfVector2f queries[] = {
        {0.f, 0.f},
        {size.x, 0.f},
        PLANE_SIZE_RECT,
        {0.f, size. y}
    };
    sfVector2f** apexes =  malloc(sizeof(*apexes) * 4);
    sfVector2f* point;

    for (int i = 0; i < 4; i += 1) {
        tmp = sfTransform_transformPoint(ts, queries[i]);
        point = malloc(sizeof(sfVector2f));
        point->x = tmp.x;
        point->y = tmp.y;
        apexes[i] = point;
    }
    return (apexes);
}

sfRectangleShape* init_box(sfVector2f *pos, double angle, aircraft_t* plane)
{
    sfVector2f** apexes;
    sfRectangleShape* box = sfRectangleShape_create();
    sfRectangleShape_setRotation(box, (float) angle);
    sfRectangleShape_setPosition(box, *pos);
    sfRectangleShape_setFillColor(box, sfTransparent);
    sfRectangleShape_setOutlineColor(box, sfGreen);
    sfRectangleShape_setOutlineThickness(box, 3);
    sfRectangleShape_setSize(box, PLANE_SIZE_RECT);
    apexes = get_apexes(box);
    plane->apexes = apexes;
    plane->bounds = get_bounds_hitbox(apexes);
    return (box);
}

aircraft_t *create_aircraft(char **entity_data)
{
    static int id = 0;
    sfVector2f* dep_pos = create_vector(
    (float) my_getnbr(entity_data[1]) - (float) PLANE_SIZE / 2,
    (float) my_getnbr(entity_data[2]) - (float) PLANE_SIZE / 2);
    sfVector2f* arr_pos = create_vector(
    (float) my_getnbr(entity_data[3]) - (float) PLANE_SIZE / 2,
    (float) my_getnbr(entity_data[4]) - (float) PLANE_SIZE / 2);
    sfTexture* texture = sfTexture_createFromFile(PLANE_IMG, NULL);
    sfSprite* sprite = sfSprite_create();
    aircraft_t *plane = malloc(sizeof(aircraft_t));
    float pente  = get_direction(dep_pos, arr_pos);
    double angle = 0;

    if (dep_pos->x < arr_pos->x && pente > 0)
        angle = 90 + fabs(toDegree(atanf(pente)));
    if (dep_pos->x < arr_pos->x && pente < 0)
        angle = 90 - fabs(toDegree(atanf(pente)));
    if (dep_pos->x > arr_pos->x && pente > 0)
        angle = 270 + fabs(toDegree(atanf(pente)));
    if (dep_pos->x > arr_pos->x && pente < 0)
        angle = 270 - fabs(toDegree(atanf(pente)));

    plane->actual_pos = dep_pos;
    plane->departure = create_vector(dep_pos->x, dep_pos->y);
    plane->arrival = arr_pos;
    plane->move_speed = my_getnbr(entity_data[5]);
    plane->take_off_time = my_getnbr(entity_data[6]);
    plane->is_destroyed = 0;
    plane->is_arrived = 0;
    plane->direction = get_direction(dep_pos, arr_pos);
    plane->sprite = sprite;
    plane->txt = texture;
    plane->id = id++;
    plane->box = init_box(dep_pos, angle, plane);
    sfSprite_setPosition(plane->sprite, *plane->actual_pos);
    sfSprite_setRotation(plane->sprite, (float) angle);
    sfSprite_setTexture(plane->sprite, texture, sfTrue);
    return (plane);
}

void insert_aircraft(Grid* qtree, aircraft_t *new_aircraft)
{
    if (!rect_contains(qtree->area, new_aircraft->actual_pos->x,
        new_aircraft->actual_pos->y))
        return;
    if (get_nb_aircrafts(qtree->aircrafts) < LIMITED_SPACE)
        add_aircraft(&qtree->aircrafts, new_aircraft);
    else {
        if (!qtree->divided)
            subdivide_tree(qtree);
        insert_aircraft(qtree->nw, new_aircraft);
        insert_aircraft(qtree->ne, new_aircraft);
        insert_aircraft(qtree->sw, new_aircraft);
        insert_aircraft(qtree->se, new_aircraft);
    }
}

int move_aircraft(aircraft_t *plane, sfTime deltat)
{
    sfVector2f offset;
    float t = TO_SECONDS(deltat.microseconds);

    if (is_arrived(plane->actual_pos, plane->departure, plane->arrival) ||
    plane->is_arrived) {
        plane->is_arrived = 1;
        return (0);
    }
    if (plane->is_destroyed)
        return (0);
    if (plane->actual_pos->x < plane->arrival->x)
        offset.x = (float) plane->move_speed * t;
    else
        offset.x = (float) -plane->move_speed * t;
    offset.y = plane->direction * (offset.x);
    sfSprite_move(plane->sprite, offset);
    sfRectangleShape_move(plane->box, offset);
    plane->bounds->left += offset.x;
    plane->bounds->top += offset.y;
    sfVector2f new_pos = sfRectangleShape_getPosition(plane->box);
    free(plane->actual_pos);
    plane->actual_pos = create_vector(new_pos.x, new_pos.y);
    return (1);
}

void aircraft_destroy(aircraft_t *plane)
{
    sfTexture_destroy(plane->txt);
    sfSprite_destroy(plane->sprite);
    sfRectangleShape_destroy(plane->box);
    free(plane->departure);
    free(plane->actual_pos);
    free(plane->arrival);
    free(plane);
}

sfFloatRect* get_bounds_hitbox(sfVector2f** apexes)
{
    sfFloatRect* bounds;
    float min_x, max_x, min_y, max_y;

    max_y = sort_points(apexes, &min_x, &max_x, &min_y);
    bounds = create_rect(min_x, min_y, max_x - min_x, max_y - min_y);
    return (bounds);
}

void change_texture(aircraft_t *plane, char const * filepath)
{
    sfTexture *new_t = sfTexture_createFromFile(filepath, NULL);
    sfTexture_destroy(plane->txt);
    plane->txt = new_t;
    sfSprite_setTexture(plane->sprite, new_t, sfTrue);
}

int sat_intersects_rect(aircraft_t *a, aircraft_t *b)
{
}
