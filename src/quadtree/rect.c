/*
** EPITECH PROJECT, 2019
** QuadTree
** File description:
** rect.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../include/my.h"
#include "../../include/rect.h"

sfFloatRect* create_rect(float x, float y, float w, float h)
{
    sfFloatRect* area = malloc(sizeof(*area));

    area->left = x;
    area->top = y;
    area->width = w;
    area->height = h;
    return (area);
}

void rect_destroy(sfFloatRect* rect)
{
    free(rect);
}

int aabb_intersects(sfFloatRect* a, sfFloatRect* b)
{

}

int rect_contains(sfFloatRect* rect, float x, float y)
{
    return (x >= rect->left && x < rect->left + rect->width
            && y >= rect->top && y < rect->top + rect->height);
}

int rect_intersects(sfFloatRect *boundary, sfFloatRect *range)
{
    if (boundary->left > range->left + range->width
    || range->left > boundary->left + boundary->width) {
        return (0);
    }
    if (boundary->top > range->top + range->height
    || range->top > boundary->top + boundary->height) {
        return (0);
    }
    return (1);
}