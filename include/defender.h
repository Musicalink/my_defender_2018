/*
** EPITECH PROJECT, 2019
** defender
** File description:
** include
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_

#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "totem.h"
#include "monster.h"
#include "my.h"

typedef struct menu {
    sfRenderWindow *window;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
} menu_t;

menu_t *init_menu(char *);

#endif /*DEFENDER_H_*/
