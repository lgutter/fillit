# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aholster <aholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/16 15:46:43 by aholster       #+#    #+#                 #
#    Updated: 2019/04/01 16:59:19 by aholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

BONOR := lstnew lstdelone lstdel lstadd lstiter lstmap

ADVOR := memalloc memdel strnew strdel strclr striter striteri strmap\
 strmapi strequ strnequ strsub strjoin strtrim strsplit itoa putchar\
 putstr putendl putnbr putchar_fd putstr_fd putendl_fd putnbr_fd 

BASICOR := memset bzero memcpy memccpy memmove memchr memcmp\
 strlen strdup strcpy strncpy strcat strncat strlcat strchr strrchr\
 strstr strnstr strcmp strncmp\
 atoi isalpha isdigit isalnum isascii isprint toupper tolower

CUSOR:= nbrlen del lstaddend itoba iswhitespace isprime power putstrarr\
 putstrarr_fd strarrdel strarrtolst lsttostrarr lstleng min max constrain\
 segdefault factorial count_if range sqrt absneg swap lsttardest memjoin \
 memdup strarrnew textangle stralloc bitprint


FILEC = $(ADVOR:%=./ft_%.c) $(BONOR:%=./ft_%.c)\
		$(CUSOR:%=./ft_%.c) $(BASICOR:%=./ft_%.c)

OBJ =	$(ADVOR:%=./ft_%.o) $(BONOR:%=./ft_%.o)\
		$(CUSOR:%=./ft_%.o) $(BASICOR:%=./ft_%.o)

HEAD = libft.h

NAME = libft.a

NORM = norminette $(FILEC) $(HEAD) | grep -e "Error"  -e "Warning" -B 1

GCCC = ${CC} -c
CC = gcc -Wall -Werror -Wextra
AR = ar rcs

all: $(OBJ) $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[0;33m$(NAME) Compiled\033[0;00m"

%.o: %.c
	@$(GCCC) -o $@ $<

clean:
	@echo "\033[0;31mInitializing of Summary Deletions\033[0;00m"
	@rm -rf $(OBJ) *~ \#*\# .DS_Store
	@find "./" -type f \( -name '*~' -o -name '\#*\#' -o -name '.DS_Store' \)\
	 -exec rm -rfv {} \;
	@echo "\033[0;31mThe Emperor Protects...\033[0;00m"

fclean: clean
	@rm -rfv $(NAME)

re: fclean all

norm:
	@echo "**+++=====*=====*=====*=====*{\033[0;31mOUT\033[0;00m}\
	*=====*=====*=====*=====+++**"
	@$(NORM) || TRUE 
	@echo "**+++=====*=====*=====*=====*=====*=====*===*=====*=====+++**"

add:
	@git add $(FILEC) $(HEAD) Makefile author
	git status

push: norm
ifdef MSG
	@git commit -m "$(MSG)"
	git push
else
	@git commit
	git push
endif