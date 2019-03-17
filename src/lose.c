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
    sfRenderWindow_drawText(window, lose->text, NULL);
}

int lose(sfRenderWindow *window, int nb)
{
    menu_t *lose = init_menu("./resources/lose.png");
    char *s = my_strcat("You've been through wave ", my_itoa(nb));

    lose->text = gen_text(s, 1028, 580);
    while (sfRenderWindow_isOpen(window)) {
        display_lose(lose, window);
        sfRenderWindow_display(window);
    }
    free(s);
}
