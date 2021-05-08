##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makesfiles
##

SRC	=	src/main.c		\
		src/get_info.c		\
		src/change_grid.c	\
		src/brain_game.c	\
		src/brain_game_2.c	\
		src/error_handler.c	\
		src/sigaction_extra.c

NAME 	=	navy

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -Wall -Wextra -I include -o $(NAME) -g

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all
