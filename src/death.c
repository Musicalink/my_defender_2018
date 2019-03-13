/*
** EPITECH PROJECT, 2019
** death
** File description:
** defender
*/

#include "defender.h"

void check_explose(monster_t *elem)
{
    elem->alive = (elem->road == 9) ? 0 : 1;
}
