#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/02 16:10:46 by rmalkevy          #+#    #+#              #
#    Updated: 2017/02/06 19:26:23 by rmalkevy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRC = 	ft_atoi.c \
        ft_putnbr.c \
        ft_putchar.c \
        ft_putstr.c \
        ft_strdup.c \
        ft_strlen.c \
        ft_strsub.c \
        ft_strdel.c \
        ft_strnew.c \
        ft_tolower.c \
        ft_print_num_10.c \
        ft_print_num_16.c \
        ft_print_num_8.c \
        ft_char.c \
        ft_itoa_base_unsigned.c \
        ft_printf.c \
        filter.c \
        ft_width_precision_sharp.c \
        general_functions.c \
        string.c \
        bonus_functions.c \
        wchar.c \
        detect_flags.c \
        ft_wstring.c \
        ft_putwstr.c \
        ft_wstrlen.c \
        ft_wstrsub.c

OBJ = $(SRC:.c=.o)

HEADER = ft_printf.h

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -o $@ $<

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all