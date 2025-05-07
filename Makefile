# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/05 17:15:58 by dgrigor2          #+#    #+#              #
#    Updated: 2025/05/07 16:34:39 by dgrigor2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC  = cc
CFLAGS = -Wall -Wextra -Werror -I libft -g3
NAME = push_swap
DEPS = push_swap.h
SRCS = push_swap.c ft_stk/ft_stkadd_back.c ft_stk/ft_stkclear.c \
ft_stk/ft_stklast.c ft_stk/ft_stknew.c ft_stk/ft_stksize.c src/algorithm.c \
src/sort_three.c src/parser.c src/operations.c src/normalise.c src/refill_a.c \
src/alt_atoi.c src/free_mat.c
OBJS = $(SRCS:.c=.o)
BONUS_SRCS = checker.c ft_stk/ft_stkadd_back.c ft_stk/ft_stkclear.c \
ft_stk/ft_stklast.c ft_stk/ft_stknew.c ft_stk/ft_stksize.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
LIBDIR = ./libft
LIBMAKE = $(LIBDIR)/libft.a

all: $(NAME) 

$(NAME) : $(OBJS) $(LIBMAKE)
	$(CC) $(CFLAGS) $(OBJS) $(LIBMAKE) -o $(NAME)

bonus: $(BONUS_OBJS) $(LIBMAKE)
	$(CC) $(CFLAGS) $(OBJS) $(LIBMAKE) -o $(BONUS_NAME)

$(LIBMAKE):
	make -C $(LIBDIR)

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBDIR)
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	make fclean -C $(LIBDIR)
	rm -f  $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
