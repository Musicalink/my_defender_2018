/*
** EPITECH PROJECT, 2023
** MUL_my_defender_2018
** File description:
** Created by mcarpentier
*/

#include "defender.h"

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

void free_totem_list(player_t *player)
{
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
    sfSound_stop(player->monsters->minotaur_s->sound);
    sfSound_stop(player->monsters->penguin_s->sound);
    sfSound_destroy(player->monsters->minotaur_s->sound);
    sfSound_destroy(player->monsters->penguin_s->sound);
    free(player->monsters->penguin_s);
    free(player->monsters->minotaur_s);
    free_totem_list(player);
    free(player->monsters);
    sfMusic_stop(player->music);
}