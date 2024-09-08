/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:44:48 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/08 12:09:48 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "../includes/so_long.h"
#include "../includes/libft.h"

static int map_process(const char *filename, t_map *map_struct)
{
	*map_struct = *create_map_structure(filename);
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

int main(int argc, char **argv)
{
	t_map	map;
	t_mlx	mlx;

	if (argc == 2 && argv)
	{
		if (!map_process(argv[1], &map))
		{
			free_map(&map);
			return (1);
		}

		// Initialisation MLX
		mlx.mlx = mlx_init();
		if (!mlx.mlx)
		{
			ft_putstr_fd("Error: MLX initialization failed.\n", 2);
			free_map(&map);
			return (1);
		}

		// Démarrage du jeu
		game(&mlx, &map);

		// Nettoyage
		free_map(&map);
		return (0);
	}
	else
	{
		ft_putstr_fd("Error\nThe number of arguments provided is incorrect\n", 2);
	}
	return (1);
}