cmake_minimum_required(VERSION 3.15)
project(MUL_my_radar_2019 C)

set(CMAKE_C_STANDARD 99)

add_executable(MUL_my_radar_2019
        include/tree.h include/checker.h include/calculations.h
        include/entities.h include/radar.h include/my.h include/my_macros.h
        include/rect.h include/res.h include/window.h include/script.h
        include/img_list.h

        src/main.c src/script.c src/radar.c src/calculations.c src/checker.c
        src/tower/tower.c src/tower/tower_list.c
        src/aircraft/aircraft.c src/aircraft/aircraft_list.c
        src/window/window.c
        src/quadtree/qtree.c src/quadtree/rect.c src/imgs/img_list.c include/img_list.h src/renderer.c src/controls.c src/aircraft/aircraft_list_op.c src/aircraft/aircraft_op.c src/others.c src/quadtree/collision.c src/quadtree/qtree_op.c)