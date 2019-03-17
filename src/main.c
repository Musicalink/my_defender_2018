/*
** EPITECH PROJECT, 2019
** main
** File description:
** my_defender
*/

#include "defender.h"

int main(int ac, char **av)
{
    menu_t *menu = init_menu(MENU);
    sfVideoMode mode = {1920, 1080, 60};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, TITLE, sfTitlebar | sfClose, NULL);
    game_menu(menu, window);
    sfRenderWindow_destroy(window);
    return (0);
}
