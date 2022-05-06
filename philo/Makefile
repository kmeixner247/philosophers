# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 18:25:57 by kmeixner          #+#    #+#              #
#    Updated: 2022/05/06 16:06:30 by kmeixner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

SRCS		=	checks.c clean.c exits.c ft_atoi.c init.c input.c philo.c \
				philroutine.c time.c utils.c

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra -pthread -O3 #-g -fsanitize=thread

all:		$(NAME)

$(NAME):	$(SRCS)
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
			$(RM) $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re