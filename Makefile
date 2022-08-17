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
Main_functions   = pipex
Src_functions    = src/src 
Printf_functions = ft_printf/ft_printf ft_printf/ft_strlen \
		   ft_printf/print_addresse ft_printf/print_char \
		   ft_printf/print_hex_lower ft_printf/print_hex_upper \
		   ft_printf/print_nbr ft_printf/print_nbr_unsigned \
		   ft_printf/print_str

OBJS_main   = $(Main_functions:=.o)
OBJS_src    = $(Src_functions:=.o)
OBJS_printf = $(Printf_functions:=.o)
NAME = pipex

Color1 = \e[92;5;118m
Color2 = \033[0;33m

.Phony: all clean fclean re bonus

all : $(NAME)

$(NAME): $(OBJS_main) $(OBJS_printf) $(OBJS_src)
	@$(CC) $(Flags) $(OBJS_printf) $(OBJS_main) $(OBJS_src) -o $(NAME)
	@printf "${Color1}Compiled successfully!\n"

%.o: %.c includes/pipex.h
	@$(CC) $(FLAGS) -c $< -o $@

norm:
	norminette -R CheckForbiddenSourceHeader *

clean:
	@rm -f $(OBJS_main) $(OBJS_src) $(OBJS_printf)
	@printf "${Color2}Removing object files...\n"

fclean: clean
	@rm -f $(NAME)
	@printf "${Color2}Removing executable...\n"

re: fclean all