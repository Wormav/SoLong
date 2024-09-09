/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:57:47 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/08 19:16:14 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/so_long.h"

void	draw_tile(t_mlx *mlx, int x, int y, char *tile)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx_xpm_file_to_image(mlx->mlx, tile, &mlx->width, &mlx->height),
		x * SIZE_IMG, y * SIZE_IMG);
}

static int	can_move(t_map *map, t_pos pos, t_pos offset)
{
	int	new_i;
	int	new_j;

	new_i = pos.y + offset.y;
	new_j = pos.x + offset.x;
	return (new_i >= 0 && new_i < map->rows && new_j >= 0 && new_j < map->cols
		&& map->map[new_i][new_j] != '1');
}

static void	update_position(t_map *map, t_mlx *mlx, t_pos pos, t_pos offset)
{
	map->map[pos.y][pos.x] = '0';
	draw_tile(mlx, pos.x, pos.y, "xpm/floor.xpm");
	map->map[pos.y + offset.y][pos.x + offset.x] = 'P';
	draw_tile(mlx, pos.x + offset.x, pos.y + offset.y, "xpm/drago.xpm");
}

static t_pos	find_player_position(t_map *map)
{
	t_pos	pos;
	int		i;
	int		j;
	int		found;

	i = 0;
	found = 0;
	while (i < map->rows && !found)
	{
		j = 0;
		while (j < map->cols && !found)
		{
			if (map->map[i][j] == 'P')
			{
				pos.x = j;
				pos.y = i;
				found = 1;
			}
			j++;
		}
		i++;
	}
	return (pos);
}

void	move_player(t_map *map, t_mlx *mlx, int x_offset, int y_offset)
{
	t_pos	pos;
	t_pos	offset;

	offset.y = y_offset;
	offset.x = x_offset;
	pos = find_player_position(map);
	if (can_move(map, pos, offset))
	{
		update_position(map, mlx, pos, offset);
	}
}
