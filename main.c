/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:44:48 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/02 20:17:40 by jlorette         ###   ########.fr       */
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

void	print_map(char **map, int rows)
{
	int i;

	i = 0;
	while (i < rows)
	{
		printf("%s\n", map[i]);
		i++;
	}
}

void	free_map(char **map, int rows)
{
	int i;

	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	main(void)
{
	char	**map;
	int		rows;
	int		cols;

	map = read_map("maps/test2.ber", &rows, &cols);
	if (!map)
	{
		fprintf(stderr, "Error: Could not read map.\n");
		return (EXIT_FAILURE);
	}

	printf("Map dimensions: %d rows x %d columns\n", rows, cols);
	print_map(map, rows);

	free_map(map, rows);
	return (EXIT_SUCCESS);
}