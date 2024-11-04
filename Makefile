NAME = SoLong

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
INCLUDE_DIR = include
LIBFT_DIR = libft
MLX_DIR = mlx_linux

SRC = $(SRC_DIR)/check_collectibles.c \
	$(SRC_DIR)/check_map.c \
	$(SRC_DIR)/find_position.c \
	$(SRC_DIR)/frame.c \
	$(SRC_DIR)/game.c \
	$(SRC_DIR)/generate_map.c \
	$(SRC_DIR)/keypress.c \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/memories_map.c \
	$(SRC_DIR)/parsing_map.c \
	$(SRC_DIR)/validate_functions_map.c \

OBJ = $(SRC:.c=.o)

HEADER = $(INCLUDE_DIR)/so_long.h

all: $(MLX_DIR)/libmlx_Linux.a $(LIBFT_DIR)/libft.a $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_DIR)/libmlx_Linux.a -L$(LIBFT_DIR) -lft -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT_DIR)/libft.a:
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX_DIR)/libmlx_Linux.a:
	@$(MAKE) -C $(MLX_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
