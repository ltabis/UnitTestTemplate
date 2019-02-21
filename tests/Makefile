##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for unit testing of my_printf
##

## Sources à tester
SRC_DIR=        $(realpath ../ex00)
SRC_DIR1=        $(realpath ../ex01)

SRC=           	$(SRC_DIR)/.c	\
	$(SRC_DIR)/lists_functions_2.c


## Tests unitaires
SRC_UT_DIR=     $(realpath .)

SRC_UT=         $(SRC_UT_DIR)/unit_test_function_1.c	\
		$(SRC_UT_DIR)/unit_test_function_tree.c

## Les OBJ de toutes les sources
OBJ=            $(SRC:.c=.o) $(SRC_UT:.c=.o)

## Flags de compilation
CFLAGS=         -Wall -Wextra --coverage -I.
LDFLAGS=        -lcriterion -lgcov

NAME=           unit_tests

all:            $(NAME) run

## Rule de compilation
$(NAME):        $(OBJ)
		cc -o $(NAME) $(OBJ) $(LDFLAGS)

## Rule de test
run:		$(NAME)
		./unit_tests


## Rule pour clean le repo
clean:
		@rm -f $(OBJ)
		@find -type f -name '*.gcda' -delete
		@find -type f -name '*.gcno' -delete
fclean:         clean
		rm -f $(NAME)

re:             fclean all
