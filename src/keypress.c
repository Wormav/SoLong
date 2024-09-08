/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:35:53 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/08 12:17:52 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/so_long.h"

void keypress_d(t_map *map, t_mlx *mlx)
{
	int i, j;
	int found = 0;

	i = 0;
	while (i < map->rows && !found)
	{
		j = 0;
		while (j < map->cols && !found)
		{
			if (map->map[i][j] == 'P' && j < (map->cols - 1) && map->map[i][j + 1] != '1')
			{
				// Redessiner l'ancienne position (mettre un sol)
				map->map[i][j] = '0';
				mlx_put_image_to_window(mlx->mlx, mlx->win,
										mlx_xpm_file_to_image(mlx->mlx, "xpm/floor.xpm", &mlx->width, &mlx->height),
										j * SIZE_IMG, i * SIZE_IMG);

				// Mettre à jour la nouvelle position du joueur
				map->map[i][j + 1] = 'P';
				mlx_put_image_to_window(mlx->mlx, mlx->win,
										mlx_xpm_file_to_image(mlx->mlx, "xpm/drago.xpm", &mlx->width, &mlx->height),
										(j + 1) * SIZE_IMG, i * SIZE_IMG);

				found = 1;
			}
			j++;
		}
		i++;
	}
}

void keypress_w(t_map *map, t_mlx *mlx)
{
	int i, j;
	int found = 0;

	i = 0;
	while (i < map->rows && !found)
	{
		j = 0;
		while (j < map->cols && !found)
		{
			if (map->map[i][j] == 'P' && i > 0 && map->map[i - 1][j] != '1')
			{
				map->map[i][j] = '0';
				mlx_put_image_to_window(mlx->mlx, mlx->win,
										mlx_xpm_file_to_image(mlx->mlx, "xpm/floor.xpm", &mlx->width, &mlx->height),
										j * SIZE_IMG, i * SIZE_IMG);

				map->map[i - 1][j] = 'P';
				mlx_put_image_to_window(mlx->mlx, mlx->win,
										mlx_xpm_file_to_image(mlx->mlx, "xpm/drago.xpm", &mlx->width, &mlx->height),
										j * SIZE_IMG, (i - 1) * SIZE_IMG);

				found = 1;
			}
			j++;
		}
		i++;
	}
}

void keypress_a(t_map *map, t_mlx *mlx)
{
	int i, j;
	int found = 0;

	i = 0;
	while (i < map->rows && !found)
	{
		j = 0;
		while (j < map->cols && !found)
		{
			if (map->map[i][j] == 'P' && j > 0 && map->map[i][j - 1] != '1')
			{
				map->map[i][j] = '0';
				mlx_put_image_to_window(mlx->mlx, mlx->win,
										mlx_xpm_file_to_image(mlx->mlx, "xpm/floor.xpm", &mlx->width, &mlx->height),
										j * SIZE_IMG, i * SIZE_IMG);

				map->map[i][j - 1] = 'P';
				mlx_put_image_to_window(mlx->mlx, mlx->win,
										mlx_xpm_file_to_image(mlx->mlx, "xpm/drago.xpm", &mlx->width, &mlx->height),
										(j - 1) * SIZE_IMG, i * SIZE_IMG);

				found = 1;
			}
			j++;
		}
		i++;
	}
}

void keypress_s(t_map *map, t_mlx *mlx)
{
	int i, j;
	int found = 0;

	i = 0;
	while (i < map->rows && !found)
	{
		j = 0;
		while (j < map->cols && !found)
		{
			if (map->map[i][j] == 'P' && i < map->rows - 1 && map->map[i + 1][j] != '1')
			{
				map->map[i][j] = '0';
				mlx_put_image_to_window(mlx->mlx, mlx->win,
										mlx_xpm_file_to_image(mlx->mlx, "xpm/floor.xpm", &mlx->width, &mlx->height),
										j * SIZE_IMG, i * SIZE_IMG);

				map->map[i + 1][j] = 'P';
				mlx_put_image_to_window(mlx->mlx, mlx->win,
										mlx_xpm_file_to_image(mlx->mlx, "xpm/drago.xpm", &mlx->width, &mlx->height),
										j * SIZE_IMG, (i + 1) * SIZE_IMG);

				found = 1;
			}
			j++;
		}
		i++;
	}
}