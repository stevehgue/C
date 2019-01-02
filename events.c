/*
** EPITECH PROJECT, 2017
** events and click
** File description:
** events
*/

#include "./include/my.h"

int	score(game_t *game)
{
	if (game->my_event.miss == 2) {
		sfRenderWindow_close(game->window.window);
		my_putstr("Game over, your final score is: ");
		my_put_nbr(game->my_event.hit);
		write(1, ".\n", 2);
	}
	return (SUCCESS);
}

void	analyse_events(game_t *game)
{
	game->my_event.reset = (sfVector2f){-120, rand() % 490};
	if (game->my_event.event.type == sfEvtClosed)
		sfRenderWindow_close(game->window.window);
        else if (game->my_event.event.type == sfEvtMouseButtonPressed &&
	shoot(game) == 1){
		sfSprite_setPosition(game->duck.sprite_two,
				     game->my_event.reset);
		sfMusic_play(game->my_music.shoot);
		game->my_event.hit++;
	}
        else if (game->my_event.event.type == sfEvtMouseButtonPressed &&
		 shoot(game) == 0) {
		sfMusic_play(game->my_music.miss);
		game->my_event.miss++;
	}
	score(game);
}


int	shoot(game_t *game)
{
	if(sfMouse_getPosition((sfWindow *) game->window.window).x >
	   sfSprite_getGlobalBounds(game->duck.sprite_two).left &&
	   sfMouse_getPosition((sfWindow *) game->window.window).x <
	   (sfSprite_getGlobalBounds(game->duck.sprite_two).left +
	    sfSprite_getGlobalBounds(game->duck.sprite_two).width)
	   && sfMouse_getPosition((sfWindow *) game->window.window).y >
	   sfSprite_getGlobalBounds(game->duck.sprite_two).top &&
	   sfMouse_getPosition((sfWindow *) game->window.window).y <
	   (sfSprite_getGlobalBounds(game->duck.sprite_two).top +
	    sfSprite_getGlobalBounds(game->duck.sprite_two).height))
		return (1);
	else
		return (0);
}
