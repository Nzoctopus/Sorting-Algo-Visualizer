##
## EPITECH PROJECT, 2023
## SORT
## File description:
## Makefile
##

CC = g++

NAME = visualiser

SRC = $(shell find -name "*.cpp")

OBJ = $(SRC:.cpp=.o)

all: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -l sfml-graphics -l sfml-window \
	-l sfml-system -l sfml-audio -lm

clean:
	rm $(OBJ)
	rm -rf *#
	rm -rf *~

fclean: clean
	rm -rf $(NAME)

re: fclean all
