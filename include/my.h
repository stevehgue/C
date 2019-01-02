/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#define ERROR -1

#define SUCCESS 0

#define HELP "You have 2 lives, if you miss, you lose one, if you let the duck pass, it's game over.\nClick on the duck to shut it the hell down and do the highest score.\nPut the level number you want as first argument and 'duck' or 'ufo' as second argument to change the map. Good luck !!!!\n"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct my_music {
	sfMusic* bgmusic;
	sfMusic* shoot;
	sfMusic* miss;
} my_music_t;

typedef struct bg {
	sfTexture* texture;
	sfSprite* sprite;
} bg_t;

typedef struct duck {
	sfTexture* texture_two;
	sfSprite* sprite_two;
	
} duck_t;

typedef struct window {
	sfRenderWindow* window;
	int mouse_x;
	int mouse_y;
	float sprite_two_top;
	float sprite_two_left;
	float sprite_two_height;
	float sprite_two_width;
} window_t;

typedef struct my_event {
	sfIntRect rect;
	sfEvent event;
	sfClock *clock;
	sfTime time;
	float seconds;
	int score;
	int miss;
	int hit;
	sfVector2f duck;
	sfVector2f reset;
	float speed;
} my_event_t;

typedef struct game {
	struct bg bg;
	struct duck duck;
	struct window window;
	struct my_event my_event;
	struct my_music my_music;
} game_t;

void	my_putchar(char c);
char	my_putstr(char const *str);
int	my_strcmp(char const *s1, char const *s2);
void	my_help(void);
sfIntRect	duck_mov(game_t *game);
void	move_rect(game_t *game, int offset, int max_value);
void	animation_loop(game_t *game, int offset, int max_vule);
int	my_window(char **av);
int	my_params_init(game_t *game);
void	ressources_destroy(game_t *game);
void	my_game(game_t *game);
void	analyse_events(game_t *game);
void	manage_click(sfRenderWindow *window);
void	close_window(sfRenderWindow *window);
void	err_putchar(char c);
int	invalid_output(void);
int	score(game_t *game);
int	shoot(game_t *game);
int	my_put_nbr(int nb);
void	score_and_rect_init(game_t *game);
int	check_level(game_t *game, char **av);
int	my_getnbr(char *str);
int	check_map(game_t *game, char **av);
int	failure_to_load(void);
int	duck_params(game_t *game);
int	ufo_params(game_t *game);
int	check_music(game_t *game);
void	my_music_stop(game_t *game);

#endif /* !MY_H_ */
