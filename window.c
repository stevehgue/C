/*
** EPITECH PROJECT, 2017
** game window
** File description:
** window
*/

#include "./include/my.h"

void score_and_rect_init(game_t *game)
{
	game->my_event.rect.top = 0;
	game->my_event.rect.left = 0;
	game->my_event.rect.width = 110;
	game->my_event.rect.height = 110;
	game->my_event.hit = 0;
	game->my_event.miss = 0;
}

int   my_params_init(game_t *game)
{
	sfVideoMode mode = {800, 600, 32};
	
	score_and_rect_init(game);
	game->my_event.clock = sfClock_create();
	game->window.window = sfRenderWindow_create(mode, "My Hunter",
						    sfResize |
					    sfClose, NULL);
	if (!game->window.window)
		return (ERROR);
	sfRenderWindow_setFramerateLimit(game->window.window, 60);
	return (SUCCESS);
}

void       move_rect(game_t *game, int offset, int max_value)
{
	if (shoot(game) == 1)
		game->my_event.speed += 10.0;
	game->my_event.duck =(sfVector2f){game->my_event.speed, 0};
        game->my_event.rect.left += 110;
	sfSprite_move(game->duck.sprite_two, game->my_event.duck); 
        if (game->my_event.rect.left == max_value)
                game->my_event.rect.left = offset;
        if (sfSprite_getGlobalBounds(game->duck.sprite_two).left > 800) {
		game->my_event.miss = 2;
		score(game);
	}
}

void  animation_loop(game_t *game, int offset, int max_value)
{
        if (game->my_event.seconds > 0.2) {
                move_rect(game, offset, max_value);
                sfClock_restart(game->my_event.clock);
        }
}

int    my_window(char **av)
{
	game_t game;

	if ((check_map(&game, av) == ERROR) || (check_level(&game, av) == ERROR) ||
	    (my_params_init(&game) == ERROR))
		return (ERROR);
	else {
		my_putstr("use the -h option for more informations\n");
		while (sfRenderWindow_isOpen(game.window.window)) {
			while (sfRenderWindow_pollEvent(game.window.window,
							&game.my_event.event))
				analyse_events(&game);
			my_game(&game);
			sfRenderWindow_drawSprite(game.window.window,
						  game.duck.sprite_two,
						  NULL);
			sfRenderWindow_display(game.window.window);
		}
		ressources_destroy(&game);
		return (SUCCESS);
	}
}
