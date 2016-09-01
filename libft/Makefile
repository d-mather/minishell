# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmather <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/28 12:00:41 by dmather           #+#    #+#              #
#    Updated: 2016/08/27 20:44:32 by dmather          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAG = -c -Wall -Werror -Wextra -g

SRC_NAME = ft_atoi.c ft_bzero.c ft_ctostr.c ft_isalnum.c \
			ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c \
			ft_isprint.c ft_isupper.c ft_itoa_base.c ft_itoa.c \
			ft_lstadd.c ft_lstclear.c ft_lstdel.c ft_lstdelone.c \
			ft_lstiter.c ft_lstlen.c ft_lstmap.c ft_lstnclear.c \
			ft_lstnew.c ft_lstpushback.c ft_memalloc.c ft_memccpy.c \
			ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
			ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putchar.c \
			ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putnbr.c \
			ft_putstr_fd.c ft_putstr.c ft_strcat.c ft_strchr.c \
			ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
			ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
			ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c \
			ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
			ft_strnequ.c ft_strnew.c ft_strnjoin.c ft_strnstr.c \
			ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c \
			ft_strsub.c ft_strtrim.c ft_trim_qu.c ft_tolower.c \
			ft_toupper.c ft_uitoa_base.c ft_uitoa.c ft_gnl.c ft_tabstrstr.c\
			ft_printf/ft_printf.c ft_printf/ft_process.c \
			ft_printf/ft_utils.c ft_printf/ft_add_args.c \
			ft_atoi_hex.c ft_float_swap.c ft_memswap.c ft_nstrsplit.c \
			ft_sprintf.c ft_strtoupper.c ft_isint.c ft_tabdup.c \
			ft_nstrjoin.c ft_free_tab.c ft_realloc.c \

OBJS = ft_atoi.o ft_bzero.o ft_ctostr.o ft_isalnum.o \
			ft_isalpha.o ft_isascii.o ft_isdigit.o ft_islower.o \
			ft_isprint.o ft_isupper.o ft_itoa_base.o ft_itoa.o \
			ft_lstadd.o ft_lstclear.o ft_lstdel.o ft_lstdelone.o \
			ft_lstiter.o ft_lstlen.o ft_lstmap.o ft_lstnclear.o \
			ft_lstnew.o ft_lstpushback.o ft_memalloc.o ft_memccpy.o \
			ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memdel.o \
			ft_memmove.o ft_memset.o ft_putchar_fd.o ft_putchar.o \
			ft_putendl_fd.o ft_putendl.o ft_putnbr_fd.o ft_putnbr.o \
			ft_putstr_fd.o ft_putstr.o ft_strcat.o ft_strchr.o \
			ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o \
			ft_strdup.o ft_strequ.o ft_striter.o ft_striteri.o \
			ft_strjoin.o ft_strlcat.o ft_strlen.o ft_strmap.o \
			ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o \
			ft_strnequ.o ft_strnew.o ft_strnjoin.o ft_strnstr.o \
			ft_strrchr.o ft_strrev.o ft_strsplit.o ft_strstr.o \
			ft_strsub.o ft_strtrim.o ft_trim_qu.o ft_tolower.o \
			ft_toupper.o ft_uitoa_base.o ft_uitoa.o ft_gnl.o ft_tabstrstr.o\
			ft_atoi_hex.o ft_float_swap.o ft_memswap.o ft_nstrsplit.o \
			ft_sprintf.o ft_strtoupper.o ft_nstrjoin.o \
			ft_printf.o ft_process.o ft_free_tab.o ft_realloc.o \
			ft_utils.o ft_add_args.o ft_isint.o ft_tabdup.o \

AR = ar rc

RLIB = ranlib

HDR = -I libft.h

RM = rm -rf

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAG) $(SRC_NAME)
	@$(AR) $(NAME) $(OBJS)
	@$(RLIB) $(NAME)
	@mkdir -p objs/
	@mv $(OBJS) objs/

clean:
	@$(RM) objs/

fclean: clean
	@$(RM) $(NAME)

re: fclean all
