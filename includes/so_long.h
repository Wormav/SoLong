/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:04:12 by jlorette          #+#    #+#             */
/*   Updated: 2024/11/04 14:15:15 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 4096
# define SIZE_IMG 50

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		width;
	int		height;
	int		moves;
}				t_mlx;

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_map
{
	int		cols;
	int		rows;
	t_pos	end_pos;
	int		collectible;
	char	**data;
}				t_map;

typedef struct s_game
{
	t_mlx	*mlx;
	t_map	*map;
}				t_game;

char	**allocate_map(int rows, int cols);
int		check_collectibles(t_map *map);
int		check_map(t_map *map);
int		check_rectangular_shape(t_map *map);
int		check_required_elements(t_map *map, int *exit,
			int *player, int *collectable);
int		check_valid_chars(t_map *map);
int		check_walls(t_map *map);
int		close_game(t_game *game);
void	count_collectible(t_map *map);
t_map	*create_map_structure(const char *filename, t_map *map);
t_pos	find_end_position(t_map *map);
t_pos	find_player_position(t_map *map);
int		find_start_position(t_map *map, int *start_x, int *start_y);
void	free_map(t_map *map);
void	game(t_mlx *mlx, t_map *map);
void	generate_map(t_map *map, t_mlx *mlx);
void	keypress_a(t_game *game);
void	keypress_d(t_game *game);
void	keypress_s(t_game *game);
void	keypress_w(t_game *game);
void	move_player(t_game *game, int x_offset, int y_offset);

#endif
