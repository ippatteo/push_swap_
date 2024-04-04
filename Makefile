NAME := push_swap

CC := gcc

CFLAGS := -Wall -Wextra -Werror -g

SOURCE := push_robe/*.c
BONUS := bonus/*.c
LIBFT := libft
PRINTF := printf/*.c

all:
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(SOURCE) $(PRINTF) $(LIBFT)/libft.a -L/$(LIBFT) -o $(NAME)

	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS) $(PRINTF) $(LIBFT)/libft.a -L/$(LIBFT) -o checker

clean: fclean

fclean: clean
		make clean -C $(LIBFT)
		rm -rf $(NAME)
		rm -rf checker

re: fclean all