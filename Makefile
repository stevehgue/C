##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

CC	= gcc -g3 -Wall -Wextra -Werror -l c_graph_prog

NAME	= my_hunter

SRCS	= main.c	\
	  my_strcmp.c	\
	  my_putchar.c	\
	  my_putstr.c	\
	  my_help.c	\
	  window.c	\
	  ressources.c	\
	  err_str.c	\
	  events.c	\
	  my_put_nbr.c	\
	  levels.c	\
	  my_getnbr.c

CPPFLAGS = -I ./include

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
