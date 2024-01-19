# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 17:36:40 by bel-oirg          #+#    #+#              #
#    Updated: 2024/01/19 17:57:28 by bel-oirg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

SRCS = command_utils.c controller.c error_syntax.c \
ft_atol.c init_stack.c push_command.c push_swap_init.c \
r_rotate_command.c rotate_command.c swap_command.c tiny_sort.c \
ft_split.c ft_strlen.c ft_strjoin.c ft_strdup.c median_algo.c \
my_malloc.c

OBJS = $(SRCS:.c=.o)

CC = cc

CCF = -Wall -Wextra -Werror #-g -fsanitize=address

AR = ar rc

RM = rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(CC) $(CCF) main.c $(NAME) -o push_swap

%.o : %.c push_swap.h
	$(CC) -c $(CCF) $<

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) push_swap

re: fclean all

.PHONY: all clean fclean re
