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
#include <math.h>
#include "totem.h"
#include "monster.h"
#include "my.h"

typedef struct menu {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfText *text;
    int launch_game;
} menu_t;

typedef struct life_bar {
    sfSprite *green_s;
    sfTexture *green_t;
    sfIntRect green_r;
    sfSprite *red_s;
    sfTexture *red_t;
    sfIntRect red_r;
} lifebar_t;

typedef struct player {
    int launch_menu;
    sfTime time;
    sfClock *clock;
    int money;
    int waves;
    int enemies_r;
    sfText *money_t;
    sfText *waves_t;
    sfText *enemies_t;
    totem_t **totems;
    list *monsters;
    int life;
    sfSprite *w_spr;
    sfTexture *w_txt;
    int market_d;
    sfSprite *market_spr;
    sfSprite *upgrader_spr;
    sfTexture *market_tex;
    sfTexture *upgrader_tex;
    int upgrader_d;
    float secs;
    int m_sel;
    sfMusic *music;
    sfTime b_elapsed;
    sfTime elapsed;
    lifebar_t *lifebar;
} player_t;

int pause_menu(sfRenderWindow *, player_t *);

menu_t *init_menu(char *);

sfIntRect create_rect(int left, int top, int width, int height);

void display_monsters(player_t *player, sfRenderWindow *window);

totem_t *generate_totem(float y, float x);

player_t *generate_game(void);

int start_game(player_t *player, sfRenderWindow *window);

int game_start(sfRenderWindow *window);

totem_t *s_up(totem_t *totem, player_t *player);

totem_t *d_up(totem_t *totem, player_t *player);

totem_t *b_up(totem_t *totem, player_t *player);

totem_t *f_up(totem_t *totem, player_t *player);

player_t *totem_menu_gen(player_t *player);

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

void add_element_to_list(list *list, monster_t *elem);

void add_penguin(list *enemies, int position, int wave);

player_t *my_event(player_t *player, sfRenderWindow *window);

player_t *my_clock(player_t *game, sfRenderWindow *window);

void display_game(player_t *player, sfRenderWindow *window);

void add_bull(list *enemies, int position, int wave);

list *monster_list_init();

void my_flip(monster_t *elem, int diff, list *enemies);

void check_explose(monster_t *elem, player_t *player);

void gen_circle(totem_t *totem);

void monsters_damage(player_t *player);

int monsters_remaining(list *list);

void make_shot(monster_t *elem, totem_t *totem, player_t *player);

void make_move(monster_t *elem, player_t *player);

void move_monster(player_t *player, sfRenderWindow *window);

player_t *generate_game(void);

int game_start(sfRenderWindow *window);

void display_monsters(player_t *player, sfRenderWindow *window);

void draw_totem(sfRenderWindow *window, player_t *player, totem_t *totem);

void display_game(player_t *player, sfRenderWindow *window);

int take_percentage(player_t *player);

int lose(sfRenderWindow *window, int nb);

void generate_wave(player_t *player);

void my_movement(monster_t *elem, list *enemies, player_t *player);

void free_totem_list(player_t *player);

void free_end(player_t *player);

list *free_list(list *enemies);

totem_t *create_totem(totem_t *totem, char *type);

my_sound_t *generate_sound(char *path, int vol);

sfIntRect create_rect(int left, int top, int width, int height);

menu_t *init_menu(char *resources);

void check_mouse_pos(sfRenderWindow *window, menu_t *menu);

int display_menu(menu_t *menu, sfRenderWindow *window);

int game_menu(menu_t *menu, sfRenderWindow *window);

void after_game(player_t *player, sfRenderWindow *window);

void move_helper(monster_t *elem, player_t *player, int speed);

totem_t *create_totem(totem_t *totem, char *type);

#define MENU "./resources/menu.jpg"
#define GAME_BG "./resources/game_bg.png"
#define DARK_T "./resources/dark.png"
#define FIRE_T "./resources/fire.png"
#define STORM_T "./resources/storm.png"
#define BUBBLE_T "./resources/bubble.png"
#define CONSTRUCT_TXT "./resources/construct_menu.png"
#define UPGRADER_TXT "./resources/upgrade_menu.png"
#define FONT "resources/font.ttf"
#define KAMIKAZE "./resources/boumboum.png"
#define MINOTAUR "./resources/minotaure.png"
#define KAMIKAZE_R "./resources/boumboum_r.png"
#define MINOTAUR_R "./resources/minotaure_r.png"
#define PENGUIN_S "./resources/penguin.ogg"
#define MINOTAUR_S "./resources/meuh.ogg"
#define MUSIC "./resources/music.ogg"
#define PAUSE_B "./resources/pause.jpg"
#define TITLE "Gold Rush"
#define GREENBAR "./resources/green_bar.png"
#define REDBAR "./resources/red_bar.png"

static const sfColor COLORS[] = {{.r=255, .g=0, .b=0, .a=36},
    {.r=255, .g=0, .b=0, .a=80}, {.r=0, .g=0, .b=255, .a=36},
    {.r=0, .g=0, .b=255, .a=80}, {.r=255, .g=255, .b=0, .a=36},
    {.r=255, .g=255, .b=0, .a=80}, {.r=0, .g=0, .b=0, .a=36},
    {.r=0, .g=0, .b=0, .a=80}};

#endif /*DEFENDER_H_*/
