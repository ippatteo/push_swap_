NAME := push_swap

CC := gcc

CFLAGS := -Wall -Wextra -Werror -g

SOURCE := push_robe/*.c
LIBFT := libft
PRINTF := printf/*.c

all:
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(SOURCE) $(PRINTF) $(LIBFT)/libft.a -L/$(LIBFT) -o $(NAME)

clean: fclean

fclean: clean
		make clean -C $(LIBFT)
		rm -rf $(NAME)

re: fclean all