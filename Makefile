##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## All purpose Makefile by Tabis Lucas
##

SRC_DIR=        $(realpath src/)

SRC=	$(wildcard $(SRC_DIR)/*.c)

CFLAGS=	-Wall -Wextra -Werror -Iinclude

NAME=	project

OBJ=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
		cc -o $(NAME) $(OBJ) $(LDFLAGS)

tests_run:
		cd tests/ && $(MAKE)

clean:
		@$(RM) -f $(OBJ)
		@find -type f -name '*~' -delete
		@find -type f -name '#*#' -delete
		@find -type f -name '*.o' -delete
		@find -type f -name '*.gcda' -delete
		@find -type f -name '*.gcno' -delete
		@$(RM) -r -f *~ \#*\#

fclean:         clean
		@$(RM) -f $(NAME)

re:		fclean all

.PHONY:	tests_run clean fclean re
