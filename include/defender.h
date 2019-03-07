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
#include <stdlib.h>
#include "totem.h"
#include "monster.h"
#include "my.h"

typedef struct menu {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
} menu_t;

typedef struct player {
    int money;
    int waves;
    int monster_killed;
    totem_t **totems;
    monster_t **monsters;
    sfSprite *w_spr;
    sfTexture *w_txt;
} player_t;

menu_t *init_menu(char *);

sfIntRect create_IntRect(int top, int left, int width, int height);

totem_t *generate_totem(int y, int x);

player_t *generate_game(void);

player_t *my_end_event(player_t *player, sfRenderWindow *window);

int start_game(player_t *player, sfRenderWindow *window);

int game_start(sfRenderWindow *window);

totem_t *s_up(totem_t *totem);

totem_t *d_up(totem_t *totem);

totem_t *b_up(totem_t *totem);

totem_t *f_up(totem_t *totem);

#define GAME_BG "./ressources/game_bg.png"

#endif /*DEFENDER_H_*/
