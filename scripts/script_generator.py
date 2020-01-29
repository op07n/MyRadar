#!/usr/bin/env python3

import sys
import random


class Vector:
    def __init__(self, x, y):
        self.x = x
        self.y = y


class Tower:

    def __init__(self, location: Vector, radius: int):
        self.location = location
        self.radius = radius

    def __str__(self):
        return str("T {} {} {}".format(self.location.x, self.location.y,
                                       self.radius))


class Aircraft:

    def __init__(self, dep: Vector, arr: Vector, speed: int, take_off: int):
        self.dep = dep
        self.arr = arr
        self.move_speed = speed
        self.take_off = take_off

    def __str__(self):
        return str("A {} {} {} {} {} {}".format(self.dep.x, self.dep.y,
                                                self.arr.x, self.arr.y,
                                                self.move_speed, self.take_off))


def generate_aircraft(nb: int):
    aircrafts = list()
    for i in range(nb):
        dep = Vector(random.randint(1, 1900), random.randint(1, 1060))
        arr = Vector(random.randint(1, 1900), random.randint(1, 1060))
        aircraft = Aircraft(dep, arr, random.randint(10, 20),
                            random.randint(0, 5))
        aircrafts.append(aircraft)
    return aircrafts


def generate_tower(nb: int):
    towers = list()
    for i in range(nb):
        loc = Vector(random.randint(1, 1900), random.randint(1, 1060))
        radius = random.randint(2, 20)
        tower = Tower(loc, radius)
        towers.append(tower)
    return towers


def generate(ac, av):
    aircrafts = list()
    towers = list()

    if ac == 5:
        if av[1] == '-t':
            towers = generate_tower(int(av[4]))
        if av[3] == '-a':
            aircrafts = generate_aircraft(int(av[2]))
        if av[1] == '-a':
            aircrafts = generate_aircraft(int(av[2]))
        if av[3] == '-t':
            towers = generate_tower(int(av[4]))
    elif ac == 3:
        if av[1] == '-a':
            aircrafts = generate_aircraft(int(av[2]))
        elif av[1] == '-t':
            towers = generate_tower(int(av[2]))
    return aircrafts, towers


def main(ac, av):
    if ac < 3:
        print("Not enough arguments : -h for help")
        return
    aircrafts, towers = generate(ac, av)
    with open('./r_scripts', 'w+') as f:
        for i in range(len(aircrafts)):
            f.write('{}\n'.format(aircrafts[i]))
        for i in range(len(towers)):
            f.write('{}\n'.format(towers[i]))
    print("Air Traffic script generation completed !")


if __name__ == '__main__':
    main(len(sys.argv), sys.argv)
