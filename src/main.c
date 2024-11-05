/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:13:55 by jlorette          #+#    #+#             */
/*   Updated: 2024/11/05 15:45:06 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../mlx_linux/mlx.h"
#include "../includes/so_long.h"
#include "../libft/libft.h"

static int	map_process(const char *filename, t_map *map)
{
	*map = *create_map_structure(filename, map);
	if (!map->data)
	{
		ft_putstr_fd("Error: Could not read map.\n", 2);
		return (0);
	}
	if (!check_map(map))
	{
		ft_putstr_fd("Error\nThe map is not valid!\n", 2);
		return (0);
	}
	map->end_pos = find_end_position(map);
	return (1);
}

static int	game_process(t_mlx *mlx, t_map *map)
{
	mlx->mlx = mlx_init();
	mlx->moves = 0;
	if (!mlx->mlx)
	{
		ft_putstr_fd("Error: MLX initialization failed.\n", 2);
		// free map avant
		return (0);
	}
	game(mlx, map);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_mlx	mlx;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		ft_putstr_fd("Error\nAllocating memory for map structure", 2);
		exit(EXIT_FAILURE);
	}
	if (argc == 2 && argv)
	{
		if (!map_process(argv[1], map) || !game_process(&mlx, map))
		{
			free_map(map);
			return (1);
		}
		else
			return (0);
	}
	else
		ft_putstr_fd("Error\nThe number of arguments "
			"provided is incorrect\n", 2);
	return (1);
}
