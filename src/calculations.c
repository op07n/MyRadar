/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** calculations.c
*/

#include "../include/my.h"
#include "../include/radar.h"

float get_direction(sfVector2f* a, sfVector2f* b)
{
    return ((b->y - a->y) / (b->x - a->x));
}

sfVector2f* create_vector(float x, float y)
{
    sfVector2f* v = malloc(sizeof(*v));

    v->x = x;
    v->y = y;
    return (v);
}

int is_arrived(sfVector2f *curr, sfVector2f *dep, sfVector2f *arr)
{
    if (dep->x < arr->x && dep->y < arr->y)
        return curr->x >= arr->x && curr->y >= arr->y;
    if (dep->x < arr->x && dep->y > arr->y)
        return curr->x >= arr->x && curr->y <= arr->y;
    if (dep->x > arr->x && dep->y < arr->y)
        return curr->x <= arr->x && curr->y >= arr->y;
    if (dep->x > arr->x && dep->y > arr->y)
        return curr->x <= arr->x && curr->y <= arr->y;
}

float toDegree(double rad)
{
    return (float) (rad * 180 / M_PI);
}

float toRad(double deg)
{
    return (float) (deg * M_PI / 180);
}

int circle_intersects(sfCircleShape* area, sfVector2f *center, aircraft_t
*plane, float radius)
{
    sfVector2f pos_area = sfCircleShape_getPosition(area);
    double distance_centre_point = dist(*plane->actual_pos, *center);
    if (distance_centre_point < radius)
        return (1);
    return (0);
}

double dist(sfVector2f a, sfVector2f b)
{
    return sqrt((double) mpow((int) (b.x - a.x), 2) +
    (double) mpow((int) (b.y - a.y), 2));
}

float sort_points(sfVector2f** apexes, float *min_x, float *max_x, float *min_y)
{
    *min_x = apexes[0]->x;
    *max_x = apexes[0]->x;
    *min_y = apexes[0]->y;
    float max_y = apexes[0]->y;

    for (int i = 1; i < 4; i += 1) {
        if (apexes[i]->x < *min_x)
            *min_x = apexes[i]->x;
        if (apexes[i]->x > *max_x)
            *max_x = apexes[i]->x;
        if (apexes[i]->y < *min_y)
            *min_y = apexes[i]->y;
        if (apexes[i]->y > max_y)
            max_y = apexes[i]->y;
    }
    return (max_y);
}