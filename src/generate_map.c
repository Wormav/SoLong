/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:18:16 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/07 20:10:43 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "../includes/so_long.h"

static char	*name_img(char c)
{
	if (c == '1')
		return ("xpm/wall.xpm");
	else if (c == 'E')
		return ("xpm/floor.xpm");
	else if (c == 'C')
		return ("xpm/snake.xpm");
	else if (c == 'P')
		return ("xpm/drago.xpm");
	else
		return ("xpm/floor.xpm");
}

static void	count_collectible(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	map->collectible = count;
}

void	generate_map(t_map *map, t_mlx *mlx)
{
	int		i;
	int		j;

	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, map->cols * SIZE_IMG,
			map->rows * SIZE_IMG, "So_long");
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			mlx->img = mlx_xpm_file_to_image(mlx->mlx,
					name_img(map->map[i][j]), &mlx->width, &mlx->height);
			mlx_put_image_to_window(mlx, mlx->win, mlx->img,
				SIZE_IMG * j, SIZE_IMG * i);
			j++;
		}
		i++;
	}
	count_collectible(map);
}
