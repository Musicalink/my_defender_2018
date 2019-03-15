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
    int rng;
    int cst;
} totem_stats_t;

typedef struct totem {
    char *type;
    int lvl;
    float current_cd;
    int current_er;
    totem_stats_t *stat;
    sfSprite *spr;
    sfTexture *text;
    sfIntRect rect;
    sfVector2f pos;
    sfCircleShape *circle;
} totem_t;

static const totem_stats_t STORM_TOTEM_LVL[] = {
    {.lvl = 1, .atk = 421, .spd = 0, .cd = 3, 4, .rng = 200, .cst = 130},
    {.lvl = 2, .atk = 757, .spd = 0, .cd = 3, 5, .rng = 200, .cst = 140},
    {.lvl = 3, .atk = 1364, .spd = 0, .cd = 3, 6, .rng = 200, .cst = 310},
    {.lvl = 4, .atk = 2455, .spd = 0, .cd = 3, 7, .rng = 200, .cst = 650},
    {.lvl = 5, .atk = 4418, .spd = 0, .cd = 3, 9, .rng = 200, .cst = 910},
    {.lvl = 6, .atk = 7955, .spd = 0, .cd = 3, 12, .rng = 200, .cst = 1560},
    {.lvl = 7, .atk = 14319, .spd = 0, .cd = 3, 14, .rng = 200, .cst = 2300},
    {.lvl = 8, .atk = 25775, .spd = 0, .cd = 3, 18, .rng = 200, .cst = 3610},
    {.lvl = 9, .atk = 46994, .spd = 0, .cd = 3, 22, .rng = 200, .cst = 6900},
    {.lvl = 10, .atk = 83609, .spd = 0, .cd = 3, 28, .rng = 200, .cst = 10810}};

static const totem_stats_t BUBBLE_TOTEM_LVL[] = {
    {.lvl = 1, .atk = 336, .spd = 1, .cd = 2, 1, .rng = 200, .cst = 230},
    {.lvl = 2, .atk = 623, .spd = 1, .cd = 2, 2, .rng = 200, .cst = 250},
    {.lvl = 3, .atk = 1152, .spd = 2, .cd = 2, 3, .rng = 200, .cst = 530},
    {.lvl = 4, .atk = 2132, .spd = 2, .cd = 2, 4, .rng = 200, .cst = 790},
    {.lvl = 5, .atk = 3944, .spd = 3, .cd = 2, 5, .rng = 200, .cst = 1500},
    {.lvl = 6, .atk = 7298, .spd = 3, .cd = 2, 6, .rng = 200, .cst = 2400},
    {.lvl = 7, .atk = 13502, .spd = 3, .cd = 2, 7, .rng = 200, .cst = 4790},
    {.lvl = 8, .atk = 24978, .spd = 4, .cd = 2, 8, .rng = 200, .cst = 6910},
    {.lvl = 9, .atk = 46210, .spd = 4, .cd = 2, 9, .rng = 200, .cst = 11690},
    {.lvl = 10, .atk = 85490, .spd = 5, .cd = 2, 10, .rng = 200, .cst = 19790}};

static const totem_stats_t FIRE_TOTEM_LVL[] = {
    {.lvl = 1, .atk = 79, .spd = 0, .cd = 0.5, 1, .rng = 200, .cst = 180},
    {.lvl = 2, .atk = 133, .spd = 0, .cd = 0.45, 1, .rng = 200, .cst = 200},
    {.lvl = 3, .atk = 272, .spd = 0, .cd = 0.45, 1, .rng = 200, .cst = 440},
    {.lvl = 4, .atk = 409, .spd = 0, .cd = 0.4, 1, .rng = 200, .cst = 630},
    {.lvl = 5, .atk = 591, .spd = 0, .cd = 0.4, 1, .rng = 200, .cst = 1140},
    {.lvl = 6, .atk = 1093, .spd = 0, .cd = 0.3, 1, .rng = 200, .cst = 1730},
    {.lvl = 7, .atk = 2025, .spd = 0, .cd = 0.3, 1, .rng = 200, .cst = 2790},
    {.lvl = 8, .atk = 3745, .spd = 0, .cd = 0.25, 2, .rng = 200, .cst = 4200},
    {.lvl = 9, .atk = 6931, .spd = 0, .cd = 0.25, 2, .rng = 200, .cst = 6440},
    {.lvl = 10, .atk = 7823, .spd = 0, .cd = 0.2, 3, .rng = 200, .cst = 9510}};

static const totem_stats_t DARK_TOTEM_LVL[] = {
    {.lvl = 1, .atk = 1010, .spd = 0, .cd = 4, 1, .rng = 200, .cst = 410},
    {.lvl = 2, .atk = 1919, .spd = 0, .cd = 4, 1, .rng = 300, .cst = 460},
    {.lvl = 3, .atk = 3674, .spd = 0, .cd = 4, 1, .rng = 300, .cst = 790},
    {.lvl = 4, .atk = 6929, .spd = 0, .cd = 4, 1, .rng = 400, .cst = 1120},
    {.lvl = 5, .atk = 13167, .spd = 0, .cd = 4, 1, .rng = 400, .cst = 1810},
    {.lvl = 6, .atk = 25019, .spd = 0, .cd = 4, 1, .rng = 500, .cst = 2650},
    {.lvl = 7, .atk = 47535, .spd = 0, .cd = 4, 1, .rng = 500, .cst = 4100},
    {.lvl = 8, .atk = 90316, .spd = 0, .cd = 4, 1, .rng = 500, .cst = 6210},
    {.lvl = 9, .atk = 171601, .spd = 0, .cd = 4, 1, .rng = 600, .cst = 9430},
    {.lvl = 10, .atk = 326044, .spd = 0, .cd = 4, 1, .rng = 600, .cst = 14100}};

static const sfVector2f TOTEM_POS[] = {{.x = 67, .y = 61}, {.x = 493, .y = 45},
    {.x = 976, .y = 45}, {.x = 1420, .y = 45}, {.x = 1795, .y = 45},
    {.x = 1795, .y = 405}, {.x = 1795, .y = 784}, {.x = 1782, .y = 961},
    {.x = 1540, .y = 980}, {.x = 1090, .y = 980}, {.x = 661, .y = 980},
    {.x = 37, .y = 381}, {.x = 45, .y = 771}, {.x = 409, .y = 798},
    {.x = 786, .y = 795}, {.x = 1260, .y = 795}, {.x = 1630, .y = 795},
    {.x = 1630, .y = 480}, {.x = 1630, .y = 219}, {.x = 1300, .y = 220},
    {.x = 912, .y = 220}, {.x = 574, .y = 220}, {.x = 211, .y = 220},
    {.x = 234, .y = 600}, {.x = 477, .y = 615}, {.x = 756, .y = 615},
    {.x = 1077, .y = 615}, {.x = 1417, .y = 615}, {.x = 406, .y = 409},
    {.x = 616, .y = 409}, {.x = 925, .y = 409}, {.x = 1194, .y = 409},
    {.x = 0, .y = 0,}};

#endif /*TOTEM_H_*/
