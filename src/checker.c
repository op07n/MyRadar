/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** checker.c
*/

#include <stdio.h>
#include "../include/my.h"
#include "../include/radar.h"

static int only_numbers(char **data, int begin)
{
    for (int i = begin; data[i] != NULL; i += 1) {
        if (!my_str_isnum(data[i]))
            return (RETURN_BAD);
    }
    return (RETURN_GOOD);
}

int is_valid_fp(FILE* fp, char *filepath)
{
    if (fp == NULL) {
        print_error("Unable to open the file : ");
        print_error(filepath);
        print_error("\n");
        return (RETURN_BAD);
    }
    return (RETURN_GOOD);
}

int is_valid_entity(char *type)
{
    int good = 0;
    int i;

    for (i = 0; i < NB_VALID_TYPES; i += 1) {
        if (my_strcmp(ENTITY_TYPES[i], type) == 0) {
            good = 1;
            break;
        }
    }
    if (!good) {
        print_error("Invalid entity detected\n");
        return (RETURN_BAD);
    }
    return (i + 1);
}

int is_valid_data(char **entity_data)
{
    int status = only_numbers(entity_data, 1);
    CHECK_ERROR(status);
    return (RETURN_GOOD);
}