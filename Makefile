# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jordgarc <jordgarc@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 18:44:14 by jordgarc          #+#    #+#              #
#    Updated: 2024/02/13 17:53:24 by jordgarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_putchar.c ft_putnbr.c ft_num_nosign.c ft_punt_hexa.c \
				ft_strlen.c ft_putstr.c ft_hexa_min.c ft_hexa_mayus.c

INCLUDE = ft_printf.h

CC = gcc
RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror

%.o: %.c ${INCLUDE}
			@echo "Compiling $<"
			@${CC} ${CFLAGS} -c $< -o $@

OBJS = ${SRCS:.c=.o}

all:	${NAME}

${NAME}: ${OBJS}
		@${AR} ${NAME} ${OBJS}
		@echo "\nCreated $(NAME)\n"

clean:
		@${RM} ${OBJS}
		@echo "\nAll objects cleaned successfully\n"

fclean:
		@${RM} ${OBJS}
		@${RM} ${NAME}
		@echo "\nAll objects and executable cleaned successfully\n"

re: fclean all

.PHONY: all clean fclean re
