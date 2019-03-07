/*
** EPITECH PROJECT, 2023
** MUL_my_defender_2018
** File description:
** Created by mcarpentier
*/

#include "defender.h"

totem_t *s_up(totem_t *totem, player_t *player)
{
    if (player->money < STORM_TOTEM_LVL[totem->lvl].cost)
        return (totem);
    totem->stat->atk = STORM_TOTEM_LVL[totem->lvl].atk;
    totem->stat->spd = STORM_TOTEM_LVL[totem->lvl].spd;
    totem->stat->cd = STORM_TOTEM_LVL[totem->lvl].cd;
    totem->stat->max_e = STORM_TOTEM_LVL[totem->lvl].max_e;
    totem->stat->range = STORM_TOTEM_LVL[totem->lvl].range;
    totem->stat->cost = STORM_TOTEM_LVL[totem->lvl].cost;
    totem->stat->lvl = STORM_TOTEM_LVL[totem->lvl].lvl;
    totem->lvl++;
    player->money -= totem->stat->cost;
    return (totem);
}

totem_t *d_up(totem_t *totem, player_t *player)
{
    if (player->money < DARK_TOTEM_LVL[totem->lvl].cost)
        return (totem);
    totem->stat->atk = DARK_TOTEM_LVL[totem->lvl].atk;
    totem->stat->spd = DARK_TOTEM_LVL[totem->lvl].spd;
    totem->stat->cd = DARK_TOTEM_LVL[totem->lvl].cd;
    totem->stat->max_e = DARK_TOTEM_LVL[totem->lvl].max_e;
    totem->stat->range = DARK_TOTEM_LVL[totem->lvl].range;
    totem->stat->cost = DARK_TOTEM_LVL[totem->lvl].cost;
    totem->stat->lvl = DARK_TOTEM_LVL[totem->lvl].lvl;
    totem->lvl++;
    player->money -= totem->stat->cost;
    return (totem);
}

totem_t *b_up(totem_t *totem, player_t *player)
{
    if (player->money < BUBBLE_TOTEM_LVL[totem->lvl].cost)
        return (totem);
    totem->stat->atk = BUBBLE_TOTEM_LVL[totem->lvl].atk;
    totem->stat->spd = BUBBLE_TOTEM_LVL[totem->lvl].spd;
    totem->stat->cd = BUBBLE_TOTEM_LVL[totem->lvl].cd;
    totem->stat->max_e = BUBBLE_TOTEM_LVL[totem->lvl].max_e;
    totem->stat->range = BUBBLE_TOTEM_LVL[totem->lvl].range;
    totem->stat->cost = BUBBLE_TOTEM_LVL[totem->lvl].cost;
    totem->stat->lvl = BUBBLE_TOTEM_LVL[totem->lvl].lvl;
    totem->lvl++;
    player->money -= totem->stat->cost;
    return (totem);
}

totem_t *f_up(totem_t *totem, player_t *player)
{
    if (player->money < FIRE_TOTEM_LVL[totem->lvl].cost)
        return (totem);
    totem->stat->atk = FIRE_TOTEM_LVL[totem->lvl].atk;
    totem->stat->spd = FIRE_TOTEM_LVL[totem->lvl].spd;
    totem->stat->cd = FIRE_TOTEM_LVL[totem->lvl].cd;
    totem->stat->max_e = FIRE_TOTEM_LVL[totem->lvl].max_e;
    totem->stat->range = FIRE_TOTEM_LVL[totem->lvl].range;
    totem->stat->cost = FIRE_TOTEM_LVL[totem->lvl].cost;
    totem->stat->lvl = FIRE_TOTEM_LVL[totem->lvl].lvl;
    totem->lvl++;
    player->money -= totem->stat->cost;
    return (totem);
}