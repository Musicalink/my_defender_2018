/*
** EPITECH PROJECT, 2019
** monster
** File description:
** my_defender
*/

#include "defender"

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

    elem->type = "Kamipenguin";
    elem->speed = 150;
    elem->health = 500;
    elem->armor = 50;
    elem->a_speed = 0;
    elem->a_damage = 100;
    elem->text = sfTexture_createFromFile("ressources/boumboum.png", NULL);
    elem->pos.x = -30;
    elem->pos.y = 949;
    elem->rect = create_rect(0, 0, 0, 0);//faudra changer les valeurs
    elem->spr = sfSprite_create();
    sfSprite_setPosition(elem->spr, elem->pos);
    sfSprite_setTexture(elem->spr, elem->text, sfTrue);
    sfSprite_settextureRect(elem->spr, elem->rect);
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
