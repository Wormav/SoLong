/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memories_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:28:51 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/09 17:05:02 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../includes/so_long.h"
#include "../includes/libft.h"

void	free_map(t_map *map_struct)
{
	int	i;

	i = 0;
	if (!map_struct)
		return ;
	if (map_struct->map)
	{
		while (map_struct->map[i])
		{
			free(map_struct->map[i]);
			i++;
		}
	}
	free(map_struct->map);
	free(map_struct);
}

static void	free_partial_map(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**allocate_map(int rows, int cols)
{
	char	**map;
	int		i;

	map = malloc((rows + 1) * sizeof(char *));
	if (!map)
	{
		ft_putstr_fd("Error allocating memory for map", 2);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < rows)
	{
		map[i] = malloc((cols + 1) * sizeof(char));
		if (!map[i])
		{
			ft_putstr_fd("Error allocating memory for map", 2);
			free_partial_map(map, rows);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (map);
}
