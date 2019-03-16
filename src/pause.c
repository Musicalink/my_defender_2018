/*
** EPITECH PROJECT, 2019
** pause
** File description:
** my_defender
*/

#include "defender.h"

int check_mouse_pos_pause(sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    int ret = 0;
    
    if (mouse.x < 1245 && mouse.x > 678) {
	ret = (mouse.y < 489 && mouse.y > 340) ? 1 : ret;
	ret = (mouse.y < 742 && mouse.y > 586) ? 2 : ret;
	ret = (mouse.y < 997 && mouse.y > 847) ? 3 : ret;
    }
    return (ret);
}

int display_pause(menu_t *pause, sfRenderWindow *window)
{
    sfEvent event;
    int ret = 0;
    
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        else if (event.type == sfEvtMouseButtonPressed) {
            ret = check_mouse_pos_pause(window);
        }
    }
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, pause->sprite, NULL);
    return (ret);
}

int pause_menu(sfRenderWindow *window)
{
    menu_t *pause = init_menu(PAUSE_B);
    int ret;

    while (sfRenderWindow_isOpen(window)) {
	ret = display_pause(pause, window);
	sfRenderWindow_display(window);
	if (ret == 1)
	    return (0);
	else if (ret == 3)
	    sfRenderWindow_close(window);
    }
}
