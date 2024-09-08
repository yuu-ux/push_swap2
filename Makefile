PUSH_SWAP = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

PRINTF = printf
LIBFT = $(PRINTF)/libft

PUSH_SOURCE = src/push_swap.c src/generate_stack.c src/operation.c src/sort_small.c src/utils.c src/sort_main.c src/position.c src/operation2.c

all: $(PUSH_SWAP)

$(PUSH_SWAP): $(PUSH_SOURCE)
	make -C $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $^ -L$(PRINTF) -lftprintf
clean:
	make -C $(PRINTF) clean
	rm -f *.o

fclean: clean
	make -C $(PRINTF) fclean
	rm -f $(PUSH_SWAP)

re: fclean all

.PHONY: all clean fclean re

# -fsanitize=address
