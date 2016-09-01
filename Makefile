# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmather <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/05 14:51:29 by dmather           #+#    #+#              #
#    Updated: 2016/08/27 16:45:44 by dmather          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 42sh
NC			= \033[0m
CR			= \033[31m
CB			= \033[34m
CP			= \033[38;5;128m
CY			= \033[33m
FLAGS		= -Wall -Wextra -Werror -ltermcap -g3
LIBFT		= -L libft -lft
INCLUDES	= -I include -I libft

SRCS		=	src/ft_sh.c		\
				src/execs.c		\
				src/ft_getenv.c	\
				src/builtins.c	\
				src/small.c		\
				src/terms.c		\

all: $(NAME)

$(NAME):
	@make -s -C libft all
	@gcc $(FLAGS) $(INCLUDES) $(SRCS) $(LIBFT) -o $(NAME)
#	@echo "$(CR)Terminal Broken!$(NC)"
#	@sleep 2
#	@echo "Just Kidding ;)"
#	@sleep 1
	@echo "$(CB)$(NAME) ==> Made '$(NAME)'$(NC)"

clean:
	@make -s -C libft clean
	@echo "$(CY)$(NAME) ==> Removed all .o files in library$(NC)"

aclean: clean
	@make -s -C libft fclean
	@rm -f $(NAME)
	@echo "$(CR)$(NAME) ==> Removed '$(NAME)'$(NC)"
#	@echo "$(CP)-*-*-*-*-* Time Remaining: 438 sec. *-*-*-*-*-"
#	@sleep 2
#	@echo "-*-*-*-*-* Time Remaining: 437 sec. *-*-*-*-*-"
#	@sleep 2
#	@echo "-*-*-*-*-* Time Remaining: 436 sec. *-*-*-*-*-"
#	@sleep 2
#	@echo "-*-*-*-*-* Time Remaining: 435 sec. *-*-*-*-*-"
#	@sleep 2
#	@echo "-*-*-*-*-* Time Remaining: 434 sec. *-*-*-*-*-"
#	@sleep 2
#	@echo "-*-*-*-*-* Time Remaining: 433 sec. *-*-*-*-*-"

fclean: clean
	@make -s -C libft fclean
	@rm -f $(NAME)
	@echo "$(CR)$(NAME) ==> Removed '$(NAME)'$(NC)"

re: aclean all

del:
	@rm -f $(NAME)
	@echo "$(CR)$(NAME) ==> Removed '$(NAME)'$(NC)"

run: del all
