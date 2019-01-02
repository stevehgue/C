/*
** EPITECH PROJECT, 2017
** do_op.c
** File description:
** do_op.c
*/

#include "my.h"

int	sum(int ac, char **av)
{
	int a = my_getnbr(av[1]);
	int b = my_getnbr(av[3]);

	return (a + b);
}

int	sub(int ac, char **av)
{
	int a = my_getnbr(av[1]);
	int b = my_getnbr(av[3]);

	return (a - b);
}

int	mult(int ac, char **av)
{
	int a = my_getnbr(av[1]);
	int b = my_getnbr(av[3]);

	return (a * b);
}
