/*
** EPITECH PROJECT, 2023
** MUL_my_defender_2018
** File description:
** Created by mcarpentier
*/

#include "defender.h"

void display_monsters(player_t *player, sfRenderWindow *window)
{
    monster_t *elem = player->monsters->head;

    for (; elem != NULL; elem = elem->next)
        if (elem->alive == 1)
            sfRenderWindow_drawSprite(window, elem->spr, NULL);
}

void draw_totem(sfRenderWindow *window, player_t *player, totem_t *totem)
{
    sfCircleShape *shape;

    sfRenderWindow_drawSprite(window, totem->spr, NULL);
    if ((player->market_d == 1 || player->upgrader_d == 1)) {
        if (my_strcmp(player->totems[player->m_sel]->type, "none") != 0) {
            shape = player->totems[player->m_sel]->circle;
            sfRenderWindow_drawCircleShape(window, shape, NULL);
        }
    }
}

void draw_upgrade(player_t *player, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, player->upgrader_spr, NULL);
    if (player->totems[player->m_sel]->stat->lvl >= 10)
        sfText_setString(player->totems[player->m_sel]->cost, "");
    sfRenderWindow_drawText(window, player->totems[player->m_sel]->level, NULL);
    sfRenderWindow_drawText(window, player->totems[player->m_sel]->cost, NULL);
}

void display_game(player_t *player, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, player->w_spr, NULL);
    sfRenderWindow_drawText(window, player->money_t, NULL);
    sfRenderWindow_drawText(window, player->waves_t, NULL);
    sfRenderWindow_drawText(window, player->enemies_t, NULL);
    display_monsters(player, window);
    for (int i = 0; player->totems[i] != NULL; i++)
        if (my_strcmp(player->totems[i]->type, "none") != 0) {
            draw_totem(window, player, player->totems[i]);
        }
    if (player->market_d == 1)
        sfRenderWindow_drawSprite(window, player->market_spr, NULL);
    else if (player->upgrader_d == 1)
        draw_upgrade(player, window);
    sfRenderWindow_display(window);
}