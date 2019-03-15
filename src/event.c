/*
** EPITECH PROJECT, 2023
** MUL_my_defender_2018
** File description:
** Created by mcarpentier
*/

#include "defender.h"

player_t *my_clock(player_t *player, sfRenderWindow *window)
{
    float seconds = 0;
    float limit = 0.05;

    while (seconds < limit) {
        player->time = sfClock_getElapsedTime(player->clock);
        player = my_event(player, window);
        seconds = (float)(player->time.microseconds / 1000000.0);
    }
    player->secs += seconds;
    sfClock_restart(player->clock);
    monsters_damage(player);
    return (player);
}

player_t *my_event(player_t *player, sfRenderWindow *window)
{
    sfEvent event;
    sfVector2i cursor_pos = sfMouse_getPosition(window);
    sfVector2f cursor;

    cursor.x = (float)cursor_pos.x;
    cursor.y = (float)cursor_pos.y;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        else if (sfKeyboard_isKeyPressed(sfKeyQ) == 1)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed)
            my_click_event(player, cursor_pos);
    }
    return (player);
}