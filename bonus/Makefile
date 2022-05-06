# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 18:25:57 by kmeixner          #+#    #+#              #
#    Updated: 2022/05/06 16:24:07 by kmeixner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo_bonus

SRCS		=	philo_bonus.c input.c ft_atoi.c exits.c time.c philroutine.c \
				utils.c parent.c clean.c init.c checks.c

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra -pthread -O3 #-g -fsanitize=address

all:		$(NAME)

$(NAME):	$(SRCS)
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
			$(RM) $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re