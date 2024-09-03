/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:44:48 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/03 14:10:19 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	mlx_loop(mlx);
}*/

#include <stdio.h>
#include <stdlib.h>
#include "includes/so_long.h"

void print_map(t_map *map_struct)
{
	int i = 0;
	while (i < map_struct->rows)
	{
		printf("%s\n", map_struct->map[i]);
		i++;
	}
}


int main(void)
{
	t_map *map_struct = create_map_structure("maps/test2.ber");
	if (!map_struct)
	{
		fprintf(stderr, "Error: Could not read map.\n");
		return EXIT_FAILURE;
	}

	printf("Map dimensions: %d rows x %d columns\n", map_struct->rows, map_struct->cols);
	print_map(map_struct);

	free_map(map_struct);
	return 0;
}