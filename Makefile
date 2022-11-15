##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC			=	main.cpp				\
				src/Board.cpp			\
				src/BrainCommand.cpp	\
				src/Command.cpp			\
				src/Info.cpp			\

OBJ			=	$(SRC:%.cpp=%.o)

CFLAGS 		=	-std=c++20 -Wall -Wextra

NAME		=	pbrain-gomoku-ai

CC = g++

RM = rm -f

all: $(NAME)

$(NAME) :
		$(CC) $(SRC) -o $(NAME)

clean :
			$(RM) $(OBJ)

fclean :	clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:	all core games graphicals clean fclean re