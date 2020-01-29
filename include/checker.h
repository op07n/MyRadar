/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** checker.h
*/

#ifndef MUL_MY_RADAR_2019_CHECKER_H
#define MUL_MY_RADAR_2019_CHECKER_H

#include <stdio.h>

int is_valid_fp(FILE* fp, char *filepath);
int is_valid_entity(char *type);

int is_valid_data(char **entity_data);

int is_arrived(sfVector2f *curr, sfVector2f *dep, sfVector2f *arr);

static const char *ENTITY_TYPES[] = {"T", "A"};
static const int NB_VALID_TYPES = 2;

#endif
