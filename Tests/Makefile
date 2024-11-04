
CC = cc
CFLAGS = -Wall -Wextra -Werror
SANITIZE = -fsanitize=address

SRCS = ./
LIB_DIR = ../Project
LIB_NAME = ft
NAME = libft.a
LIB = -L$(LIB_DIR) -l$(LIB_NAME)

all:
	@echo "You have to paste the of the function you wanna compile!"

-%: $(LIB) $(SRCS)/main_%.c
	@echo "Building with fsanitize..."
	$(CC) $(CFLAGS) $(SANITIZE) $< $(LIB)

%: $(LIB) $(SRCS)/main_%.c
	@echo "Building..."
	$(CC) $(CFLAGS) $< $(LIB)

$(LIB):
	@if [! -f $(LIB_DIR)/$(NAME)]; then;\
		$(MAKE) -C $(LIB_DIR) clean;\
		$(MAKE) -C $(LIB_DIR);\
	fi	

run:
	./a.out

clean:
	-rm a.out

.PHONY: all run clean
