/*
** EPITECH PROJECT, 2019
** death
** File description:
** defender
*/

#include "defender.h"

void check_explose(monster_t *elem, player_t *player)
{
    player->life -= (elem->road == 9 && elem->alive == 1) ? elem->health : 0;
    if (elem->road == 9 && elem->alive == 1) {
        player->lifebar->green_r.width = take_percentage(player);
        sfSprite_setTextureRect(player->lifebar->green_s,
            player->lifebar->green_r);
        player->monsters->penguin_s = generate_sound(PENGUIN_S, 50);
        sfSound_play(player->monsters->penguin_s->sound);
    }
    elem->health = (elem->road == 9) ? -1 : elem->health;
    elem->alive = (elem->road == 9) ? 0 : elem->alive;
}

