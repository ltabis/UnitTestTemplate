NAME			:=		unit_tests

SRC_DIR			:=		$(realpath .)
SRC				:=		$(SRC_DIR)/getnbr_check.c

UT_SRC_DIR		:=		$(realpath .)
UT_SRC			:=		$(UT_SRC_DIR)/test_isdigit_check.c		\
						$(UT_SRC_DIR)/test_getnbr_check.c

OBJ				:=		$(SRC:.c=.o) $(UT_SRC:.c=.o)

CFLAGS			+=		-Wall -Wextra --coverage
LDFLAGS			+=		-lcriterion -lgcov

all:			$(NAME)

$(NAME):		$(OBJ)
				gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
				@rm -rf $(OBJ)
				@find -type f -name '*.gcda' -delete
				@find -type f -name '*.gcno' -delete

fclean:			clean
				rm -rf $(NAME)

re:				fclean $(NAME)

.PHONY:			all $(NAME) clean fclean re
