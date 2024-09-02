NAME = SoLong

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
INCLUDE_DIR = include
MLX_DIR = mlx

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)

HEADER = $(wildcard $(INCLUDE_DIR)/*.h)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	cp $(MLX_DIR)/libmlx.dylib ./

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) libmlx.dylib

re: fclean all

.PHONY: all clean fclean re