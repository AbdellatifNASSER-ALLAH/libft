
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

f%: $(SRCS)/main_%.c $(LIB)
	@echo "Building with fsanitize..."
	$(CC) $(CFLAGS) $(SANITIZE) $^

%: $(SRCS)/main_%.c $(LIB)
	@echo "Building..."
	$(CC) $(CFLAGS) $^

$(LIB):
	@if [ ! -f $(LIB_DIR)/$(NAME) ]; then \
		$(MAKE) -C $(LIB_DIR) ;\
		$(MAKE) -C $(LIB_DIR) clean ;\
	fi

run:
	./a.out

clean:
	-rm a.out

fclean: clean
	rm $(LIB_DIR)/$(NAME)

.PHONY: all run clean fclean
