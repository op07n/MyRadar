/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** res.h
*/

#ifndef MUL_MY_RADAR_2019_RES_H
#define MUL_MY_RADAR_2019_RES_H

typedef struct text
{
    int uid;
    sfText* text;
    sfFont* font;
    struct text *next;
} text_list_t;

typedef struct img
{
    sfTexture *txt;
    sfSprite *sprite;
    struct img *next;
} img_list_t;

#endif
