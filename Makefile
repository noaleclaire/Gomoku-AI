##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC			=	main.cpp				\
				src/AI.cpp				\
				src/Board.cpp			\
				src/BrainCommand.cpp	\
				src/Command.cpp			\
				src/Info.cpp			\

OBJ			=	$(SRC:%.cpp=%.o)

CFLAGS 		=	-std=c++20 -Wall -Wextra

CC			=	g++

NAME		=	pbrain-gomoku-ai

RM 			=  	rm -f

ifeq ($(OS),Windows_NT)
	NAME	=	pbrain-gomoku-ai.exe
	RM 		=	del
endif

all: $(NAME)

$(NAME) :
		$(CC) $(SRC) -o $(NAME) $(CFLAGS)

ifeq ($(OS), Windows_NT)
clean :
	$(RM) $(NAME)
fclean : clean
else
clean :
	$(RM) $(OBJ)
fclean : clean
	$(RM) $(NAME)
endif

re:		 fclean all

.PHONY:	all core games graphicals clean fclean re
