/*
** EPITECH PROJECT, 2023
** MUL_my_defender_2018
** File description:
** Created by mcarpentier
*/

#include "defender.h"

void my_movement(monster_t *elem)
{
    elem->pos.x += (elem->road == 0 && elem->pos.x < 1700) ? elem->speed : 0;
    elem->road += (elem->road == 0 && elem->pos.x >= 1700) ? 1 : 0;
    elem->pos.y -= (elem->road == 1 && elem->pos.y > 120) ? elem->speed : 0;
    elem->road += (elem->road == 1 && elem->pos.y <= 120) ? 1 : 0;
    elem->pos.x -= (elem->road == 2 && elem->pos.x > 130) ? elem->speed : 0;
    elem->road += (elem->road == 2 && elem->pos.x <= 130) ? 1 : 0;
    elem->pos.y += (elem->road == 3 && elem->pos.y < 660) ? elem->speed : 0;
    elem->road += (elem->road == 3 && elem->pos.y >= 660) ? 1 : 0;
    elem->pos.x += (elem->road == 4 && elem->pos.x < 1527) ? elem->speed : 0;
    elem->road += (elem->road == 4 && elem->pos.x >= 1527) ? 1 : 0;
    elem->pos.y -= (elem->road == 5 && elem->pos.y > 285) ? elem->speed : 0;
    elem->road += (elem->road == 5 && elem->pos.y <= 285) ? 1 : 0;
    elem->pos.x -= (elem->road == 6 && elem->pos.x > 282) ? elem->speed : 0;
    elem->road += (elem->road == 6 && elem->pos.x <= 282) ? 1 : 0;
    elem->pos.y += (elem->road == 7 && elem->pos.y < 467) ? elem->speed : 0;
    elem->road += (elem->road == 7 && elem->pos.y >= 467) ? 1 : 0;
    elem->pos.x += (elem->road == 8 && elem->pos.x < 1185) ? elem->speed : 0;
    elem->road += (elem->road == 8 && elem->pos.x >= 1185) ? 1 : 0;
}

void penguin_move(monster_t *elem)
{
    if (elem->road == 8) {
	elem->speed += 2;
	if (elem->rect.left == 0 && elem->rect.top < 81 * 2)
	    elem->rect.top += 81;
    }
    elem->rect.left += 81;
    if (elem->rect.left > 81 * 7)
	elem->rect.left = 0;
}

void move_monster(player_t *player, sfRenderWindow *window)
{
    monster_t *elem = player->monsters->head;

    for (; elem != NULL; elem = elem->next) {
        my_movement(elem);
        sfSprite_setPosition(elem->spr, elem->pos);
	if (my_strcmp(elem->type, "Kamipenguin") == 0) {
	    penguin_move(elem);
	    check_explose(elem);
	} else {//-------------------------------|
	    elem->rect.left += 81;//-----------|
	    if (elem->rect.left > 81 * 7)//----|--> A normifier
		elem->rect.left = 0;//---------|
	}//------------------------------------|
        sfSprite_setTextureRect(elem->spr, elem->rect);
    }
}

player_t *my_clock(player_t *player, sfRenderWindow *window)
{
    float seconds = 0;
    float limit = 0.05;

    while (seconds < limit) {
        player->time = sfClock_getElapsedTime(player->clock);
        player = my_event(player, window);
        seconds = (float)(player->time.microseconds / 1000000.0);
    }
    sfClock_restart(player->clock);
    return (player);
}

player_t *generate_game(void)
{
    player_t *player = malloc(sizeof(player_t));

    player->money = 500;
    player->waves = 0;
    player->enemies_r = 0;
    player->money_t = gen_text(my_itoa(player->money), 955, 110);
    player->waves_t = gen_text(my_itoa(player->waves), 993, 390);
    player->enemies_t = gen_text(my_itoa(player->enemies_r), 1028, 130);
    player->totems = malloc(sizeof(totem_t) * 33);
    for (int i = 0; i < 33; i++)
        player->totems[i] = malloc(sizeof(totem_t));
    player->totems[32] = NULL;
    for (int i = 0; TOTEM_POS[i].x != 0 && TOTEM_POS[i].y != 0; i++)
        player->totems[i] = generate_totem(TOTEM_POS[i].y, TOTEM_POS[i].x);
    player->w_spr = sfSprite_create();
    player->w_txt = sfTexture_createFromFile(GAME_BG, NULL);
    sfSprite_setTexture(player->w_spr, player->w_txt, sfTrue);
    return (player);
}

int is_it_in(int to_try, int exone, int extwo)
{
    if (to_try > exone && to_try < extwo)
        return (1);
    return (0);
}

totem_t *chose_totem(totem_t *totem, sfVector2i cursor_pos, player_t *player)
{
    int dark = 0;
    int fire = 0;
    int storm = 0;
    int bubble = 0;

    dark += is_it_in(cursor_pos.x, 1632, 1747);
    dark += is_it_in(cursor_pos.y, 797, 918);
    bubble += is_it_in(cursor_pos.x, 1792, 1907);
    bubble += is_it_in(cursor_pos.y, 797, 918);
    fire += is_it_in(cursor_pos.x, 1792, 1907);
    fire += is_it_in(cursor_pos.y, 943, 1063);
    storm += is_it_in(cursor_pos.x, 1632, 1747);
    storm += is_it_in(cursor_pos.y, 943, 1063);
    totem = (storm == 2) ? build_totem(totem, "storm", player) : totem;
    totem = (bubble == 2) ? build_totem(totem, "bubble", player) : totem;
    totem = (dark == 2) ? build_totem(totem, "dark", player) : totem;
    totem = (fire == 2) ? build_totem(totem, "fire", player) : totem;
    return (totem);
}

void totem_info(totem_t *totem, int i)
{
    printf("Totem %d touched\n", i);
    printf("Value:\nType: %s\nLevel: %d\n", totem->type, totem->lvl);
    printf("Level stat: %d\n", totem->stat->lvl);
    printf("Attack: %d\nSpeed booster: %.2f\n", totem->stat->atk,
        totem->stat->spd);
    printf("Cooldown: %.2f\nMax Enemies: %d\n", totem->stat->cd,
        totem->stat->max_e);
    printf("Range: %d\nCost: %d\n", totem->stat->range, totem->stat->cost);
    printf("_________\n");
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

void display_monsters(player_t *player, sfRenderWindow *window)
{
    monster_t *elem = player->monsters->head;

    for (; elem != NULL; elem = elem->next)
        if (elem->health > 0)
            sfRenderWindow_drawSprite(window, elem->spr, NULL);
}

void display_game(player_t *player, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, player->w_spr, NULL);
    if (player->market_d == 1)
        sfRenderWindow_drawSprite(window, player->market_spr, NULL);
    else if (player->upgrader_d == 1)
        sfRenderWindow_drawSprite(window, player->upgrader_spr, NULL);
    display_monsters(player, window);
    sfRenderWindow_drawText(window, player->money_t, NULL);
    sfRenderWindow_drawText(window, player->waves_t, NULL);
    sfRenderWindow_drawText(window, player->enemies_t, NULL);
    for (int i = 0; player->totems[i] != NULL; i++)
        if (my_strcmp(player->totems[i]->type, "none") != 0)
            sfRenderWindow_drawSprite(window, player->totems[i]->spr, NULL);
    sfRenderWindow_display(window);
}

int start_game(player_t *player, sfRenderWindow *window)
{
    while (sfRenderWindow_isOpen(window)) {
        player = my_clock(player, window);
        sfText_setString(player->money_t, my_itoa(player->money));
        sfText_setString(player->waves_t, my_itoa(player->waves));
        sfText_setString(player->enemies_t, my_itoa(player->enemies_r));
        display_game(player, window);
        move_monster(player, window);
    }
}

int game_start(sfRenderWindow *window)
{
    player_t *player = generate_game();
    player->market_spr = totem_menu_gen(CONSTRUCT_TXT);
    player->upgrader_spr = totem_menu_gen(UPGRADER_TXT);
    player->monsters = monster_list_init();
    add_penguin(player->monsters);
    add_bull(player->monsters);
    player->clock = sfClock_create();
    player->market_d = 0;
    start_game(player, window);
    return (0);
}
