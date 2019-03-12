/*
** EPITECH PROJECT, 2019
** defender
** File description:
** include
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_

#include <SFML/System.h>
#include <SFML/Window.h>
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
    int enemies_r;
    sfText *money_t;
    sfText *waves_t;
    sfText *enemies_t;
    totem_t **totems;
    monster_t **monsters;
    sfSprite *w_spr;
    sfTexture *w_txt;
    int market_d;
    sfSprite *market_spr;
    sfSprite *upgrader_spr;
    int upgrader_d;
    int m_sel;
} player_t;

menu_t *init_menu(char *);

sfIntRect create_IntRect(int top, int left, int width, int height);

totem_t *generate_totem(float y, float x);

player_t *generate_game(void);

player_t *my_end_event(player_t *player, sfRenderWindow *window);

int start_game(player_t *player, sfRenderWindow *window);

int game_start(sfRenderWindow *window);

totem_t *s_up(totem_t *totem, player_t *player);

totem_t *d_up(totem_t *totem, player_t *player);

totem_t *b_up(totem_t *totem, player_t *player);

totem_t *f_up(totem_t *totem, player_t *player);

sfSprite *totem_menu_gen(char *path);

totem_t *build_totem(totem_t *totem, char *type, player_t *player);

totem_t *upgrade_totem(totem_t *tot, char *type, player_t *p);

int my_click_event(player_t *player, sfVector2i cursor);

void market_handler(player_t *player, sfVector2i cursor);

int is_it_in(int to_try, int exone, int extwo);

int touch_check(player_t *player, sfVector2i cursor);

totem_t *chose_totem(totem_t *totem, sfVector2i cursor_pos, player_t *player);

int upgrade_handler(player_t *player, sfVector2i cursor);

sfText *gen_text(char *s, int y, int x);

int is_enough_money(player_t *player, char *type);

char *find_totem_texture(char *type, char *s);

void totem_info(totem_t *totem, int i);

#define GAME_BG "./ressources/game_bg.png"
#define DARK_T "./ressources/dark.png"
#define FIRE_T "./ressources/fire.png"
#define STORM_T "./ressources/storm.png"
#define BUBBLE_T "./ressources/bubble.png"
#define CONSTRUCT_TXT "./ressources/construct_menu.png"
#define UPGRADER_TXT "./ressources/upgrade_menu.png"
#define FONT "ressources/font.ttf"

#endif /*DEFENDER_H_*/
