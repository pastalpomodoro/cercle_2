NAME = push_swap

CC = cc
FLAG = -Wall -Werror -Wextra -g3

FILE = nm_pile_a.c nm_pile_b.c algo_utils.c testeur.c moove/r_rotate.c moove/rotate.c moove/place_to.c moove/swap_a_b.c utils_lst.c parsing.c push_swap.c

OBJ_PATH = Bin/
OBJ = $(addprefix $(OBJ_PATH), $(FILE:.c=.o))

LIBFT_DIR=../../cercle_1/libft
LIBFT_LIB=../../cercle_1/libft/libft.a

PRINTF_DIR=../../cercle_1/printf
PRINTF_LIB=../../cercle_1/printf/libftprintf.a

all:$(NAME)

$(NAME):$(OBJ) $(LIBFT_LIB) $(PRINTF_LIB)
	$(CC) $(FLAG) -o $(NAME) $(OBJ) $(LIBFT_LIB) $(PRINTF_LIB)

$(OBJ_PATH)%.o:%.c
	mkdir -p $(dir $@)
	$(CC) $(FLAG) -c $< -o $@

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)
$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	rm -rf $(OBJ_PATH)
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re