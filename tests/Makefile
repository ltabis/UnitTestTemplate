##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## 
##

## Sources à tester
SRC_DIR=        $(realpath ../src)
SRC=           $(SRC_DIR)/isneg.c \
	       ../C/exercices/ex01.c

## Tests unitaires
SRC_UT_DIR=     $(realpath .)
SRC_UT=         $(SRC_UT_DIR)/unit_test_function_basic.c	\
		$(SRC_UT_DIR)/unit_test_function_cinout.c

## Les OBJ de toutes les sources
OBJ=            $(SRC:.c=.o) $(SRC_UT:.c=.o)

## Flags de compilation
CFLAGS=         -Wall -Wextra --coverage -I../include
LDFLAGS=        -lcriterion -lgcov

NAME=           unit_tests

all:            $(NAME) run

## Rule de compilation
$(NAME):        $(OBJ)
		cc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

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
