/*
** EPITECH PROJECT, 2023
** MUL_my_defender_2018
** File description:
** Created by mcarpentier
*/

#include "defender.h"

double check_rng(monster_t *monster, totem_t *totem)
{
    sfFloatRect monsters_c = sfSprite_getGlobalBounds(monster->spr);
    sfFloatRect totem_c = sfSprite_getGlobalBounds(totem->spr);
    float monster_mx = monsters_c.left + monsters_c.width / 2;
    float monster_my = monsters_c.top + monsters_c.height / 2;
    float totem_mx = totem_c.left + totem_c.width / 2;
    float totem_my = totem_c.top + totem_c.height / 2;
    double res = pow((monster_mx - totem_mx), 2);

    return (sqrt(res + pow(fabs(monster_my - totem_my), 2)));
}

void make_shot(monster_t *elem, totem_t *totem, player_t *player)
{
    if (player->secs - totem->current_cd > totem->stat->cd) {
        elem->health -= totem->stat->atk;
        elem->speed -= (int)totem->stat->spd;
        elem->speed = (elem->speed < 1) ? 1 : elem->speed;
        if (elem->health <= 0 && elem->alive == 1 && elem->type[0] == 'K')
            sfSound_play(player->monsters->penguin_s->sound);
        else if (elem->health <= 0 && elem->alive == 1 && elem->type[0] != 'K')
            sfSound_play(player->monsters->minotaur_s->sound);
        elem->alive = (elem->health <= 0) ? 0 : 1;
        player->money += (elem->alive == 0) ? elem->value : 0;
        elem->value = (elem->alive == 0) ? 0 : elem->value;
        elem->speed = (elem->alive == 0) ? 0 : elem->speed;
        totem->current_er++;
        if (totem->current_er >= totem->stat->max_e) {
            totem->current_cd = player->secs;
            totem->current_er = 0;
        }
    }
}

void search_monsters(list *monsters, totem_t *totem, player_t *player)
{
    monster_t *elem = monsters->head;
    int left = 0;

    for (; elem != NULL; elem = elem->next)
        if (check_rng(elem, totem) < totem->stat->rng && elem->alive == 1) {
            totem->rect.left += 56;
            left = (totem->rect.left > 56 * 6) ? 0 : totem->rect.left;
            totem->rect.left = (left != 0) ? left : totem->rect.left;
            left = 0;
            sfSprite_setTextureRect(totem->spr, totem->rect);
            make_shot(elem, totem, player);
        }
    if (totem->current_er > 0)
        totem->current_cd = player->secs;
    totem->current_er = 0;
}

void monsters_damage(player_t *player)
{
    for (int i = 0; player->totems[i] != NULL; i++)
        if (my_strcmp(player->totems[i]->type, "none") != 0)
            search_monsters(player->monsters, player->totems[i], player);
}