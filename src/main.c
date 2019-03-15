/*
** EPITECH PROJECT, 2019
** main
** File description:
** my_defender
*/

#include "defender.h"

int main(int ac, char **av)
{
    menu_t *menu = init_menu("./ressources/menu.jpg");
    sfVideoMode mode = {1920, 1080, 60};
    sfRenderWindow *window;
    window = sfRenderWindow_create(mode, "Runner", sfTitlebar | sfClose, NULL);

    game_menu(menu, window);
    return (0);
}
