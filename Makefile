# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 15:28:27 by dgrigor2          #+#    #+#              #
#    Updated: 2025/02/07 17:20:20 by dgrigor2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC  = cc
CFLAGS = -Wall -Wextra -Werror
DEPS = ft_printf.h push_swap.h
NAME = push_swap.out
SRCS = algo.c ft_printf.c ft_putnbr.c extras.c extras_two.c push_swap.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstclear.c ft_lstiter.c ft_lstmap.c parser.c operations.c
OBJS = $(SRCS:.c=.o)
LIBA = $(CC) -o

all: $(NAME)

$(NAME) : $(OBJS)
	$(LIBA) $(NAME) $(OBJS)


%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o 

fclean: clean
	rm -f  $(NAME)

re: fclean all

.PHONY: all clean fclean re
