/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:13:41 by jlorette          #+#    #+#             */
/*   Updated: 2024/11/04 10:13:43 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include "../includes/so_long.h"

static char	*name_img(char c)
{
	if (c == '1')
		return ("textures/wall.xpm");
	else if (c == 'E')
		return ("textures/floor.xpm");
	else if (c == 'C')
		return ("textures/snake.xpm");
	else if (c == 'P')
		return ("textures/drago.xpm");
	else
		return ("textures/floor.xpm");
}

void	count_collectible(t_map *map)
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
			if (map->data[i][j] == 'C')
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

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			mlx->img = mlx_xpm_file_to_image(mlx->mlx,
					name_img(map->data[i][j]), &mlx->width, &mlx->height);
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img,
				SIZE_IMG * j, SIZE_IMG * i);
			mlx_destroy_image(mlx->mlx, mlx->img);
			j++;
		}
		i++;
	}
	count_collectible(map);
}
