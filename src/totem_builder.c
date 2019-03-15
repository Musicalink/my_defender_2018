/*
** EPITECH PROJECT, 2023
** MUL_my_defender_2018
** File description:
** Created by mcarpentier
*/

#include "defender.h"

int is_it_in(int to_try, int exone, int extwo)
{
    if (to_try > exone && to_try < extwo)
        return (1);
    return (0);
}

totem_t *chose_totem(totem_t *totem, sfVector2i cursor_pos, player_t *player)
{
    int dark = 0;
    int fire = 0;
    int storm = 0;
    int bubble = 0;

    dark += is_it_in(cursor_pos.x, 1632, 1747);
    dark += is_it_in(cursor_pos.y, 797, 918);
    bubble += is_it_in(cursor_pos.x, 1792, 1907);
    bubble += is_it_in(cursor_pos.y, 797, 918);
    fire += is_it_in(cursor_pos.x, 1792, 1907);
    fire += is_it_in(cursor_pos.y, 943, 1063);
    storm += is_it_in(cursor_pos.x, 1632, 1747);
    storm += is_it_in(cursor_pos.y, 943, 1063);
    totem = (storm == 2) ? build_totem(totem, "storm", player) : totem;
    totem = (bubble == 2) ? build_totem(totem, "bubble", player) : totem;
    totem = (dark == 2) ? build_totem(totem, "dark", player) : totem;
    totem = (fire == 2) ? build_totem(totem, "fire", player) : totem;
    return (totem);
}