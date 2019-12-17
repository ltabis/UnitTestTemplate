##
## EPITECH PROJECT, 2019
## imageCompressor
## File description:
## makefile
##

SRC_DIR		=	$(realpath ./src)

NAME		=	myHaskellProgram

TEST_NAME	=	test_coverage

XDG			=	$(shell which xdg-open)

RM			=	rm -f

PA_TEST		= `stack path --local-install-root`/hpc/$(NAME)/$(NAME)-test/hpc_index.html

PA			= `stack path --local-install-root`/bin/imageCompressor-exe

all:	$(NAME)

$(NAME):
		stack build
		@cp $(PA) ./$(NAME)

tests_run:
	@rm -f $(PA_TEST)
	stack test --coverage
ifneq ($(XDG), /dev/null)
	@xdg-open $(PA_TEST)
else
	@echo "\e[1;31mERROR: No default browser found ! $<\e[0m"
	@echo "\e[1;34mFor coverage report, you can open manually the file:\n$(PA_TEST)\n$<\e[0m"
endif

debug:
	stack build --trace
	@cp $(PA) ./$(NAME)

clean:
		$(RM) $(SRC_DIR)/*~
		$(RM) $(SRC_DIR)/\#*\#
		$(RM) *~
		$(RM) \#*\#

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all, clean, fclean, re
