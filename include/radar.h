/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** radar.h
*/

#ifndef MUL_MY_RADAR_2019_RADAR_H
#define MUL_MY_RADAR_2019_RADAR_H

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <math.h>
#include "window.h"
#include "entities.h"
#include "script.h"
#include "res.h"
#include "checker.h"
#include "calculations.h"
#include "img_list.h"


#define EXIT_FAIL  84
#define RETURN_BAD  0
#define RETURN_GOOD 1
#define CHECK_ERROR(x) if (!x) { return (RETURN_BAD); }

int run_radar(char *filepath);
void manage_events(sfRenderWindow *window, int *show_sprite, int *show_hitbox);
void render(tower_list_t **towers, aircraft_list_t **aircrafts, img_list_t**);
void print_framerate(void);

#endif