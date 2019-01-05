##
## Makefile for Makefile in /home/samuel/CPE/CPE_2016_matchstick
## 
## Made by Samuel
## Login   <samuel.rousseaux@epitech.eu>
## 
## Started on  Fri Feb 17 13:22:19 2017 Samuel
## Last update Mon Feb 20 18:09:02 2017 Samuel
##

SRCS=	./src/ai.c		\
	./src/create_map.c	\
	./src/error.c		\
	./src/game.c		\
	./src/get_next_line.c	\
	./src/main.c 		\
	./src/useful.c		\
	./src/useful_2.c	\
	./src/useful_map.c	\
	./src/verify.c		\
	./src/verify_input.c	\

OBJS=	$(SRCS:.c=.o)

NAME=	matchstick

CC=	gcc

CFLAGS=	-W -Werror -Wall -I./include

RM=	rm -f

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	re fclean clean all
