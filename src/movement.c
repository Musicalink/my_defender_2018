/*
** EPITECH PROJECT, 2023
** MUL_my_defender_2018
** File description:
** Created by mcarpentier
*/

#include "defender.h"

void move_helper(monster_t *elem, player_t *player, int speed)
{
    elem->pos.x += (elem->road == 0 && elem->pos.x < 1700) ? speed : 0;
    elem->road += (elem->road == 0 && elem->pos.x >= 1700) ? 1 : 0;
    elem->pos.y -= (elem->road == 1 && elem->pos.y > 120) ? speed : 0;
    elem->road += (elem->road == 1 && elem->pos.y <= 120) ? 1 : 0;
    elem->pos.x -= (elem->road == 2 && elem->pos.x > 130) ? speed : 0;
    elem->road += (elem->road == 2 && elem->pos.x <= 130) ? 1 : 0;
    elem->pos.y += (elem->road == 3 && elem->pos.y < 660) ? speed : 0;
    elem->road += (elem->road == 3 && elem->pos.y >= 660) ? 1 : 0;
    elem->pos.x += (elem->road == 4 && elem->pos.x < 1527) ? speed : 0;
    elem->road += (elem->road == 4 && elem->pos.x >= 1527) ? 1 : 0;
    elem->pos.y -= (elem->road == 5 && elem->pos.y > 285) ? speed : 0;
    elem->road += (elem->road == 5 && elem->pos.y <= 285) ? 1 : 0;
    elem->pos.x -= (elem->road == 6 && elem->pos.x > 282) ? speed : 0;
    elem->road += (elem->road == 6 && elem->pos.x <= 282) ? 1 : 0;
    elem->pos.y += (elem->road == 7 && elem->pos.y < 467) ? speed : 0;
    elem->road += (elem->road == 7 && elem->pos.y >= 467) ? 1 : 0;
    elem->pos.x += (elem->road == 8 && elem->pos.x < 1185) ? speed : 0;
    elem->road += (elem->road == 8 && elem->pos.x >= 1185) ? 1 : 0;
}

void make_move(monster_t *elem, player_t *player)
{
    sfTime time = sfClock_getElapsedTime(player->clock);
    int speed = elem->speed;
    sfTime elapsed;

    elapsed.microseconds = time.microseconds - player->time.microseconds;
    player->time = time;
    speed *= (int)((elapsed.microseconds / 1000000) / 0.05) + 1;
    move_helper(elem, player, speed);
}

void my_movement(monster_t *elem, list *enemies, player_t *player)
{
    int s = elem->road;

    make_move(elem, player);
    if (elem->road != s)
        my_flip(elem, s, enemies);
}

void penguin_move(monster_t *elem)
{
    if (elem->road == 8) {
        elem->speed += 2;
        if (elem->rect.left == 0 && elem->rect.top < 81 * 2)
            elem->rect.top += 81;
    }
    elem->rect.left += 81;
    if (elem->rect.left > 81 * 7)
        elem->rect.left = 0;
}

void move_monster(player_t *player, sfRenderWindow *window)
{
    monster_t *elem = player->monsters->head;

    for (; elem != NULL; elem = elem->next) {
        my_movement(elem, player->monsters, player);
        sfSprite_setPosition(elem->spr, elem->pos);
        if (my_strcmp(elem->type, "Kamipenguin") == 0) {
            penguin_move(elem);
            check_explose(elem, player);
        } else {
            elem->rect.left += 81;
            elem->rect.left = (elem->rect.left >= 81 * 7) ? 0 : elem->rect.left;
        }
        sfSprite_setTextureRect(elem->spr, elem->rect);
    }
}