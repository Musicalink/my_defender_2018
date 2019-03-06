/*
** EPITECH PROJECT, 2023
** MUL_my_defender_2018
** File description:
** Created by mcarpentier
*/

#include "defender.h"

sfIntRect create_IntRect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}

my_object_t *generate_object(char *texture_path, int x, int y)
{
    my_object_t *object = malloc(sizeof(my_object_t));

    object->spr = sfSprite_create();
    object->texture = sfTexture_createFromFile(texture_path, NULL);
    sfSprite_setTexture(object->spr, object->texture, sfTrue);
    object->rect = create_IntRect(0, 0, y, x);
    sfSprite_setTextureRect(object->spr, object->rect);
    return (object);
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
