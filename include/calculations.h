/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** calculations.h
*/

#ifndef MUL_MY_RADAR_2019_CALCULATIONS_H
#define MUL_MY_RADAR_2019_CALCULATIONS_H

float get_direction(sfVector2f* a, sfVector2f* b);
sfVector2f* create_vector(float x, float y);
float toDegree(double rad);
int circle_intersects(sfCircleShape*, sfVector2f*, aircraft_t *, float);
float toRad(double deg);
float sort_points(sfVector2f** apexes, float *min_x, float *max_x, float
*min_y);
double dist(sfVector2f a, sfVector2f b);

#endif
