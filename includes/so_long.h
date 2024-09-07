/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:04:12 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/07 20:53:37 by jlorette         ###   ########.fr       */
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
}				t_mlx;

typedef struct s_map
{
	int		cols;
	int		rows;
	int		collectible;
	char	**map;
}				t_map;

typedef struct s_game {
	t_mlx  *mlx;
	t_map  *map;
}				t_game;

char	**allocate_map(int rows, int cols);
int		check_map(t_map *map);
int		check_rectangular_shape(t_map *map_struct);
int		check_required_elements(t_map *map_struct, int *exit,
			int *player, int *collectable);
int		check_valid_chars(t_map *map_struct);
int		check_walls(t_map *map);
t_map	*create_map_structure(const char *filename);
void	free_map(t_map *map_struct);
void	game(t_mlx *mlx, t_map *map);
void	generate_map(t_map *map, t_mlx *mlx);
int		keypress_d(t_map *map);

#endif