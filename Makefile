# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnabil <rnabil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 15:14:45 by rnabil            #+#    #+#              #
#    Updated: 2022/09/02 18:54:42 by rnabil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

#Bonus

functions_bonus    = bonus/src/src_bonus bonus/src/split_bonus \
				bonus/src/src2_bonus bonus/src/parsing_utils_bonus \
				bonus/src/parsing_bonus bonus/pipex_bonus \
				bonus/src/get_next_line bonus/src/src3_bonus

OBJS_functions_bonus    = $(functions_bonus:=.o)

NAME = pipex
NAME2 = pipex_bonus
Compiling = 1
Color1    = \e[92;5;118m
Color2    = \033[0;33m
CC        = gcc
Flags     = -g -Wall -Wextra -Werror
# INC = -I includes
# BINC = -I bonus/includes

.Phony: all clean fclean re bonus

all   : $(NAME)
bonus : $(NAME2)

%.o: %.c includes/pipex.h bonus/includes/pipex_bonus.h
	@if [ $(Compiling) = '1' ]; then\
		printf "${Color1}${Color1}               Compiling...               ${Color1}\n${Color1}│";\
	fi
	$(eval Compiling=$(shell echo $$(($(Compiling)+1))))
	@printf "${Color1}▓▓▓"
	@$(CC) $(Flags) -c $< -o $@

$(NAME): $(OBJS_main) $(OBJS_printf) $(OBJS_src)
	@$(CC) $(Flags) $(OBJS_printf) $(OBJS_main) $(OBJS_src) -o $(NAME)
	@printf "${Color1}│\n          Compiled successfully!\n"

$(NAME2): $(OBJS_functions_bonus) $(OBJS_printf)
	@$(CC) $(Flags) $(OBJS_functions_bonus) $(OBJS_printf) -o $(NAME2)
	@printf "${Color1}│\n          Compiled successfully!\n"
	
norm:
	norminette -R CheckForbiddenSourceHeader *

clean:
	@rm -f $(OBJS_main) $(OBJS_src) $(OBJS_printf) $(OBJS_functions_bonus)
	@printf "${Colors2}Removing object files...\n"

fclean: clean
	@rm -f $(NAME) $(NAME2)
	@printf "${Color2}Removing executable...\n"


re: fclean all