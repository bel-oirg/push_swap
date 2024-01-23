# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 17:36:40 by bel-oirg          #+#    #+#              #
#    Updated: 2024/01/22 04:35:50 by bel-oirg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_B = checker

SRCS = command_utils.c controller.c error_syntax.c \
ft_atol.c init_stack.c push_command.c push_swap_init.c \
r_rotate_command.c rotate_command.c swap_command.c tiny_sort.c \
ft_split.c ft_strlen.c ft_strjoin.c ft_strdup.c median_algo.c \
my_malloc.c

SRCS_B = ft_strcmp.c get_next_line.c get_next_line_utils.c

CC = cc
CFLAGS = -Wall -Wextra -Werror #-g# -fsanitize=address

RM = rm -f

all: $(NAME)

$(NAME) : $(SRCS) main.c push_swap.h
	$(CC) $(CFLAGS) $(SRCS) main.c -o push_swap

bonus: $(NAME_B)

$(NAME_B) : $(SRCS_B) $(SRCS) checker_bonus.c checker_bonus.h
	$(CC) $(CFLAGS) $(SRCS_B) $(SRCS) checker_bonus.c -o checker

clean: 
	@echo "nothing to clean"

fclean:
	$(RM) push_swap checker

re: fclean all

.PHONY: all clean fclean re
