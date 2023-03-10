/*
** EPITECH PROJECT, 2023
** MUL_my_defender_2018
** File description:
** Created by mcarpentier
*/

#include "defender.h"

int is_enough_money(player_t *player, char *type)
{
    int money = 0;

    money = (my_strcmp(type, "fire") == 0) ? FIRE_TOTEM_LVL[0].cst : money;
    money = (my_strcmp(type, "dark") == 0) ? DARK_TOTEM_LVL[0].cst : money;
    money = (my_strcmp(type, "bubble") == 0) ? BUBBLE_TOTEM_LVL[0].cst : money;
    money = (my_strcmp(type, "storm") == 0) ? STORM_TOTEM_LVL[0].cst : money;
    return ((player->money < money) ? 0 : 1);
}

char *find_totem_texture(char *type, char *s)
{
    s = (my_strcmp(type, "fire") == 0) ? my_strdup(FIRE_T) : s;
    s = (my_strcmp(type, "dark") == 0) ? my_strdup(DARK_T) : s;
    s = (my_strcmp(type, "bubble") == 0) ? my_strdup(BUBBLE_T) : s;
    s = (my_strcmp(type, "storm") == 0) ? my_strdup(STORM_T) : s;
    return (s);
}

totem_t *create_totem(totem_t *totem, char *type)
{
    char *s = NULL;

    totem->type = my_strdup(type);
    totem->lvl = 0;
    s = find_totem_texture(type, s);
    totem->text = sfTexture_createFromFile(s, NULL);
    sfSprite_setTexture(totem->spr, totem->text, sfTrue);
    totem->rect = create_rect(0, 0, 56, 120);
    sfSprite_setTextureRect(totem->spr, totem->rect);
    totem->level = sfText_create();
    totem->cost = sfText_create();
    totem->level = gen_text("1", 1010, 1630);
    totem->cost = gen_text("", 1010, 1810);
    sfText_setColor(totem->cost, sfYellow);
    return (totem);
}

totem_t *build_totem(totem_t *totem, char *type, player_t *player)
{
    char *s = NULL;
    int money;

    if (is_enough_money(player, type) == 0)
        return (totem);
    if (totem->lvl > 0)
        upgrade_totem(totem, type, player);
    totem = create_totem(totem, type);
    totem = (my_strcmp(type, "fire") == 0) ? f_up(totem, player) : totem;
    totem = (my_strcmp(type, "dark") == 0) ? d_up(totem, player) : totem;
    totem = (my_strcmp(type, "bubble") == 0) ? b_up(totem, player) : totem;
    totem = (my_strcmp(type, "storm") == 0) ? s_up(totem, player) : totem;
    free(s);
    return (totem);
}

totem_t *upgrade_totem(totem_t *tot, char *type, player_t *p)
{
    if (my_strcmp(tot->type, type) != 0) {
        if (my_strcmp(tot->type, "none") == 0)
            tot = build_totem(tot, type, p);
    } else {
        if (tot->lvl >= 10)
            return (tot);
        tot = (my_strcmp(tot->type, "storm")) == 0 ? s_up(tot, p) : tot;
        tot = (my_strcmp(tot->type, "dark")) == 0 ? d_up(tot, p) : tot;
        tot = (my_strcmp(tot->type, "bubble")) == 0 ? b_up(tot, p) : tot;
        tot = (my_strcmp(tot->type, "fire")) == 0 ? f_up(tot, p) : tot;
    }
    return (tot);
}