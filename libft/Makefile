# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lgutter <lgutter@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/16 14:00:27 by lgutter       #+#    #+#                  #
#    Updated: 2019/11/29 12:56:31 by lgutter       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
include ./libftsources

CFLAGS := -Wall -Wextra -Werror

SRCS := $(LFTSOURCES:%= %.c)
OBJS := $(LFTSOURCES:%= %.o)

C_RESET = \033[0;00m
C_CLEAN = \033[38;5;159m
C_FCLEAN = \033[38;5;81m
C_OBJECTS = \033[38;5;75m
C_LIB = \033[38;5;33m
C_LINES = \033[38;5;250m

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $@ $^
	@ranlib $(NAME)
	@echo "$(C_LIB)Libft.a has been compiled$(C_RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -rf $(OBJS)
	@echo "$(C_CLEAN)Libft object files removed$(C_RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(C_FCLEAN)Libft.a removed$(C_RESET)"
	@echo "$(C_LINES)- - - - - - - - - -$(C_RESET)"

re: fclean
	$(MAKE) all

.PHONY: all objects clean fclean re
