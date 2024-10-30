# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 15:07:33 by abdnasse          #+#    #+#              #
#    Updated: 2024/10/30 17:22:53 by abdnasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -Wall -Wextra -Werror

SRC=$(wildcard ft_*.c)
OBJ=$(SRC:.c=.o)
NAME=libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)
	ranlib $(NAME)	
$(OBJ)  : $(SRC)
	$(CC) $(SRC) -c -I./ 

clean:
	-rm $(OBJ)

fclean: clean
	rm $(NAME)

re:	fclean all

.PHONY:
