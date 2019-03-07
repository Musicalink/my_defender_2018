/*
** EPITECH PROJECT, 2023
** MUL_my_defender_2018
** File description:
** Created by mcarpentier
*/

#include "defender.h"

sfText *gen_text(char *s, int y, int x)
{
    sfText *text = sfText_create();
    sfVector2f size;
    sfVector2f pos;
    sfFont *font = sfFont_createFromFile(FONT);

    size.x = 1.5;
    size.y = 1.5;
    pos.x = x;
    pos.y = y;
    sfText_setString(text, s);
    sfText_setScale(text, size);
    sfText_setPosition(text, pos);
    sfText_setFont(text, font);
    return (text);
}

totem_t *generate_totem(float y, float x)
{
    totem_t *totem = malloc(sizeof(totem_t));

    totem->type = my_strdup("none");
    totem->stat = malloc(sizeof(totem_stats_t));
    totem->stat->lvl = 0;
    totem->lvl = 0;
    totem->stat->atk = 0;
    totem->stat->spd = 0;
    totem->stat->cd = 0;
    totem->stat->max_e = 0;
    totem->stat->range = 0;
    totem->stat->cost = 0;
    totem->spr = sfSprite_create();
    totem->pos.x = x + 7;
    totem->pos.y = y - 80;
    sfSprite_setPosition(totem->spr, totem->pos);
    totem->pos.y = y;
    totem->pos.x = x;
    return (totem);
}

/*
int lvl;
int atk;
float spd;
float cd;
int max_e;
int range;
int cost;
 */