/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:32:32 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/04 10:58:59 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/so_long.h"

static int	explore_path_from_start(t_map *map, int x, int y, int visited[])
{
	if (x < 0 || x >= map->rows || y < 0 || y >= map->cols
		|| map->map[x][y] == '1' || visited[x * map->cols + y])
		return (0);
	if (map->map[x][y] == 'E')
		return (1);
	visited[x * map->cols + y] = 1;
	if (explore_path_from_start(map, x + 1, y, visited)
		|| explore_path_from_start(map, x - 1, y, visited)
		|| explore_path_from_start(map, x, y + 1, visited)
		|| explore_path_from_start(map, x, y - 1, visited))
		return (1);
	return (0);
}

static int	find_start_position(t_map *map, int *start_x, int *start_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->map[i][j] == 'P')
			{
				*start_x = i;
				*start_y = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	*start_x = -1;
	*start_y = -1;
	return (0);
}

static int	check_valid_path(t_map *map)
{
	int	start_x;
	int	start_y;
	int	*visited;
	int	index;
	int	result;

	visited = malloc(map->rows * map->cols * sizeof(int));
	if (!visited)
		return (0);
	index = 0;
	while (index < map->rows * map->cols)
	{
		visited[index] = 0;
		index++;
	}
	if (!find_start_position(map, &start_x, &start_y) || start_x == -1)
	{
		free(visited);
		return (0);
	}
	result = explore_path_from_start(map, start_x, start_y, visited);
	free(visited);
	return (result);
}

int	check_map(t_map *map)
{
	int	exit;
	int	player;
	int	collectable;

	exit = 0;
	player = 0;
	collectable = 0;
	if (!check_rectangular_shape(map) || !check_valid_chars(map)
		|| !check_walls(map) || !check_valid_path(map)
		|| !check_required_elements(map, &exit, &player, &collectable))
		return (0);
	return (1);
}
