/*
** EPITECH PROJECT, 2023
** MUL_my_defender_2018
** File description:
** Created by mcarpentier
*/

#include "defender.h"

totem_t *s_up(totem_t *totem, player_t *player)
{
    if (player->money < STORM_TOTEM_LVL[totem->lvl].cst)
        return (totem);
    totem->stat->atk = STORM_TOTEM_LVL[totem->lvl].atk;
    totem->stat->spd = STORM_TOTEM_LVL[totem->lvl].spd;
    totem->stat->cd = STORM_TOTEM_LVL[totem->lvl].cd;
    totem->stat->max_e = STORM_TOTEM_LVL[totem->lvl].max_e;
    totem->stat->rng = STORM_TOTEM_LVL[totem->lvl].rng;
    totem->stat->cst = STORM_TOTEM_LVL[totem->lvl].cst;
    totem->stat->lvl = STORM_TOTEM_LVL[totem->lvl].lvl;
    totem->lvl++;
    player->money -= totem->stat->cst;
    gen_circle(totem);
    return (totem);
}

totem_t *d_up(totem_t *totem, player_t *player)
{
    if (player->money < DARK_TOTEM_LVL[totem->lvl].cst)
        return (totem);
    totem->stat->atk = DARK_TOTEM_LVL[totem->lvl].atk;
    totem->stat->spd = DARK_TOTEM_LVL[totem->lvl].spd;
    totem->stat->cd = DARK_TOTEM_LVL[totem->lvl].cd;
    totem->stat->max_e = DARK_TOTEM_LVL[totem->lvl].max_e;
    totem->stat->rng = DARK_TOTEM_LVL[totem->lvl].rng;
    totem->stat->cst = DARK_TOTEM_LVL[totem->lvl].cst;
    totem->stat->lvl = DARK_TOTEM_LVL[totem->lvl].lvl;
    totem->lvl++;
    player->money -= totem->stat->cst;
    gen_circle(totem);
    return (totem);
}

totem_t *b_up(totem_t *totem, player_t *player)
{
    if (player->money < BUBBLE_TOTEM_LVL[totem->lvl].cst)
        return (totem);
    totem->stat->atk = BUBBLE_TOTEM_LVL[totem->lvl].atk;
    totem->stat->spd = BUBBLE_TOTEM_LVL[totem->lvl].spd;
    totem->stat->cd = BUBBLE_TOTEM_LVL[totem->lvl].cd;
    totem->stat->max_e = BUBBLE_TOTEM_LVL[totem->lvl].max_e;
    totem->stat->rng = BUBBLE_TOTEM_LVL[totem->lvl].rng;
    totem->stat->cst = BUBBLE_TOTEM_LVL[totem->lvl].cst;
    totem->stat->lvl = BUBBLE_TOTEM_LVL[totem->lvl].lvl;
    totem->lvl++;
    player->money -= totem->stat->cst;
    gen_circle(totem);
    return (totem);
}

totem_t *f_up(totem_t *totem, player_t *player)
{
    if (player->money < FIRE_TOTEM_LVL[totem->lvl].cst)
        return (totem);
    totem->stat->atk = FIRE_TOTEM_LVL[totem->lvl].atk;
    totem->stat->spd = FIRE_TOTEM_LVL[totem->lvl].spd;
    totem->stat->cd = FIRE_TOTEM_LVL[totem->lvl].cd;
    totem->stat->max_e = FIRE_TOTEM_LVL[totem->lvl].max_e;
    totem->stat->rng = FIRE_TOTEM_LVL[totem->lvl].rng;
    totem->stat->cst = FIRE_TOTEM_LVL[totem->lvl].cst;
    totem->stat->lvl = FIRE_TOTEM_LVL[totem->lvl].lvl;
    totem->lvl++;
    player->money -= totem->stat->cst;
    gen_circle(totem);
    return (totem);
}