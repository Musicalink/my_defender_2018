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

list *free_list(list *enemies)
{
    monster_t *mon = enemies->head;
    monster_t *tmp;

    for (; mon != NULL; mon = mon->next) {
        tmp = mon->next;
        free(mon->type);
        sfSprite_destroy(mon->spr);
        free(mon);
        mon = tmp;
    }
    enemies->size = 0;
    enemies->head = NULL;
    enemies->tail = NULL;
    return (enemies);
}

void free_end(player_t *player)
{
    sfClock_destroy(player->clock);
    sfText_destroy(player->money_t);
    sfText_destroy(player->waves_t);
    sfText_destroy(player->enemies_t);
    sfSprite_destroy(player->w_spr);
    sfTexture_destroy(player->w_txt);
    sfTexture_destroy(player->upgrader_tex);
    sfTexture_destroy(player->market_tex);
    sfSprite_destroy(player->market_spr);
    sfSprite_destroy(player->upgrader_spr);
    free_list(player->monsters);
    free(player->monsters);
    for (int i = 0; player->totems[i] != NULL; i++) {
	if (my_strcmp(player->totems[i]->type, "none") != 0) {
	    sfCircleShape_destroy(player->totems[i]->circle);
	    sfTexture_destroy(player->totems[i]->text);
	}
        free(player->totems[i]->type);
        free(player->totems[i]->stat);
        sfSprite_destroy(player->totems[i]->spr);
        free(player->totems[i]);
    }
    free(player->totems);
}

int start_game(player_t *player, sfRenderWindow *window)
{
    while (sfRenderWindow_isOpen(window)) {
        player = my_clock(player, window);
        sfText_setString(player->money_t, my_itoa(player->money));
        sfText_setString(player->enemies_t, my_itoa(player->enemies_r));
        move_monster(player, window);
        display_game(player, window);
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
    return (0);
}
