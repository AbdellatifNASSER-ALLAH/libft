# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 15:07:33 by abdnasse          #+#    #+#              #
#    Updated: 2024/10/31 16:36:22 by abdnasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror

SRC=$(wildcard ft_*.c)
OBJ=$(SRC:.c=.o)
NAME=libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -cr $(NAME) $(OBJ)
	ranlib $(NAME)	

$(OBJ)  : $(SRC)
	$(CC) $(FLAGS) $(SRC) -c -I./ 

clean:
	-rm $(OBJ)

fclean: clean
	rm $(NAME)

re:	fclean all

.PHONY:
