/*
** EPITECH PROJECT, 2023
** MUL_my_defender_2018
** File description:
** Created by mcarpentier
*/

#include "defender.h"

player_t *generate_game(void)
{
    player_t *player = malloc(sizeof(player_t));

    player->money = 500;
    player->waves = 0;
    player->monster_killed = 0;
    player->totems = malloc(sizeof(totem_t) * 33);
    for (int i = 0; i < 33; i++)
        player->totems[i] = malloc(sizeof(totem_t));
    player->totems[32] = NULL;
    for (int i = 0; TOTEM_POS[i].x != 0 && TOTEM_POS[i].y != 0; i++)
        player->totems[i] = generate_totem(TOTEM_POS[i].y, TOTEM_POS[i].x);
    player->w_spr = sfSprite_create();
    player->w_txt = sfTexture_createFromFile(GAME_BG, NULL);
    sfSprite_setTexture(player->w_spr, player->w_txt, sfTrue);
    return (player);
}

void my_click_event(player_t *player, sfVector2i cursor_pos)
{
    for (int i = 0; player->totems[i] != NULL; i++) {
        if (cursor_pos.x > player->totems[i]->pos.x &&
            cursor_pos.x < player->totems[i]->pos.x + 78)
            if (cursor_pos.y > player->totems[i]->pos.y &&
                cursor_pos.y < player->totems[i]->pos.y + 78)
                printf("Totem %d touched\n", i);
    }
}

player_t *my_event(player_t *player, sfRenderWindow *window)
{
    sfEvent event;
    sfVector2i cursor_pos = sfMouse_getPosition(window);
    sfVector2f cursor;

    cursor.x = (float)cursor_pos.x;
    cursor.y = (float)cursor_pos.y;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        else if (sfKeyboard_isKeyPressed(sfKeyQ) == 1)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed)
            my_click_event(player, cursor_pos);
    }
    return (player);
}

int start_game(player_t *player, sfRenderWindow *window)
{
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, player->w_spr, NULL);
        sfRenderWindow_display(window);
        my_event(player, window);
    }
}

int game_start(sfRenderWindow *window)
{
    player_t *player = generate_game();
    start_game(player, window);
}

/*

typedef struct totem_stats {
    int lvl;
    int atk;
    float spd;
    float cd;
    int max_e;
    int range;
    int cost;
} totem_stats_t;

typedef struct totem {
    char *type;
    int lvl;
    totem_stats_t *stat;
    sfSprite *spr;
    sfTexture *text;
    sfIntRect rect;
    sfVector2f pos;
} totem_t;

typedef struct player {
    int money;
    int waves;
    int monster_killed;
    totem_t **totems;
    monster_t **monsters;
} player_t;

 */