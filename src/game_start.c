/*
** EPITECH PROJECT, 2023
** MUL_my_defender_2018
** File description:
** Created by mcarpentier
*/

#include "defender.h"

void totem_info(totem_t *totem, int i)
{
    printf("Totem %d touched\n", i);
    printf("Value:\nType: %s\nLevel: %d\n", totem->type, totem->lvl);
    printf("Level stat: %d\n", totem->stat->lvl);
    printf("Attack: %d\nSpeed booster: %.2f\n", totem->stat->atk,
        totem->stat->spd);
    printf("Cooldown: %.2f\nMax Enemies: %d\n", totem->stat->cd,
        totem->stat->max_e);
    printf("rng: %d\ncst: %d\n", totem->stat->rng, totem->stat->cst);
    printf("_________\n");
}

int monsters_remaining(list *list)
{
    int count = 0;
    monster_t *elem = list->head;

    for (; elem != NULL; elem = elem->next)
        count += (elem->alive == 1) ? 1 : 0;
    return (count);
}

int start_game(player_t *player, sfRenderWindow *window)
{
    player->elapsed = sfClock_getElapsedTime(player->clock);
    while (sfRenderWindow_isOpen(window) && player->launch_menu == 0) {
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
    free_end(player);
    free(player);
    if (player->launch_menu == 1) {
        game_menu(init_menu(MENU), window);
    }
    if (player->launch_menu == 0)
        sfRenderWindow_destroy(window);
    return (0);
}
