/*
** EPITECH PROJECT, 2017
** ressources management
** File description:
** destroying ressources
*/

#include "./include/my.h"

void	ressources_destroy(game_t *game)
{
	sfClock_destroy(game->my_event.clock);
	sfSprite_destroy(game->bg.sprite);
	sfSprite_destroy(game->duck.sprite_two);
	sfTexture_destroy(game->bg.texture);
	sfTexture_destroy(game->duck.texture_two);
	sfRenderWindow_destroy(game->window.window);
	sfMusic_destroy(game->my_music.bgmusic);
	sfMusic_destroy(game->my_music.shoot);
	sfMusic_destroy(game->my_music.miss);
}

void	my_game(game_t *game)
{
	sfRenderWindow_clear(game->window.window, sfBlack);
	sfRenderWindow_drawSprite(game->window.window,
				  game->bg.sprite, NULL);
	game->my_event.time = sfClock_getElapsedTime(game->my_event.clock);
	game->my_event.seconds = game->my_event.time.microseconds /
		1000000.0;
	animation_loop(game, 0, 330);
	sfSprite_setTextureRect(game->duck.sprite_two, game->my_event.rect);
}
