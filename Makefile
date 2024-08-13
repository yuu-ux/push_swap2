PUSH_SWAP = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

PRINTF = printf
LIBFT = $(PRINTF)/libft

PUSH_SOURCE = push_swap.c generate_stack.c operation.c

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
