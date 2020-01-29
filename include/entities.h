/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** entities.h
*/

#ifndef MUL_MY_RADAR_2019_ENTITIES_H
#define MUL_MY_RADAR_2019_ENTITIES_H

#define PLANE_IMG   "./assets/plane.png"
#define MAP_IMG     "./assets/mapt3.jpg"
#define TOWER_IMG   "./assets/tower.png"
#define DESTROY_IMG "./assets/clear.png"

#define PLANE_SIZE 20
#define PLANE_SIZE_RECT (sfVector2f) {PLANE_SIZE, PLANE_SIZE}
#define TOWER_SIZE 30
#define TO_SECONDS(x) (float) x / 1000000

typedef struct tower
{
    sfCircleShape* control_area;
    sfTexture* txt;
    sfVector2f* pos;
    sfSprite* sprite;
    float radius;
} tower_t;

typedef struct aircraft
{
    int id;
    sfVector2f* actual_pos;
    sfVector2f* departure;
    sfVector2f* arrival;
    sfVector2f** apexes;
    sfRectangleShape* box;
    double angle;
    sfFloatRect* bounds;
    sfTexture* txt;
    sfSprite* sprite;
    float direction;
    int take_off_time;
    int move_speed;
    int is_destroyed;
    int is_arrived;
} aircraft_t;

typedef struct tower_list
{
    tower_t *tower;
    struct tower_list *next;
} tower_list_t;

typedef struct aircraft_list
{
    aircraft_t *plane;
    struct aircraft_list *next;
} aircraft_list_t;

void tower_destroy(tower_t *tower);
tower_t *create_tower(char **entity_data);

void aircraft_destroy(aircraft_t *plane);
aircraft_t *create_aircraft(char **entity_data);
int move_aircraft(aircraft_t *plane, sfTime);
sfFloatRect* get_bounds_hitbox(sfVector2f** apexes);
int sat_intersects(aircraft_t *a, aircraft_t *b);
void change_texture(aircraft_t *plane, char const * filepath);

void add_tower(tower_list_t **list, tower_t *tower);
void show_towers(tower_list_t *list, int depth);
int get_nb_towers(tower_list_t *list);
void tower_list_destroy(tower_list_t *list);

void add_aircraft(aircraft_list_t **list, aircraft_t *plane);
void show_aircrafts(aircraft_list_t *list, int depth);
int get_nb_aircrafts(aircraft_list_t *list);
void aircraft_list_destroy(aircraft_list_t *list);
void update_aircrafts(aircraft_list_t *list, sfClock* global, sfTime);
void concat_aircraft_lists(aircraft_list_t **l1, aircraft_list_t *l2);
int is_in_list(aircraft_list_t *list, aircraft_list_t *element);

#endif

