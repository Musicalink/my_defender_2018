/*
** EPITECH PROJECT, 2019
** totem_menu
** File description:
** 
*/

#include "defender.h"

sfSprite *totem_menu_gen(void)
{
    sfSprite *sprite;
    sfVector2f pos;
    sfTexture *texture = sfTexture_createFromFile("./ressources/construct_menu.png", NULL);

    pos.x = 1620;
    pos.y = 780;
    sprite = sfSprite_create();
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

