/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collectibles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:38:46 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/12 13:07:20 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../includes/so_long.h"

static int	explore_collectibles(t_map *map, int x, int y, int visited[])
{
	if (x < 0 || x >= map->rows || y < 0 || y >= map->cols
		|| map->map[x][y] == '1' || visited[x * map->cols + y])
		return (0);
	if (map->map[x][y] == 'C')
		map->collectible--;
	visited[x * map->cols + y] = 1;
	explore_collectibles(map, x + 1, y, visited);
	explore_collectibles(map, x - 1, y, visited);
	explore_collectibles(map, x, y + 1, visited);
	explore_collectibles(map, x, y - 1, visited);
	return (1);
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

int	check_collectibles(t_map *map)
{
	int	start_x;
	int	start_y;
	int	*visited;
	int	index;
	int	result;

	count_collectible(map);
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
	explore_collectibles(map, start_x, start_y, visited);
	free(visited);
	result = map->collectible == 0;
	return (result);
}
