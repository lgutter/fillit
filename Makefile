# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aholster <aholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/08 15:18:49 by aholster       #+#    #+#                 #
#    Updated: 2019/03/22 16:42:33 by aholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


FILES := fillit.c solver.c

HEADER := fillit.h

NORM := norminette $(FILES) $(HEADER) | grep -e "Error"  -e "Warning" -B 1

CC := gcc -Wall -Werror -Wextra

NAME := fillit

all: $(NAME)

$(NAME):
	@${CC} $(FILES)

clean:
	@rm -rf *~ \#*\# .DS_Store

fclean: clean
	@rm -rf $(NAME)

re: fclean all

norm:
	@echo "**+++=====*=====*=====*=====OUT=====*=====*=====*=====+++**"
	@$(NORM) || TRUE 
	@echo "**+++=====*=====*=====*=====*=====*=====*===*=====*=====+++**"

add:
	@git add $(FILES) $(HEADER) Makefile author
	git status

push:
ifdef MSG
	@make norm
	@git commit -m "$(MSG)"
	git push
else
	@echo 'Usage: make push MSG="Message here"'
endif