/*
** EPITECH PROJECT, 2023
** MUL_my_defender_2018
** File description:
** Created by mcarpentier
*/

#include "defender.h"

totem_t *build_totem(totem_t *totem, char *type)
{
    char *s = NULL;

    if (totem->lvl > 0)
        upgrade_totem(totem, type);
    totem->type = type;
    totem->lvl = 0;
    s = (my_strcmp(type, "fire") == 0) ? my_strdup(FIRE_T) : s;
    s = (my_strcmp(type, "dark") == 0) ? my_strdup(DARK_T) : s;
    s = (my_strcmp(type, "bubble") == 0) ? my_strdup(BUBBLE_T) : s;
    s = (my_strcmp(type, "storm") == 0) ? my_strdup(STORM_T) : s;
    totem->text = sfTexture_createFromFile(s, NULL);
    sfSprite_setTexture(totem->spr, totem->text, sfTrue);
    /*    totem = s_up(totem);
        totem = f_up(totem);
        totem = b_up(totem);
        totem = d_up(totem);*/
    totem->rect = create_IntRect(0, 0, 56, 120);
    sfSprite_setTextureRect(totem->spr, totem->rect);
    totem = (my_strcmp(type, "fire") == 0) ? f_up(totem) : totem;
    totem = (my_strcmp(type, "dark") == 0) ? d_up(totem) : totem;
    totem = (my_strcmp(type, "bubble") == 0) ? b_up(totem) : totem;
    totem = (my_strcmp(type, "storm") == 0) ? s_up(totem) : totem;
    free(s);
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