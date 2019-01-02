/*
** EPITECH PROJECT, 2017
** levels
** File description:
** levels
*/

#include "./include/my.h"

int	check_level(game_t *game, char **av)
{
	int level = my_getnbr(av[1]);

	if (level > 20)
		return (ERROR);
	game->my_event.speed = level * 10;
	return (SUCCESS);
}

int	duck_params(game_t *game)
{
	game->bg.texture = sfTexture_createFromFile("background.png", NULL);
	if (!game->bg.texture)
		return (ERROR);
	game->duck.texture_two = sfTexture_createFromFile("sprite.png", NULL);
	if (!game->duck.texture_two)
		return (ERROR);
	game->bg.sprite = sfSprite_create();
	game->duck.sprite_two = sfSprite_create();
	sfSprite_setTexture(game->bg.sprite, game->bg.texture, sfTrue);
	sfSprite_setTexture(game->duck.sprite_two, game->duck.texture_two, sfTrue);
	if (!(game->my_music.shoot = sfMusic_createFromFile("gun.wav")))
		return (ERROR);
	else
		return (SUCCESS);
}

int	ufo_params(game_t *game)
{
	game->bg.texture = sfTexture_createFromFile("bgmy.png", NULL);
	if (!game->bg.texture)
		return (ERROR);
	game->duck.texture_two = sfTexture_createFromFile("ufo.png", NULL);
	if (!game->duck.texture_two)
		return (ERROR);
	game->bg.sprite = sfSprite_create();
	game->duck.sprite_two = sfSprite_create();
	sfSprite_setTexture(game->bg.sprite, game->bg.texture, sfTrue);
	sfSprite_setTexture(game->duck.sprite_two, game->duck.texture_two, sfTrue);
	if (!(game->my_music.shoot = sfMusic_createFromFile("shoot.wav")))
		return (ERROR);
	else
		return (SUCCESS);
}

int	check_map(game_t *game, char **av)
{
	if (!(check_music(game) == SUCCESS))
		return (ERROR);
	else if ((my_strcmp(av[2], "duck") == 0) && (duck_params(game) == SUCCESS))
		return (SUCCESS);
	else if ((my_strcmp(av[2], "ufo") == 0) && (ufo_params(game) == SUCCESS))
		return (SUCCESS);
	return (ERROR);
}

int	check_music(game_t *game)
{
	if (!(game->my_music.bgmusic = sfMusic_createFromFile("bgmusic.wav")) ||
	    !(game->my_music.miss = sfMusic_createFromFile("miss.wav")))
	  return (ERROR);
	sfMusic_play(game->my_music.bgmusic);
	return (SUCCESS);
}
