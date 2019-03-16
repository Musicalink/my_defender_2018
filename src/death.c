/*
** EPITECH PROJECT, 2019
** death
** File description:
** defender
*/

#include "defender.h"

void check_explose(monster_t *elem, player_t *player)
{
    player->life -= (elem->road == 9 && elem->alive == 1) ? 500 : 0;
    if (elem->road == 9 && elem->alive == 1) {
        printf("\n\nBOUM\n\nNEXUS IS NOW %d/5000 HP\n\n", player->life);
        player->monsters->penguin_s = generate_sound(PENGUIN_S, 50);
        sfSound_play(player->monsters->penguin_s->sound);
    }
    elem->alive = (elem->road == 9) ? 0 : elem->alive;
}

