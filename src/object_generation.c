/*
** EPITECH PROJECT, 2023
** MUL_my_defender_2018
** File description:
** Created by mcarpentier
*/

#include "defender.h"

sfText *gen_text(char *s, int y, int x)
{
    sfText *text = sfText_create();
    sfVector2f size;
    sfVector2f pos;
    sfFont *font = sfFont_createFromFile(FONT);

    size.x = 1.5;
    size.y = 1.5;
    pos.x = x;
    pos.y = y;
    sfText_setString(text, s);
    sfText_setScale(text, size);
    sfText_setPosition(text, pos);
    sfText_setFont(text, font);
    return (text);
}

sfColor get_color(char *s, int i)
{
    if (my_strcmp(s, "fire") == 0 || my_strcmp(s, "bubble") == 0) {
        if (my_strcmp(s, "bubble") == 0)
            return ((i == 0) ? COLORS[2] : COLORS[3]);
        else
            return ((i == 0) ? COLORS[0] : COLORS[1]);
    }
    if (my_strcmp(s, "dark") == 0 || my_strcmp(s, "storm") == 0) {
        if (my_strcmp(s, "dark") == 0)
            return ((i == 0) ? COLORS[6] : COLORS[7]);
        else
            return ((i == 0) ? COLORS[4] : COLORS[5]);
    }
}

void gen_circle(totem_t *totem)
{
    float width;
    sfVector2f new_pos = (sfVector2f){totem->pos.x + 25, totem->pos.y + 40};
    sfColor color = get_color(totem->type, 0);
    sfColor color2 = get_color(totem->type, 1);

    totem->circle = sfCircleShape_create();
    sfCircleShape_setRadius(totem->circle, totem->stat->rng);
    width = sfCircleShape_getGlobalBounds(totem->circle).width / 2;
    sfCircleShape_setOrigin(totem->circle, (sfVector2f){width, width});
    sfCircleShape_setPosition(totem->circle, new_pos);
    sfCircleShape_setFillColor(totem->circle, color);
    sfCircleShape_setOutlineThickness(totem->circle, 5);
    sfCircleShape_setOutlineColor(totem->circle, color2);
}

totem_t *generate_totem(float y, float x)
{
    totem_t *totem = malloc(sizeof(totem_t));

    totem->type = my_strdup("none");
    totem->stat = malloc(sizeof(totem_stats_t));
    totem->stat->lvl = 0;
    totem->lvl = 0;
    totem->stat->atk = 0;
    totem->stat->spd = 0;
    totem->stat->cd = 0;
    totem->stat->max_e = 0;
    totem->stat->rng = 0;
    totem->stat->cst = 0;
    totem->spr = sfSprite_create();
    totem->pos.x = x + 7;
    totem->pos.y = y - 80;
    sfSprite_setPosition(totem->spr, totem->pos);
    totem->pos.y = y;
    totem->pos.x = x;
    totem->current_er = 0;
    return (totem);
}

my_sound_t *generate_sound(char *path, int vol)
{
    my_sound_t *sound = malloc(sizeof(my_sound_t));

    sound->buffer = sfSoundBuffer_createFromFile(path);
    sound->sound = sfSound_create();
    sfSound_setBuffer(sound->sound, sound->buffer);
    sfSound_setVolume(sound->sound, vol);
    return (sound);
}