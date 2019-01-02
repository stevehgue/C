/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** my_putstr.c
*/

#include "./include/my.h"

char	my_putstr(char const *str)
{
	if (str == NULL)
		return (84);
	else
		for (int i = 0; str[i] != '\0'; i++)
			write(1, &str[i], 1);
	return (0);
}
