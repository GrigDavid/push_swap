# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 15:28:27 by dgrigor2          #+#    #+#              #
#    Updated: 2025/04/17 18:53:10 by dgrigor2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC  = cc
CFLAGS = -Wall -Wextra -Werror -I libft
NAME = push_swap
DEPS = push_swap.h
SRCS = babshka.c sort_three.c ft_stkadd_back.c ft_stkclear.c ft_stkiter.c \
ft_stklast.c ft_stknew.c ft_stksize.c push_swap.c parser.c operations.c validation.c
OBJS = $(SRCS:.c=.o)
LIBDIR = ./libft
LIBMAKE = $(LIBDIR)/libft.a

all: $(NAME) 

$(NAME) : $(OBJS) $(LIBMAKE)
	$(CC) $(CFLAGS) $(OBJS) $(LIBMAKE) -o $(NAME)

$(LIBMAKE):
	make -C $(LIBDIR)

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBDIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBDIR)
	rm -f  $(NAME)

re: fclean all

.PHONY: all clean fclean re
