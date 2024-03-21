# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 00:21:24 by ansulist          #+#    #+#              #
#    Updated: 2023/04/09 17:26:22 by ansulist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =  algorithm.c \
		checks.c \
		helper_alg.c \
		helper_alg2.c \
		list_functions.c \
		push.c \
		reverse.c \
		rotate.c \
		simple_sort.c \
		sort_tab.c \
		swap.c \
		utils.c \
		main.c \

OBJS = ${SRCS:.c=.o}
CHECK_OBJS = ${CHECK_SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: ${NAME}
${NAME}: ${OBJS}
	@${MAKE} -C libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

clean: 
	@${MAKE} -C libft clean
	@${RM} ${OBJS}

fclean: clean
	@${MAKE} -C libft fclean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re