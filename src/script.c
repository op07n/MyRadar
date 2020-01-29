/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** script.c
*/

#include <stdio.h>
#include "../include/my.h"
#include "../include/radar.h"

int create_data(char **entity_data, tower_list_t **towers, aircraft_list_t
**aircrafts)
{
    int status = 0;
    int type = is_valid_entity(entity_data[0]);
    aircraft_t *plane;
    tower_t *tower;

    CHECK_ERROR(type);
    status = is_valid_data(entity_data);
    CHECK_ERROR(status);
    if (type == 1) {
        tower = create_tower(entity_data);
        add_tower(towers, tower);
    } else {
        plane = create_aircraft(entity_data);
        add_aircraft(aircrafts, plane);
    }
    return (RETURN_GOOD);
}

int parse_line(char *entity, tower_list_t **towers, aircraft_list_t **aircrafts)
{
    char **entity_data = my_str_split2char(entity, ' ', '\t');
    int status = create_data(entity_data, towers, aircrafts);
    arr2d_destroy((void **) entity_data);
    free(entity);
    if (!status)
        return (RETURN_BAD);
    return (RETURN_GOOD);
}

int parse_file(char *path, tower_list_t **towers, aircraft_list_t **aircrafts)
{
    FILE* fp;
    char *entity = NULL;
    size_t size_line = 0;
    int line = 0, status = 0;

    fp = fopen(path, "r");
    if (!is_valid_fp(fp, path))
        return (RETURN_BAD);
    while ((line = getline(&entity, &size_line, fp)) != -1) {
        if (entity[line - 1] == '\n')
            entity[line - 1] = '\0';
        status = parse_line(entity, towers, aircrafts);
        entity = NULL;
        if (!status)
            return (RETURN_BAD);
    }
    fclose(fp);
    return (RETURN_GOOD);
}
