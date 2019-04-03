# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aholster <aholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/08 15:18:49 by aholster       #+#    #+#                 #
#    Updated: 2019/04/03 13:45:00 by lgutter       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

DATE = $(shell date +"%T")

FILES := main.c fillit.c solver.c shift_corner.c place_tet.c smallest_map.c\
check_tet.c increment_offset.c remove_tet.c print_result.c read_tet.c\
calc_empty.c

HEADER := fillit.h

NORM := norminette $(FILES) $(HEADER) | grep -e "Error"  -e "Warning" -B 1

CC := gcc -Wall -Werror -Wextra

NAME := fillit

all: $(NAME)

$(NAME):
	@make -C libft/
	@echo "\033[0;33mStarting assembly of $(NAME) at $(DATE)...\033[0;00m"
	@${CC} $(FILES) -I ./libft -L ./libft -lft -o $(NAME)
	@echo "\033[0;32m$(NAME) succesfully assembled at $(DATE)!\033[0;00m\n"

clean:
	@rm -rf *~ \#*\# .DS_Store
	@echo "\033[0;31mPests exterminated!\033[0;00m\n"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft/
	@echo "\033[0;31mObituary of $(NAME): deceased at $(DATE).\033[0;00m\n"

re: fclean all

norm:
	@echo "**+++=====*=====*=====*=====*{\033[0;31mOUT\033[0;00m}\
	*=====*=====*=====*=====+++**"
	@$(NORM) || TRUE 
	@echo "**+++=====*=====*=====*=====*=====*=====*=====*=====*=====+++**"

add:
	@git add $(FILES) $(HEADER) Makefile author
	git status

push:
#ifdef MSG
	@make norm
	@git commit
	git push
#else
#	@echo "\033[0;31mUsage: make push MSG=\"Message here\"\033[0;00m"
#endif