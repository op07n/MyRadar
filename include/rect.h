/*
** EPITECH PROJECT, 2019
** QuadTree
** File description:
** rect.h
*/

#ifndef QUADTREE_RECT_H
#define QUADTREE_RECT_H

#include <SFML/Graphics.h>

sfFloatRect* create_rect(float x, float y, float w, float h);
void rect_destroy(sfFloatRect* rect);
int rect_intersects(sfFloatRect* a, sfFloatRect* b);
int rect_contains(sfFloatRect* rect, float x, float y);

#endif
