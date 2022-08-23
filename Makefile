# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnabil <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 15:14:45 by rnabil            #+#    #+#              #
#    Updated: 2022/08/16 15:18:45 by rnabil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
Flags = -Wall -Wextra -Werror
Printf_functions = ft_printf/ft_printf  ft_printf/print_str\
		   ft_printf/print_addresse ft_printf/print_char \
		   ft_printf/print_hex_lower ft_printf/print_hex_upper \
		   ft_printf/print_nbr ft_printf/print_nbr_unsigned
Src_functions    = src/src src/split src/src2 src/parsing_utils \
			src/parsing
Main_functions   = pipex

OBJS_main   = $(Main_functions:=.o)
OBJS_src    = $(Src_functions:=.o)
OBJS_printf = $(Printf_functions:=.o)
NAME = pipex

Compiling = 1
Color1 = \e[92;5;118m
Color2 = \033[0;33m

.Phony: all clean fclean re bonus

all : $(NAME)

$(NAME): $(OBJS_main) $(OBJS_printf) $(OBJS_src)
	@$(CC) $(Flags) $(OBJS_printf) $(OBJS_main) $(OBJS_src) -o $(NAME)
	@printf "${Color1}│\n          Compiled successfully!\n"

%.o: %.c includes/pipex.h
	@if [ $(Compiling) = '1' ]; then\
		printf "${Color1}${Color1}               Compiling...               ${Color1}\n${Color1}│";\
	fi
	$(eval Compiling=$(shell echo $$(($(Compiling)+1))))
	@printf "${Color1}▓▓▓"
	@$(CC) $(Flag) -c $< -o $@


norm:
	norminette -R CheckForbiddenSourceHeader *

clean:
	@rm -f $(OBJS_main) $(OBJS_src) $(OBJS_printf)
	@printf "${Color2}Removing object files...\n"

fclean: clean
	@rm -f $(NAME)
	@printf "${Color2}Removing executable...\n"

re: fclean all