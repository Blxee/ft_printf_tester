CC = cc
LIB_DIR = ./ft_printf
LIB = $(LIB_DIR)/libftprintf.a
CFLAGS = -g
LDFLAGS = -L$(LIB_DIR) -lftprintf
NAME = test.out
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)

test: $(NAME)
	./$(NAME)

all: test

$(NAME): $(OBJS) $(LIB)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(LIB):
	$(MAKE) -C $(LIB_DIR)

clean:
	$(MAKE) -C $(LIB_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	rm -f $(NAME)

.PHONY: all test clean fclean
