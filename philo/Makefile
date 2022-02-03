# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 10:48:08 by rtracee           #+#    #+#              #
#    Updated: 2022/01/18 12:24:25 by rtracee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRCS	=	info.c init_threads.c initialization.c liba.c \
			output.c philosophers.c process.c threads.c clear.c

OBJS	=	${SRCS:.c=.o}

CC		=	gcc
CFLAGS 	=	-Wall -Wextra -Werror

%.o:%.c
					@$(CC) ${CFLAGS} -c $< -o $(<:.c=.o)

all:	${NAME}

${NAME}:	${OBJS}
					@$(CC) ${OBJS} -o ${NAME} -lpthread
					@printf "\nSUCCES\n\n"

clean:
					@rm -f ${OBJS}

fclean: 	clean
					@rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re