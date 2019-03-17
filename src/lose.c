/*
** EPITECH PROJECT, 2019
** lose
** File description:
** my_defender
*/

#include "defender.h"

int display_lose(menu_t *lose, sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, lose->sprite, NULL);
}

int lose(sfRenderWindow *window)
{
    menu_t *lose = init_menu("./ressources/lose.png");

    while (sfRenderWindow_isOpen(window)) {
        display_lose(lose, window);
        sfRenderWindow_display(window);
    }

}
