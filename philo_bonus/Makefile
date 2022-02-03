# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 19:16:35 by rtracee           #+#    #+#              #
#    Updated: 2022/01/18 12:23:34 by rtracee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_B	=	philo_bonus

SRCS_B 	=	clear_bonus.c descendant_bonus.c error_bonus.c info_bonus.c\
			inicialization_bonus.c liba_bonus.c outp_bonus.c philosophers_bonus.c

OBJS_B	=	${SRCS_B:.c=.o}

CC 		=	gcc
CFLAGS 	=	-Wall -Wextra -Werror

%.o:%.c
					@$(CC) ${CFLAGS} -c $< -o $(<:.c=.o)

all:	${NAME_B}

${NAME_B}:	${OBJS_B}
					@$(CC) ${OBJS_B} -o ${NAME_B} -lpthread
					@printf "\nSUCCES\n\n"

clean:
					@rm -f ${OBJS_B}

fclean: 	clean
					@rm -f ${NAME_B}

re:			fclean all

.PHONY: all clean fclean re