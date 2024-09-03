NAME = SoLong

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
INCLUDE_DIR = include
LIBFT_DIR = libft
MLX_DIR = mlx

SRC = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(LIBFT_DIR)/*.c)
OBJ = $(SRC:.c=.o)

HEADER = $(wildcard $(INCLUDE_DIR)/*.h) $(wildcard $(LIBFT_DIR)/*.h)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	cp $(MLX_DIR)/libmlx.dylib ./
	cp $(LIBFT_DIR)/libft.a ./

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) libmlx.dylib libft.a

re: fclean all

.PHONY: all clean fclean re