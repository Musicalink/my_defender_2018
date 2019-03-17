/*
** EPITECH PROJECT, 2019
** totem_menu
** File description:
**
*/

#include "defender.h"

player_t *totem_menu_gen(player_t *player)
{
    sfVector2f pos;

    player->market_tex = sfTexture_createFromFile(CONSTRUCT_TXT, NULL);
    player->upgrader_tex = sfTexture_createFromFile(UPGRADER_TXT, NULL);
    pos.x = 1620;
    pos.y = 780;
    player->market_spr = sfSprite_create();
    player->upgrader_spr = sfSprite_create();
    sfSprite_setPosition(player->market_spr, pos);
    sfSprite_setPosition(player->upgrader_spr, pos);
    sfSprite_setTexture(player->market_spr, player->market_tex, sfTrue);
    sfSprite_setTexture(player->upgrader_spr, player->upgrader_tex, sfTrue);
    return (player);
}

