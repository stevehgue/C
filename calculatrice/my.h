/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
# define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	my_put_nbr(int nb);
int	my_getnbr(char const *str);
int	my_strcmp(char const *s1, char const *s2);
void	my_putchar(char c);
int	sum(int ac, char **av);
int	sub(int ac, char **av);
int	mult(int ac, char **av);

#endif /* !MY_H_ */
