/*
** EPITECH PROJECT, 2017
** error output
** File description:
** errors
*/

#include "./include/my.h"

void	err_putchar(char c)
{
	write(2, &c, 1);
}

int	invalid_output(void)
{
	char *str = "invalid output, use -h option for more informations\n";

	for (int i = 0; str[i] != '\0'; i++)
		err_putchar(str[i]);
	return (ERROR);
}

int	failure_to_load(void)
{
	char *str = "failed to load a file\n";

	for (int i = 0; str[i] != '\0'; i++)
		err_putchar(str[i]);
	return (ERROR);
}
