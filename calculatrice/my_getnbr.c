/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** my_getnbr.c
*/

int	my_getnbr(char const *str)
{
	int a = 1;
	int b = 0;

	for (*str; *str == '-' || *str == '+'; str++) {
		if (*str == '-')
			a = - a;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9') {
		if (b > 214748364)
			return (0);
		if (b == 214748364 && *str > 7 && a == 1)
			return (0);
		if (b == 214748464 && *str > 8 && a == - 1)
			return (0);
		b = b * 10 + *str - 48;
		str++;
	}
	if (a == -1)
		b = - b;
	return (b);
}
