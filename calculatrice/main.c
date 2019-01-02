/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main.c
*/

#include "my.h"

int	divide(int ac, char **av)
{
	int a = my_getnbr(av[1]);
	int b = my_getnbr(av[3]);

	if (b == 0) {
		write(2, "Stop: division by zero", 23);
		return (84);
	}
	my_put_nbr(a / b);
}

int	modulo(int ac, char **av)
{
	int a = my_getnbr(av[1]);
	int b = my_getnbr(av[3]);

	if (b == 0) {
		write(2, "Stop: modulo by zero", 21);
		return (84);
	}
	my_put_nbr(a % b);
}

int	funct_prt(int ac, char **av)
{
	int	(*fptr[5])(int, char **);

	fptr[0] = &sum;
	fptr[1] = &sub;
	fptr[2] = &divide;
	fptr[3] = &mult;
	fptr[4] = &modulo;
	if (my_strcmp(av[2], "+") == 0)
		my_put_nbr(fptr[0](ac, av));
	if (my_strcmp(av[2], "-") == 0)
		my_put_nbr(fptr[1](ac, av));
	if (my_strcmp(av[2], "/") == 0)
		fptr[2](ac, av);
	if (my_strcmp(av[2], "*") == 0)
		my_put_nbr(fptr[3](ac, av));
	if (my_strcmp(av[2], "%") == 0)
		fptr[4](ac, av);
	write(1, "\n", 1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 4 || (my_strcmp(av[2], "+") != 0 &&my_strcmp(av[2], "-") != 0 && my_strcmp(av[2], "%") != 0 &&
			my_strcmp(av[2], "*") != 0 && my_strcmp(av[2], "/") != 0))
		return (-1);
	funct_prt(ac, av);
	return (0);
}
