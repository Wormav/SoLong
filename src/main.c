/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:44:48 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/10 16:35:47 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "../includes/so_long.h"
#include "../includes/libft.h"

static int	map_process(const char *filename, t_map *map_struct)
{
	*map_struct = *create_map_structure(filename, map_struct);
	if (!map_struct->map)
	{
		ft_putstr_fd("Error: Could not read map.\n", 2);
		return (0);
	}
	if (!check_map(map_struct))
	{
		ft_putstr_fd("Error\nThe map is not valid!\n", 2);
		return (0);
	}
	return (1);
}

static int	game_process(t_mlx *mlx, t_map *map)
{
	mlx->mlx = mlx_init();
	mlx->moves = 0;
	if (!mlx->mlx)
	{
		ft_putstr_fd("Error: MLX initialization failed.\n", 2);
		free_map(map);
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
