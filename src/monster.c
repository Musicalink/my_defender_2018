/*
** EPITECH PROJECT, 2019
** monster
** File description:
** my_defender
*/

#include "defender.h"

void add_element_to_list(list *list, monster_t *elem)
{
    if (elem != NULL) {
        elem->next = NULL;
        if (list->tail == NULL) {
            elem->prev = NULL;
            list->head = elem;
            list->tail = elem;
        } else {
            elem->prev = list->tail;
            list->tail->next = elem;
            list->tail = elem;
        }
        list->size += 1;
    }
}

void add_penguin(list *enemies, int position, int wave)
{
    monster_t *elem = malloc(sizeof(monster_t));

    elem->alive = 1;
    elem->type = my_strdup("Kamipenguin");
    elem->speed = 16;
    elem->health = 500 + 500 * ((wave - 1) / 2);
    elem->armor = 50;
    elem->a_speed = 0;
    elem->a_damage = 100;
    elem->pos.x = -40 * position;
    elem->pos.y = 860;
    elem->road = 0;
    elem->value = 75;
    elem->rect = create_rect(0, 0, 81, 81);
    elem->spr = sfSprite_create();
    sfSprite_setPosition(elem->spr, elem->pos);
    sfSprite_setTexture(elem->spr, enemies->penguin, sfTrue);
    sfSprite_setTextureRect(elem->spr, elem->rect);
    add_element_to_list(enemies, elem);
}

void add_bull(list *enemies, int position, int wave)
{
    monster_t *elem = malloc(sizeof(monster_t));

    elem->alive = 1;
    elem->type = my_strdup("minotaure");
    elem->speed = 4;
    elem->health = 1000 + 1000 * ((wave - 1) / 2);
    elem->armor = 100;
    elem->a_speed = 0;
    elem->a_damage = 200;
    elem->value = 125;
    elem->pos.x = -40 * position;
    elem->pos.y = 860;
    elem->road = 0;
    elem->rect = create_rect(0, 0, 81, 81);
    elem->spr = sfSprite_create();
    sfSprite_setPosition(elem->spr, elem->pos);
    sfSprite_setTexture(elem->spr, enemies->minotaur, sfTrue);
    sfSprite_setTextureRect(elem->spr, elem->rect);
    add_element_to_list(enemies, elem);
}

list *monster_list_init(int first_time)
{
    list *new_list = NULL;

    new_list = malloc(sizeof(list));
    if (new_list != NULL) {
        new_list->size = 0;
        new_list->head = NULL;
        new_list->tail = NULL;
        if (first_time == 1) {
            new_list->minotaur = sfTexture_createFromFile(MINOTAUR, NULL);
            new_list->minotaur_r = sfTexture_createFromFile(MINOTAUR_R, NULL);
            new_list->penguin = sfTexture_createFromFile(KAMIKAZE, NULL);
            new_list->penguin_r = sfTexture_createFromFile(KAMIKAZE_R, NULL);
        }
    }
    return (new_list);
}

void generate_wave(player_t *player)
{
    srand((unsigned int)player->secs);

    for (int i = 0; i < player->waves * 2; i++) {
        if (rand() % 2 == 1)
            add_penguin(player->monsters, i, player->waves);
        else
            add_bull(player->monsters, i, player->waves);
    }
}