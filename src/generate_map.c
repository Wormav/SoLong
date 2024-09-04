/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:18:16 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/04 15:43:30 by jlorette         ###   ########.fr       */
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
		return ("xpm/end.xpm");
	else if (c == 'C')
		return ("xpm/snake.xpm");
	else if (c == 'P')
		return ("xpm/drago.xpm");
	else
		return ("xpm/floor.xpm");
}

void	generate_map(t_map *map, t_mlx *mlx)
{
	int		i;
	int		j;

	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, map->cols * SIZE_IMG,
			map->rows * SIZE_IMG, "So_long");
	j = 0;
	while (j < map->rows)
	{
		i = 0;
		while (i < map->cols)
		{
			mlx->img = mlx_xpm_file_to_image(mlx->mlx,
					name_img(map->map[j][i]), &mlx->width, &mlx->height);
			mlx_put_image_to_window(mlx, mlx->win, mlx->img,
				SIZE_IMG * i, SIZE_IMG * j);
			i++;
		}
		j++;
	}
	mlx_loop(mlx);
}
