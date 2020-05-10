# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/28 20:36:46 by aribesni          #+#    #+#              #
#    Updated: 2020/04/28 20:36:47 by aribesni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_print_c.c ft_print_s.c ft_print_i_u.c ft_print_p.c \
ft_assign.c ft_display.c ft_dot_s.c ft_rest.c ft_ret.c ft_wildcard.c ft_zero.c \
ft_printf_utils.c ft_printf_utils2.c ft_printf_utils3.c \

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS}
	    ar rc ${NAME} ${OBJS}

all : ${NAME}

clean :
	    ${RM} ${OBJS}

fclean : clean
	    ${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
