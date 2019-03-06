/*
** EPITECH PROJECT, 2019
** defender
** File description:
** include
*/

#ifndef TOTEM_H_
#define TOTEM_H_

typedef struct totem {
    char *type;
    int level;
    int power;
    int cooldown;
    int max_enemies;
    int range;
} totem_t;

#endif /*TOTEM_H_*/
