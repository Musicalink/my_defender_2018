/*
** EPITECH PROJECT, 2023
** MUL_my_defender_2018
** File description:
** Created by mcarpentier
*/

#include "defender.h"

void my_flip(monster_t *elem, int diff, list *enemies)
{
    if (elem->road != diff && elem->road % 4 == 2) {
        if (my_strcmp(elem->type, "minotaur") == 0)
            sfSprite_setTexture(elem->spr, enemies->minotaur_r, sfTrue);
        else
            sfSprite_setTexture(elem->spr, enemies->penguin_r, sfTrue);
    } else if (elem->road != diff && elem->road % 4 == 0) {
        if (my_strcmp(elem->type, "minotaur") == 0)
            sfSprite_setTexture(elem->spr, enemies->minotaur, sfTrue);
        else
            sfSprite_setTexture(elem->spr, enemies->penguin, sfTrue);
    }
}

int monsters_remaining(list *list)
{
    int count = 0;
    monster_t *elem = list->head;

    for (; elem != NULL; elem = elem->next)
        count += (elem->alive == 1) ? 1 : 0;
    return (count);
}

void after_game(player_t *player, sfRenderWindow *window)
{
    free_end(player);
    free(player);
    if (player->launch_menu == 1)
        game_menu(init_menu(MENU), window);
    else if (player->life <= 0)
        lose(window, player->waves);
}

int window_need_open(player_t *player, sfRenderWindow *window)
{
    if (player->life <= 0)
        return (0);
    else if (sfRenderWindow_isOpen(window) && player->launch_menu == 0)
        return (1);
    return (0);
}

int start_game(player_t *player, sfRenderWindow *window)
{
    player->elapsed = sfClock_getElapsedTime(player->clock);
    while (window_need_open(player, window) == 1) {
        sfText_setString(player->money_t, my_itoa(player->money));
        sfText_setString(player->enemies_t, my_itoa(player->enemies_r));
        move_monster(player, window);
        display_game(player, window);
        player = my_clock(player, window);
        player->enemies_r = monsters_remaining(player->monsters);
        if (player->enemies_r == 0) {
            player->monsters = free_list(player->monsters);
            player->waves++;
            sfText_setString(player->waves_t, my_itoa(player->waves));
            generate_wave(player);
        }
    }
    after_game(player, window);
    return (0);
}
