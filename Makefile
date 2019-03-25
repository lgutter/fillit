# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aholster <aholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/08 15:18:49 by aholster       #+#    #+#                 #
#    Updated: 2019/03/25 15:51:18 by aholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


FILES := fillit.c solver.c shift_corner.c place_tet.c smallest_map.c\
check_tet.c check_hash.c increment_offset.c place_final.c remove_tet.c\
print_result.c

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

fclean: clean
	@rm -rf $(NAME)

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