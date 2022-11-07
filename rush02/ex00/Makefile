# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/20 00:53:31 by hferraud          #+#    #+#              #
#    Updated: 2022/08/21 23:39:12 by dbiguene         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS	= ${wildcard ./srcs/*.c} ${wildcard ./srcs/functions/*.c}

OBJS	= ${SRCS:.c=.o}

NAME	= rush-02

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

all:	${OBJS}
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

.PHONY: all clean fclean
