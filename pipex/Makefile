NAME = pipex
CC = cc

FLAG = -Wall -Werror -Wextra -g3

FILE = utils.c pipex.c
OBJ = $(FILE:.c=.o)

PRINTF_DIR = ../../cercle_1/printf
PRINTF_LIB = ../../cercle_1/printf/libftprintf.a

LIBFT_DIR = ../../cercle_1/libft
LIBFT_LIB = ../../cercle_1/libft/libft.a

all:$(NAME)

$(NAME):$(OBJ) $(LIBFT_LIB) $(PRINTF_LIB)
	$(CC) $(FLAG) -o $(NAME) $(OBJ) $(LIBFT_LIB) $(PRINTF_LIB)
%.o:%.c
	$(CC) $(FLAG) -c $< -o $@
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)
$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)
clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
fclean:clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
re:fclean all

.PHONY: all clean fclean re