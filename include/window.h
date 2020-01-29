/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** window.h
*/

#ifndef MUL_MY_RADAR_2019_WINDOW_H
#define MUL_MY_RADAR_2019_WINDOW_H

#define WIDTH   1920
#define HEIGHT  1080
#define BPP     32
#define TITLE   "My Radar - Simulated Air Traffic 2D Visualizer"

sfRenderWindow* create_window(int width, int height, char const* title);
int is_open_window(sfRenderWindow* window);

#endif