# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pyasuko <pyasuko@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/26 13:45:49 by pyasuko           #+#    #+#              #
#    Updated: 2021/08/05 14:33:49 by pyasuko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		pipex

SRC =		pipex.c \
			utils/ft_split.c \
			utils/ft_strjoin.c \
			utils/ft_strlen.c \
			utils/ft_strnstr.c \
			utils/utils.c

OBJ =		${SRC:.c=.o}
CC =		gcc
CFLAGS =	-Wall -Werror -Wextra -g
RM =		rm -rf

all:		${NAME}

${NAME}:	${OBJ}
			@${CC} -g ${OBJ} ${CFLAGS} -o ${NAME}

${OBJ}:		pipex.h

clean:
			@${RM} ${OBJ}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

.PHONY:		clean fclean re all
