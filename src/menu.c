/*
** EPITECH PROJECT, 2019
** menu
** File description:
** lucas mascaut
*/

#include <stdlib.h>
#include <unistd.h>
#include "defender.h"

sfIntRect create_rect(int left, int top, int width, int height)
{
    sfIntRect rect;

    rect.left = left;
    rect.top = top;
    rect.width = width;
    rect.height = height;
    return (rect);
}

menu_t *init_menu(char *ressources)
{
    menu_t *menu = malloc(sizeof(menu_t));
    sfVector2f pos;

    pos.x = 0;
    pos.y = 0;
    menu->rect = create_rect(0,0,1920,1080);
    menu->texture = sfTexture_createFromFile(ressources, NULL);
    menu->sprite = sfSprite_create();
    sfSprite_setPosition(menu->sprite, pos);
    sfSprite_setTexture(menu->sprite, menu->texture, sfTrue);
    sfSprite_setTextureRect(menu->sprite, menu->rect);
}

int game_menu(menu_t *menu)
{
    
}