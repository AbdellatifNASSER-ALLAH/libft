
CC = @cc
CFLAGS = -g

SANITIZE = -fsanitize=address

SRCS = ./
LIB_DIR = ../libft/
LIB_NAME = ft
NAME = libft.a
LIB = -L$(LIB_DIR) -l$(LIB_NAME)
MAKE= @make

SRCS_FILES = $(wildcard $(SRCS)/main_*.c) 
BINS = $(SRCS_FILES:.c=.out)

all: $(BINS)

%.out : %.c
	@echo "Building all tests..."
	$(MAKE) -C $(LIB_DIR)
	@$(MAKE) -C $(LIB_DIR) clean
	$(CC) $(CFLAGS) $< $(LIB) -o $@ ;
	./$@;
	@rm $@


f%: $(SRCS)/main_%.c 
	@echo "Building with fsanitize..."
	$(MAKE) -C $(LIB_DIR)
	@$(MAKE) -C $(LIB_DIR) clean
	$(CC) $(CFLAGS) $(SANITIZE) $< $(LIB) -o  
%: $(SRCS)/main_%.c 
	@echo "Building..."
	$(MAKE) -C $(LIB_DIR)
	@$(MAKE) -C $(LIB_DIR) clean
	$(CC) $(CFLAGS) $< $(LIB)

run:
	@./a.out

clean:
	@-rm -rf a.out*

.PHONY: all run clean fclean
