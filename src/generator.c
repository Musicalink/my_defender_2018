/*
** EPITECH PROJECT, 2023
** MUL_my_defender_2018
** File description:
** Created by mcarpentier
*/

#include "defender.h"

player_t *generate_game(void)
{
    player_t *player = malloc(sizeof(player_t));

    player->money = 500;
    player->waves = 1;
    player->enemies_r = 0;
    player->money_t = gen_text(my_itoa(player->money), 955, 110);
    player->waves_t = gen_text(my_itoa(player->waves), 1028, 130);
    player->enemies_t = gen_text(my_itoa(player->enemies_r), 993, 390);
    player->totems = malloc(sizeof(totem_t) * 33);
    for (int i = 0; i < 33; i++)
        player->totems[i] = malloc(sizeof(totem_t));
    player->totems[32] = NULL;
    for (int i = 0; TOTEM_POS[i].x != 0 && TOTEM_POS[i].y != 0; i++)
        player->totems[i] = generate_totem(TOTEM_POS[i].y, TOTEM_POS[i].x);
    player->w_spr = sfSprite_create();
    player->w_txt = sfTexture_createFromFile(GAME_BG, NULL);
    sfSprite_setTexture(player->w_spr, player->w_txt, sfTrue);
    player->launch_menu = 0;
    return (player);
}

int game_start(sfRenderWindow *window)
{
    player_t *player = generate_game();
    player = totem_menu_gen(player);
    player->monsters = monster_list_init();//perica.bekavac@ibm.com
    add_penguin(player->monsters, 1, 1);
    add_bull(player->monsters, 2, 1);
    player->clock = sfClock_create();
    player->market_d = 0;
    player->upgrader_d = 0;
    player->life = 5000;
    player->secs = 0;
    player->monsters->penguin_s = generate_sound(PENGUIN_S, 200);
    player->monsters->minotaur_s = generate_sound(MINOTAUR_S, 60);
    player->music = sfMusic_createFromFile(MUSIC);
    sfMusic_setLoop(player->music, 1);
    sfMusic_setVolume(player->music, 20);
    sfMusic_play(player->music);
    sfRenderWindow_setFramerateLimit(window, 60);
    start_game(player, window);
    return (0);
}
