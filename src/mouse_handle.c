/*
** EPITECH PROJECT, 2023
** MUL_my_defender_2018
** File description:
** Created by mcarpentier
*/

#include "defender.h"

void market_handler(player_t *player, sfVector2i cursor)
{
    int std = player->m_sel;
    int is_it_touched = 0;

    is_it_touched += is_it_in(cursor.x, 1620, 1920);
    is_it_touched += is_it_in(cursor.y, 780, 1080);
    player->market_d = (is_it_touched == 2) ? 1 : 0;
    player->totems[std] = chose_totem(player->totems[std], cursor, player);
    player->market_d = 0;
}

int upgrade_handler(player_t *player, sfVector2i cursor)
{
    int std = player->m_sel;
    int is_it_touched = 0;
    char *type = my_strdup(player->totems[std]->type);

    is_it_touched += is_it_in(cursor.x, 1620, 1920);
    is_it_touched += is_it_in(cursor.y, 780, 1080);
    player->upgrader_d = (is_it_touched == 2) ? 1 : 0;
    player->totems[std] = upgrade_totem(player->totems[std], type, player);
    free(type);
    player->upgrader_d = 0;
    return (0);
}

int market_or_upgrade(player_t *player, sfVector2i cursor, int i)
{
    totem_info(player->totems[i], i);
    if (player->totems[i]->lvl == 0)
        player->market_d = 1;
    else
        player->upgrader_d = 1;
    player->m_sel = i;
    return (0);
}

int touch_check(player_t *player, sfVector2i cursor)
{
    int is_it_touched = 0;

    for (int i = 0; player->totems[i] != NULL; i++) {
        is_it_touched += (cursor.x > player->totems[i]->pos.x) ? 1 : 0;
        is_it_touched += (cursor.x < player->totems[i]->pos.x + 78) ? 1 : 0;
        is_it_touched += (cursor.y > player->totems[i]->pos.y) ? 1 : 0;
        is_it_touched += (cursor.y < player->totems[i]->pos.y + 78) ? 1 : 0;
        is_it_touched -= (player->market_d == 1) ? 1 : 0;
        if (is_it_touched == 4)
            market_or_upgrade(player, cursor, i);
        is_it_touched = 0;
    }
    return (0);
}

int my_click_event(player_t *player, sfVector2i cursor)
{
    int is_it_touched = 0;
    int std = player->m_sel;

    if (player->market_d == 1) {
        market_handler(player, cursor);
    } else if (player->upgrader_d == 1) {
        upgrade_handler(player, cursor);
    } else
        touch_check(player, cursor);

    return (0);
}