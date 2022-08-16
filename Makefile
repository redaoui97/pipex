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
Main_functions = pipex

OBJS_main = $(Main_functions:=.o)
NAME = pipex

Color1 = \e[92;5;118m
Color2 = \033[0;33m

.Phony: all clean fclean re bonus

all : $(NAME)

$(NAME): $(OBJS_main)
	@$(CC) $(Flags) $(OBJS_main) -o $(NAME)
	@printf "${Color1}Compiled successfully!"

%.o: %.c includes/pipex.h
	@$(CC) $(FLAGS) -c $< -o $@

norm:
	norminette -R CheckForbiddenSourceHeader *

clean:
	@rm -f $(OBJS_main)
	@printf "${Color2}Removing object files...\n"

fclean: clean
	@rm -f $(NAME)
	@printf "${Color2}Removing executable...\n"

re: fclean all