# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aholster <aholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/08 15:18:49 by aholster       #+#    #+#                 #
#    Updated: 2019/03/31 18:57:29 by aholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


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
	@${CC} $(FILES) -I ./libft -L ./libft -lft -o $(NAME)

clean:
	@rm -rf *~ \#*\# .DS_Store
	@make clean -C libft/

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft/

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