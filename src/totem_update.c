/*
** EPITECH PROJECT, 2023
** MUL_my_defender_2018
** File description:
** Created by mcarpentier
*/

#include "defender.h"

totem_t *build_totem(totem_t *totem, char *type)
{
    totem->type = type;
    totem->lvl = 1;
    return (totem);
}

totem_t *upgrade_totem(totem_t *totem, char *type)
{
    if (my_strcmp(totem->type, type) != 0) {
        if (my_strcmp(totem->type, "none") == 0)
            totem = build_totem(totem, type);
    } else {
        totem = (my_strcmp(totem->type, "storm")) == 0 ? s_up(totem) : totem;
        totem = (my_strcmp(totem->type, "dark")) == 0 ? d_up(totem) : totem;
        totem = (my_strcmp(totem->type, "bubble")) == 0 ? b_up(totem) : totem;
        totem = (my_strcmp(totem->type, "fire")) == 0 ? f_up(totem) : totem;
    }
    return (totem);
}

/*
    int lvl;
    int attack;
    float speeder;
    float cd;
    int max_e;
    int range;
    int cost;
    */