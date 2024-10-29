NAME = SoLong

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
INCLUDE_DIR = include
LIBFT_DIR = libft
MLX_DIR = mlx

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

HEADER = $(INCLUDE_DIR)/so_long.h)

all: $(LIBFT_DIR)/libft.a $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -L$(LIBFT_DIR) -lft -o $(NAME)
	cp $(MLX_DIR)/libmlx.dylib ./

$(LIBFT_DIR)/libft.a:
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) libmlx.dylib
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
