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
    sfSprite *spr;
    sfTexture *text;
    sfIntRect rect;
    sfVector2f pos;
} monster_t;

int level;

int attack;

float speeder;

float cd;

int max_e;

int range;

int cost;

#endif /*MONSTER_H_*/
