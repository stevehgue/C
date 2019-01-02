/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include "./include/my.h"

int	main(int ac, char **av)
{	
	if (ac == 2 && my_strcmp(av[1], "-h") == 0)
		my_help();
        else if (((ac == 3  && my_strcmp(av[2], "ufo") == 0) ||
		  (ac == 3  && my_strcmp(av[2], "duck") == 0)) &&
		 my_window(av) == SUCCESS)
		return (0);
	else if (ac != 3) {
		invalid_output();
		return (84);
	}
	else
		return (84);
}
