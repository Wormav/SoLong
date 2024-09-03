/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memories_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:28:51 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/03 11:32:56 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	free_map(char **map, int rows)
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

	map = malloc(rows * sizeof(char *));
	if (!map)
	{
		perror("Error allocating memory for map");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < rows)
	{
		map[i] = malloc((cols + 1) * sizeof(char));
		if (!map[i])
		{
			perror("Error allocating memory for map");
			free_map(map, rows);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (map);
}
