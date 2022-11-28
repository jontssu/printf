# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jole <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:47:08 by jole              #+#    #+#              #
#    Updated: 2022/11/24 14:04:59 by jole             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft.a

SRC = ft_printf.c

OSRC = $(SRC:%.c=%.o)

WWW = -Wall -Wextra -Werror

.PHONY: all clean fclean re bonus

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C ./libft

$(NAME): $(OSRC)
	cp ./libft/$(LIBFT) ./$(NAME)
	ar -rus $(NAME) $(OSRC)

clean: 
	rm -f $(OSRC)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

%.o: %.c
	cc $(WWW) -c -o $@ $^

re: fclean all

test:
	cc -g main.c libftprintf.a -I ft_printf.h

