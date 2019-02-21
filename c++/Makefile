##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for unit testing of my_printf
##

SRC_EX2_DIR=        $(realpath ../src)

SRC=           $(SRC_EX2_DIR)/...cpp

SRC_UT_DIR=     $(realpath .)

SRC_UT=	$(SRC_UT_DIR)/...cpp

OBJ=            $(SRC:.cpp=.o) $(SRC_UT:.cpp=.o)

CFLAGS=         -Wall -Wextra -I. --coverage

LDFLAGS=        -lcriterion -lgcov

NAME=           unit_tests

all:            $(NAME) run

$(NAME):        $(OBJ)
		g++ -o $(NAME) $(OBJ) $(LDFLAGS)

run:		$(NAME)
		./unit_tests

clean:
		@rm -f $(OBJ)
		@find -type f -name '*.gcda' -delete
		@find -type f -name '*.gcno' -delete

fclean:         clean
		rm -f $(NAME)

re:             fclean all
