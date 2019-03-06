/*
** EPITECH PROJECT, 2019
** defender
** File description:
** include
*/

#ifndef MONSTER_H_
#define MONSTER_H_

typedef struct monster {
    char *type;
    int speed;
    int health;
    int armor;
    int a_speed;
    int a_damage;
} monster_t;

#endif /*MONSTER_H_*/
