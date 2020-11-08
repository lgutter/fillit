# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aholster <aholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/08 15:18:49 by aholster      #+#    #+#                  #
#    Updated: 2019/09/10 20:24:10 by lgutter       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FILES := main.c fillit.c solver.c shift_corner.c place_tet.c\
check_tet.c increment_offset.c remove_tet.c print_result.c parse_tet.c\
calc_empty.c

HEADER := fillit.h

OBJS := $(FILES:%.c= %.o)

INCLUDES := -I ./libft

CFLAGS := -Wall -Werror -Wextra

NAME := fillit

all: $(NAME)


$(NAME): $(OBJS)
	@$(MAKE) --no-print-directory -C libft/
	@${CC} $(OBJS) $(INCLUDES) -L ./libft -lft -o $(NAME)
	@echo "\033[0;32m$(NAME) successfully assembled!\033[0;00m\n"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

lclean:
	@rm -rf *~ \#*\# .DS_Store $(OBJS)
	@echo "\033[0;31mPests exterminated!\033[0;00m\n"

clean: lclean
	@$(MAKE) --no-print-directory clean -C libft/

fclean: lclean
	@rm -rf $(NAME)
	@$(MAKE) --no-print-directory fclean -C libft/
	@echo "\033[0;31mObituary of $(NAME): Deceased on $(shell date).\033[0;00m\n"

re: fclean
	@$(MAKE) --no-print-directory all

