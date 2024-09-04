/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:44:48 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/04 15:44:27 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "../includes/so_long.h"
#include "../includes/libft.h"

/*void print_map(t_map *map_struct)
{
	int i = 0;
	while (i < map_struct->rows)
	{
		printf("%s\n", map_struct->map[i]);
		i++;
	}
}*/

static int	map_process(const char *filename, t_map *map_struct)
{
	*map_struct = *create_map_structure(filename);
	if (!map_struct->map)
	{
		ft_putstr_fd("Error: Could not read map.\n", 2);
		return (0);
	}
	if (!check_map(map_struct))
	{
		ft_putstr_fd("Error\nThe map is not valid!", 2);
		return (0);
	}
	return (1);
}

int	main(void)
{
	t_map	map;
	t_mlx	mlx;

	if (!map_process("maps/test.ber", &map))
	{
		free_map(&map);
		return (1);
	}
	generate_map(&map, &mlx);
	free_map(&map);
	return (0);
}
