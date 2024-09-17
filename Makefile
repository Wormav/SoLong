NAME = SoLong

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
INCLUDE_DIR = include
LIBFT_DIR = libft
MLX_DIR = mlx

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)

HEADER = $(wildcard $(INCLUDE_DIR)/*.h)

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