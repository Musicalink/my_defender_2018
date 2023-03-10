/*
** EPITECH PROJECT, 2019
** defender
** File description:
** include
*/

#ifndef MONSTER_H_
#define MONSTER_H_

typedef struct my_sound {
    sfSound *sound;
    sfSoundBuffer *buffer;
} my_sound_t;

typedef struct monster {
    char *type;
    int alive;
    int speed;
    int health;
    int armor;
    int a_speed;
    int a_damage;
    int road;
    int value;
    sfSprite *spr;
    sfIntRect rect;
    sfVector2f pos;
    struct monster *next;
    struct monster *prev;
} monster_t;

typedef struct list_m {
    int size;
    monster_t *head;
    monster_t *tail;
    sfTexture *penguin;
    sfTexture *penguin_r;
    sfTexture *minotaur;
    sfTexture *minotaur_r;
    my_sound_t *penguin_s;
    my_sound_t *minotaur_s;
    my_sound_t *explode;
} list;

int level;

int attack;

float speeder;

float cd;

int max_e;

int rng;

int cst;

#endif /*MONSTER_H_*/
