##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=gcc

RM	=rm -f

SRCS	=main.c		\
	 do_op.c	\
	 my_getnbr.c	\
	 my_putchar.c	\
	 my_put_nbr.c	\
	 my_strcmp.c

NAME	=do-op

OBJS	=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(OBJS)

re: fclean all
