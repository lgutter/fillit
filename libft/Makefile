# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aholster <aholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/16 15:46:43 by aholster       #+#    #+#                 #
#    Updated: 2019/03/24 18:15:11 by aholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

BONOR := lstnew lstdelone lstdel lstadd lstiter lstmap

ADVOR := memalloc memdel strnew strdel strclr striter striteri\
 strmap strmapi strequ strnequ strsub strjoin strtrim strsplit\
 itoa putchar putstr putendl putnbr putchar_fd putstr_fd putendl_fd\
 putnbr_fd 

BASICOR := memset bzero memcpy memccpy memmove memchr memcmp\
 strlen strdup strcpy strncpy strcat strncat strlcat strchr strrchr\
 strstr strnstr strcmp strncmp\
 atoi isalpha isdigit isalnum isascii isprint toupper tolower

CUSOR:= nbrlen del lstaddend itoba iswhitespace isprime power putstrarr\
 putstrarr_fd strarrdel strarrtolst lsttostrarr lstleng min max constrain\
 segdefault factorial count_if range sqrt absneg swap lsttardest memjoin \
 memdup strarrnew textangle stralloc


HEAD = libft.h

BASIC = $(BASICOR:%=./ft_%.c)
BASICO = $(BASICOR:%=./ft_%.o)

ADVC = $(ADVOR:%=./ft_%.c) $(BONOR:%=./ft_%.c) $(CUSOR:%=./ft_%.c)
ADVO = $(ADVOR:%=./ft_%.o) $(BONOR:%=./ft_%.o) $(CUSOR:%=./ft_%.o)

NORM = norminette $(BASIC) $(ADVC) $(HEAD) | grep -e "Error"  -e "Warning" -B 1

GCCC = ${CC} -c
CC = gcc -Wall -Werror -Wextra
AR = ar r

NAME = libft.a

all: $(ADVO) $(BASICO) $(NAME)

$(NAME): $(ADVO) $(BASICO)
	@${GCCC} ${BASIC} $(ADVC)
	@$(AR) $(NAME) $(BASICO) $(ADVO)
	@ranlib $(NAME)

clean:
	@rm -rf $(BASICO) $(ADVO) *~ \#*\# .DS_Store

fclean: clean
	@rm -rf $(NAME)

re: fclean all

lab: re
	@$(CC) -L. -lft -I./ $(TEBAS) $(TEADV) ./test/main.c -o adept

norm:
	@echo "**+++=====*=====*=====*=====OUT=====*=====*=====*=====+++**"
	@$(NORM) || TRUE 
	@echo "**+++=====*=====*=====*=====*=====*=====*===*=====*=====+++**"

add:
	@git add $(BASIC) $(ADVC) $(HEAD) Makefile author
	git status

push:
ifdef MSG
	@make norm
	@git commit -m "$(MSG)"
	git push
else
	@echo "ERROR: NO MESSAGE"
endif