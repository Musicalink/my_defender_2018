/*
** EPITECH PROJECT, 2019
** death
** File description:
** defender
*/

#include "defender.h"

void check_explose(monster_t *elem, player_t *player)
{
    sfIntRect green_r;
    player->life -= (elem->road == 9 && elem->alive == 1) ? elem->health : 0;
    if (elem->road == 9 && elem->alive == 1) {
        player->lifebar->green_r.width = take_percentage(player);
        green_r = player->lifebar->green_r;
        sfSprite_setTextureRect(player->lifebar->green_s, green_r);
        player->monsters->explode = generate_sound(EXPLODE, 100);
        sfSound_play(player->monsters->explode->sound);
    }
    elem->health = (elem->road == 9) ? -1 : elem->health;
    elem->alive = (elem->road == 9) ? 0 : elem->alive;
}

