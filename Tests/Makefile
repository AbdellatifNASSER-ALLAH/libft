
CC = cc
CFLAGS = -Wall -Wextra -Werror
SANITIZE = -fsanitize=address

SRCS = ./
LIB_DIR = ../Project/
LIB_NAME = ft
NAME = libft.a
LIB = -L$(LIB_DIR) -l$(LIB_NAME)

all:
	@echo "You have to paste the of the function you wanna compile!"

f%: $(SRCS)/main_%.c 
	@echo "Building with fsanitize..."
	$(MAKE) -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(SANITIZE) $< $(LIB)

%: $(SRCS)/main_%.c 
	@echo "Building..."
	$(MAKE) -C $(LIB_DIR)
	$(CC) $(CFLAGS) $< $(LIB)

run:
	./a.out

clean:
	-rm a.out

.PHONY: all run clean fclean
