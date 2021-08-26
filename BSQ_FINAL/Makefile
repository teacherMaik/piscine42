# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpoiron <mpoiron@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/18 10:37:16 by mpoiron           #+#    #+#              #
#    Updated: 2021/08/25 12:57:43 by mpoiron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = srcs/ft_solve.c srcs/atoi.c srcs/open_file.c srcs/main.c srcs/linked_list.c srcs/read_stdin.c srcs/ft_print.c

OBJS = ${SRCS:.c=.o}

INCL = includes/ft_file.h

INCDIR = includes

CFLAGS = -Wall -Wextra -Werror -c

NAME = bsq

%.o: %.c
	gcc ${CFLAGS} $< -o $@

${NAME}: ${OBJS}
	gcc -Wall -Wextra -Werror ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean all fclean re

