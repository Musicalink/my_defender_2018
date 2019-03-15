/*
** EPITECH PROJECT, 2023
** MUL_my_defender_2018
** File description:
** Created by mcarpentier
*/

#include "defender.h"

void my_flip(monster_t *elem, int diff)
{
    if (elem->road != diff && elem->road % 4 == 2)
        sfSprite_setTexture(elem->spr, elem->rev, sfTrue);
    else if (elem->road != diff && elem->road % 4 == 0)
        sfSprite_setTexture(elem->spr, elem->text, sfTrue);
}

void my_movement(monster_t *elem)
{
    int s = elem->road;

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
    if (elem->road != s)
        my_flip(elem, s);
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
            check_explose(elem, player);
        } else {
            elem->rect.left += 81;
            elem->rect.left = (elem->rect.left >= 81 * 7) ? 0 : elem->rect.left;
        }
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
    player->secs += seconds;
    sfClock_restart(player->clock);
    monsters_damage(player);
    return (player);
}

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

double check_range(monster_t *monster, totem_t *totem)
{
    sfFloatRect monsters_c = sfSprite_getGlobalBounds(monster->spr);
    float monster_mx = monsters_c.left + monsters_c.width / 2;
    float monster_my = monsters_c.top + monsters_c.height / 2;
    sfFloatRect totem_c = sfSprite_getGlobalBounds(totem->spr);
    float totem_mx = totem_c.left + totem_c.width / 2;
    float totem_my = totem_c.top + totem_c.height / 2;

    return ((sqrt(pow(fabs(monster_mx - totem_mx), 2) +
        pow(fabs(monster_my - totem_my), 2))));
}

void display_monsters(player_t *player, sfRenderWindow *window)
{
    monster_t *elem = player->monsters->head;

    for (; elem != NULL; elem = elem->next)
        if (elem->alive == 1)
            sfRenderWindow_drawSprite(window, elem->spr, NULL);
}

void display_game(player_t *player, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, player->w_spr, NULL);
    sfRenderWindow_drawText(window, player->money_t, NULL);
    sfRenderWindow_drawText(window, player->waves_t, NULL);
    sfRenderWindow_drawText(window, player->enemies_t, NULL);
    display_monsters(player, window);
    for (int i = 0; player->totems[i] != NULL; i++)
        if (my_strcmp(player->totems[i]->type, "none") != 0) {
            sfRenderWindow_drawSprite(window, player->totems[i]->spr, NULL);
            sfRenderWindow_drawCircleShape(window, player->totems[i]->circle,
                NULL);
        }
    if (player->market_d == 1)
        sfRenderWindow_drawSprite(window, player->market_spr, NULL);
    else if (player->upgrader_d == 1)
        sfRenderWindow_drawSprite(window, player->upgrader_spr, NULL);
    sfRenderWindow_display(window);
}

void search_monsters(list *monsters, totem_t *totem, player_t *player)
{
    monster_t *elem = monsters->head;

    for (; elem != NULL; elem = elem->next)
        if (check_range(elem, totem) < totem->stat->range && elem->alive == 1) {
            totem->rect.left += 56;
            if (totem->rect.left > 56 * 6)
                totem->rect.left = 0;
            sfSprite_setTextureRect(totem->spr, totem->rect);
            if (player->secs - totem->current_cd > totem->stat->cd) {
                elem->health -= totem->stat->atk;
                elem->speed -= (int)totem->stat->spd;
                elem->speed = (elem->speed < 1) ? 1 : elem->speed;
                elem->alive = (elem->health <= 0) ? 0 : 1;
                player->money += (elem->alive == 0) ? elem->value : 0;
                elem->value = (elem->alive == 0) ? 0 : elem->value;
                printf("%s is now %d HP (%s)\n", elem->type, elem->health,
                    totem->type);
                elem->speed = (elem->alive == 0) ? 0 : elem->speed;
                totem->current_er++;
                printf("Tower %s -> (%d/%d)\n", totem->type, totem->current_er,
                    totem->stat->max_e);
                if (totem->current_er >= totem->stat->max_e) {
                    totem->current_cd = player->secs;
                    totem->current_er = 0;
                    break;
                }
            }
        }
    totem->current_cd =
        (totem->current_er > 0) ? player->secs : totem->current_cd;
    totem->current_er = 0;
}

void monsters_damage(player_t *player)
{
    for (int i = 0; player->totems[i] != NULL; i++) {
        if (my_strcmp(player->totems[i]->type, "none") != 0) {
            search_monsters(player->monsters, player->totems[i], player);
        }
    }
}

void generate_wave(player_t *player, sfRenderWindow *window)
{
    srand((unsigned int)player->secs);

    for (int i = 0; i < player->waves * 2; i++) {
        if (rand() % 2 == 1)
            add_penguin(player->monsters, i, player->waves);
        else
            add_bull(player->monsters, i, player->waves);
    }
}

int start_game(player_t *player, sfRenderWindow *window)
{
    while (sfRenderWindow_isOpen(window)) {
        player = my_clock(player, window);
        sfText_setString(player->money_t, my_itoa(player->money));
        sfText_setString(player->waves_t, my_itoa(player->waves));
        sfText_setString(player->enemies_t, my_itoa(player->enemies_r));
        move_monster(player, window);
        display_game(player, window);
        player->enemies_r = monsters_remaining(player->monsters);
        if (player->enemies_r == 0) {
            player->waves++;
            generate_wave(player, window);
        }
    }
    return (0);
}

int monsters_remaining(list *list)
{
    int count = 0;
    monster_t *elem = list->head;

    for (; elem != NULL; elem = elem->next)
        count += (elem->alive == 1) ? 1 : 0;
    return (count);
}

int game_start(sfRenderWindow *window)
{
    player_t *player = generate_game();
    player->market_spr = totem_menu_gen(CONSTRUCT_TXT);
    player->upgrader_spr = totem_menu_gen(UPGRADER_TXT);
    player->monsters = monster_list_init();
    add_penguin(player->monsters, 1, 1);
    add_bull(player->monsters, 2, 1);
    player->clock = sfClock_create();
    player->market_d = 0;
    player->life = 5000;
    player->secs = 0;
    start_game(player, window);
    return (0);
}
