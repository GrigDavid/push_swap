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
CFLAGS = -Wall -Wextra -Werror
DEPS = ft_printf.h push_swap.h
NAME = push_swap
LSTS = ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstclear.c ft_lstiter.c
LSTO = $(LSTS:%.c=%.o)
SRCS = babshka.c ft_printf.c sort_three.c ft_putnbr.c extras.c extras_two.c ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstclear.c ft_lstiter.c\
push_swap.c parser.c operations.c ft_strncmp.c
OBJS = $(SRCS:.c=.o)
LINK = $(CC) -o

all: $(NAME)

$(NAME) : $(OBJS)
	$(LINK) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

# lst: $(LSTO)
# 	echo eghav

# ft_lst%.o: ft_lst%.c
# 	$(CC) $(CFLAGS) -c ./lsts/$< -o ./objs/$@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f  $(NAME)

re: fclean all

.PHONY: all clean fclean re
