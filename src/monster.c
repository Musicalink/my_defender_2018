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

void add_penguin(list *enemies)
{
    monster_t *elem = malloc(sizeof(monster_t));

    elem->alive = 1;
    elem->type = "Kamipenguin";
    elem->speed = 16;
    elem->health = 500;
    elem->armor = 50;
    elem->a_speed = 0;
    elem->a_damage = 100;
    elem->text = sfTexture_createFromFile(KAMIKAZE, NULL);
    elem->rev = sfTexture_createFromFile(KAMIKAZE_R, NULL);
    elem->pos.x = 30;
    elem->pos.y = 860;
    elem->road = 0;
    elem->rect = create_rect(0, 0, 81, 81);
    elem->spr = sfSprite_create();
    sfSprite_setPosition(elem->spr, elem->pos);
    sfSprite_setTexture(elem->spr, elem->text, sfTrue);
    sfSprite_setTextureRect(elem->spr, elem->rect);
    add_element_to_list(enemies, elem);
}

void add_bull(list *enemies)
{
    monster_t *elem = malloc(sizeof(monster_t));

    elem->type = "minotaure";
    elem->speed = 4;
    elem->health = 1000;
    elem->armor = 100;
    elem->a_speed = 0;
    elem->a_damage = 200;
    elem->text = sfTexture_createFromFile(MINOTAURE, NULL);
    elem->rev = sfTexture_createFromFile(MINOTAURE_R, NULL);
    elem->pos.x = 30;
    elem->pos.y = 860;
    elem->road = 0;
    elem->rect = create_rect(0, 0, 81, 81);
    elem->spr = sfSprite_create();
    sfSprite_setPosition(elem->spr, elem->pos);
    sfSprite_setTexture(elem->spr, elem->text, sfTrue);
    sfSprite_setTextureRect(elem->spr, elem->rect);
    add_element_to_list(enemies, elem);
}

list *monster_list_init(void)
{
    list *new_list = NULL;

    new_list = malloc(sizeof(list));
    if (new_list != NULL) {
        new_list->size = 0;
        new_list->head = NULL;
        new_list->tail = NULL;
    }
    return (new_list);
}
