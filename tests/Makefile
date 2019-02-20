##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## 
##

SRC_DIR=        $(realpath ../src/)

SRC=           $(SRC_DIR)/isneg.c
SRC_DIR			=		$(realpath ../ex00)
SRC_DIR1		=		$(realpath ../ex01)

SRC				=		$(SRC_DIR)/.c							\
						$(SRC_DIR)/lists_functions_2.c

SRC_UT_DIR		=		$(realpath .)

SRC_UT=         $(SRC_UT_DIR)/unit_test_function_basic.c	\
		$(SRC_UT_DIR)/unit_test_function_cinout.c
SRC_UT			=		$(SRC_UT_DIR)/unit_test_function_1.c	\
						$(SRC_UT_DIR)/unit_test_function_tree.c

OBJ				=		$(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS=         -Wall -Wextra --coverage -I../include/
=======
CFLAGS			=		-Wall -Wextra --coverage -I.

LDFLAGS			=		-lcriterion -lgcov

NAME			=		unit_tests

all:			$(NAME) run

$(NAME):		$(OBJ)
				cc -o $(NAME) $(OBJ) $(LDFLAGS)

run:			$(NAME)
				./unit_tests

clean:
				@rm -f $(OBJ)
				@find -type f -name '*.gcda' -delete
				@find -type f -name '*.gcno' -delete

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all $(NAME) run clean fclean re
