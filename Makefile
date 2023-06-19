# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yscheef <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 09:44:16 by yscheef           #+#    #+#              #
#    Updated: 2023/06/19 15:20:06 by yscheef          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC = 	ft_main.c	\
		ft_free.c	\
		ft_init.c	\
		ft_operations.c	\
		ft_input_check.c	\
		ft_linked_slists.c	\
		ft_linked_dlists.c	\
		ft_sorting.c	\
		ft_strings.c	\
		ft_lowrange.c

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	
	(cd libft && make)
	cp libft/libft.a libft.a

	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft.a

clean:	
	rm -f *.o
	rm -f libft.a
	(cd libft && make fclean)

fclean:	clean
	rm -f push_swap

re:	fclean all

.PHONY:	all clean fclean re
