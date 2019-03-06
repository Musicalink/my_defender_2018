/*
** EPITECH PROJECT, 2019
** defender
** File description:
** include
*/

#ifndef TOTEM_H_
#define TOTEM_H_

#include "defender.h"

typedef struct totem_stats {
    int lvl;
    int atk;
    float spd;
    float cd;
    int max_e;
    int range;
    int cost;
} totem_stats_t;

typedef struct totem {
    char *type;
    int lvl;
    totem_stats_t *stat;
    sfSprite *spr;
    sfTexture *text;
    sfIntRect rect;
    sfVector2f pos;
} totem_t;

static const totem_stats_t STORM_TOTEM_LVL[] = {
    {lvl: 1, atk: 421, spd: 1, cd: 3, max_e: 4, range: 500, cost: 130},
    {lvl: 2, atk: 757, spd: 1, cd: 3, max_e: 5, range: 500, cost: 140},
    {lvl: 3, atk: 1364, spd: 1, cd: 3, max_e: 6, range: 500, cost: 310},
    {lvl: 4, atk: 2455, spd: 1, cd: 3, max_e: 7, range: 500, cost: 650},
    {lvl: 5, atk: 4418, spd: 1, cd: 3, max_e: 9, range: 500, cost: 910},
    {lvl: 6, atk: 7955, spd: 1, cd: 3, max_e: 12, range: 500, cost: 1560},
    {lvl: 7, atk: 14319, spd: 1, cd: 3, max_e: 14, range: 500, cost: 2300},
    {lvl: 8, atk: 25775, spd: 1, cd: 3, max_e: 18, range: 500, cost: 3610},
    {lvl: 9, atk: 46994, spd: 1, cd: 3, max_e: 22, range: 500, cost: 6900},
    {lvl: 10, atk: 83609, spd: 1, cd: 3, max_e: 28, range: 500, cost: 10810}};

static const totem_stats_t BUBBLE_TOTEM_LVL[] = {
    {lvl: 1, atk: 336, spd: 0.75, cd: 2, max_e: 2, range: 500, cost: 230},
    {lvl: 2, atk: 623, spd: 0.7, cd: 2, max_e: 3, range: 500, cost: 250},
    {lvl: 3, atk: 1152, spd: 0.65, cd: 2, max_e: 4, range: 500, cost: 530},
    {lvl: 4, atk: 2132, spd: 0.6, cd: 2, max_e: 5, range: 500, cost: 790},
    {lvl: 5, atk: 3944, spd: 0.55, cd: 2, max_e: 6, range: 500, cost: 1500},
    {lvl: 6, atk: 7298, spd: 0.5, cd: 2, max_e: 7, range: 500, cost: 2400},
    {lvl: 7, atk: 13502, spd: 0.45, cd: 2, max_e: 8, range: 500, cost: 4790},
    {lvl: 8, atk: 24978, spd: 0.4, cd: 2, max_e: 10, range: 500, cost: 6910},
    {lvl: 9, atk: 46210, spd: 0.3, cd: 2, max_e: 12, range: 500, cost: 11690},
    {lvl: 10, atk: 85490, spd: 0.2, cd: 2, max_e: 14, range: 500, cost: 19790}};

static const totem_stats_t FIRE_TOTEM_LVL[] = {
    {lvl: 1, atk: 49, spd: 1, cd: 0.2, max_e: 3, range: 500, cost: 180},
    {lvl: 2, atk: 93, spd: 1, cd: 0.2, max_e: 4, range: 500, cost: 200},
    {lvl: 3, atk: 172, spd: 1, cd: 0.2, max_e: 5, range: 500, cost: 440},
    {lvl: 4, atk: 409, spd: 1, cd: 0.2, max_e: 6, range: 500, cost: 630},
    {lvl: 5, atk: 591, spd: 1, cd: 0.2, max_e: 7, range: 500, cost: 1140},
    {lvl: 6, atk: 1093, spd: 1, cd: 0.2, max_e: 8, range: 500, cost: 1730},
    {lvl: 7, atk: 2025, spd: 1, cd: 0.2, max_e: 10, range: 500, cost: 2790},
    {lvl: 8, atk: 3745, spd: 1, cd: 0.2, max_e: 12, range: 500, cost: 4200},
    {lvl: 9, atk: 6931, spd: 1, cd: 0.2, max_e: 14, range: 500, cost: 6440},
    {lvl: 10, atk: 12823, spd: 1, cd: 0.2, max_e: 18, range: 500, cost: 9510}};

static const totem_stats_t DARK_TOTEM_LVL[] = {
    {lvl: 1, atk: 1010, spd: 1, cd: 4, max_e: 1, range: 500, cost: 410},
    {lvl: 2, atk: 1919, spd: 1, cd: 4, max_e: 1, range: 500, cost: 460},
    {lvl: 3, atk: 3674, spd: 1, cd: 4, max_e: 2, range: 500, cost: 790},
    {lvl: 4, atk: 6929, spd: 1, cd: 4, max_e: 2, range: 500, cost: 1120},
    {lvl: 5, atk: 13167, spd: 1, cd: 4, max_e: 3, range: 500, cost: 1810},
    {lvl: 6, atk: 25019, spd: 1, cd: 4, max_e: 3, range: 500, cost: 2650},
    {lvl: 7, atk: 47535, spd: 1, cd: 4, max_e: 4, range: 500, cost: 4100},
    {lvl: 8, atk: 90316, spd: 1, cd: 4, max_e: 4, range: 500, cost: 6210},
    {lvl: 9, atk: 171601, spd: 1, cd: 4, max_e: 5, range: 500, cost: 9430},
    {lvl: 10, atk: 326044, spd: 1, cd: 4, max_e: 5, range: 500, cost: 14100}};

#endif /*TOTEM_H_*/
