/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** renderer.c
*/

#include "../include/my.h"
#include "../include/radar.h"
#include "../include/tree.h"

void draw(sfRenderWindow *window, Grid *qtree, img_list_t *imgs, int *options)
{
    sfRenderWindow_clear(window, sfWhite);
    while (imgs != NULL) {
        sfRenderWindow_drawSprite(window, imgs->sprite, NULL);
        imgs = imgs->next;
    }
    draw_grid(window, qtree, options);
    sfRenderWindow_display(window);
}

void stop_rendering(sfClock* global, sfClock *local, sfRenderWindow* window)
{
    sfClock_destroy(global);
    sfClock_destroy(local);
    sfRenderWindow_destroy(window);
}

void render(tower_list_t **towers, aircraft_list_t **aircrafts, img_list_t
**imgs)
{
    Grid* qtree = create_tree(0, 0, WIDTH, HEIGHT);
    sfRenderWindow *window = create_window(WIDTH, HEIGHT, TITLE);
    aircraft_list_t *out_of_range = NULL;
    Grid* tree_intersects = create_tree(0, 0, WIDTH, HEIGHT);
    aircraft_list_t *tmp;
    sfClock *global = sfClock_create();
    sfClock *local  = sfClock_create();
    int options[2]  = {1, 1};

    add_img(imgs, MAP_IMG);
    while (is_open_window(window)) {
        manage_events(window, options, options + 1);
        grid_reset(qtree);
        grid_insert(qtree, *towers, *aircrafts);
        out_of_range = get_uncontroled_planes(qtree, aircrafts, towers);
        grid_reset(tree_intersects);
        grid_insert(tree_intersects, NULL, out_of_range);
        manage_collisions(tree_intersects, out_of_range,
        sfClock_getElapsedTime(global));
        tmp = *aircrafts;
        while (tmp != NULL) {
            if (is_in_list(out_of_range, tmp))
                sfRectangleShape_setOutlineColor(tmp->plane->box, sfRed);
            if (tmp->plane->is_arrived && !tmp->plane->is_destroyed)
                sfRectangleShape_setOutlineColor(tmp->plane->box, sfMagenta);
            if (tmp->plane->is_destroyed)
                sfRectangleShape_setOutlineColor(tmp->plane->box, sfYellow);
            tmp = tmp->next;
        }
        draw(window, qtree, *imgs, options);
        update_aircrafts(*aircrafts, global, sfClock_getElapsedTime(local));
        sfClock_restart(local);
        print_framerate();
    }
    stop_rendering(global, local, window);
    imgs_destroy(imgs);
    grid_destroy(qtree);
}
