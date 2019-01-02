/*
** EPITECH PROJECT, 2017
** my_putnbr.c
** File description:
** my_putnbr.c
*/

#include "./include/my.h"

int	my_put_nbr(int nb)
{
	int b;

	if (nb < 0) {
		my_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 0) {
		if (nb >= 10) {
			b = nb % 10;
			nb = (nb - b) / 10;
			my_put_nbr(nb);
			my_putchar(b + '0');
		}
		else
			my_putchar('0' + nb % 10);
	}
	return (0);
}
