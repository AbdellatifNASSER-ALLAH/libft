# **************************************************************************** #
#
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

vpath %.c ./srcs
vpath %.c ./srcs/GetNextLine
vpath %.c ./srcs/ft_printf

INCLUDES=./includes
OBJDIR=./objdir/

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES)

FT_PRINTF= ft_printf.c  ft_putchar.c  ft_puthex.c  ft_putnbr.c  ft_putptr.c  ft_putstr.c  ft_putunbr.c  ft_utils.c

GETNEXTLINE= get_next_line.c get_next_line_utils.c

LIBFT= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
    ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
    ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
    ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c\

LINKED_LIST= ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c \
       ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

SRC=$(LIBFT) $(FT_PRINTF) $(GETNEXTLINE)
SRCB=$(LINKED_LIST)

OBJ=$(addprefix $(OBJDIR), $(SRC:.c=.o))
OBJB=$(addprefix $(OBJDIR), $(SRCB:.c=.o))

NAME=libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $(NAME) $?

bonus : $(OBJB)
	ar -crs $(NAME) $? 

$(OBJDIR)%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ $< -c 

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ) $(OBJB) $(OBJDIR)

