/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_functions_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:16:07 by jlorette          #+#    #+#             */
/*   Updated: 2024/11/04 08:12:50 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/so_long.h"
#include "../libft/libft.h"

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

int	check_valid_chars(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (!is_valid_char(map->data[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_required_elements(t_map *map, int *exit,
	int *player, int *collectable)
{
	int		i;
	int		j;
	char	current_char;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			current_char = map->data[i][j];
			if (current_char == 'E')
				(*exit)++;
			else if (current_char == 'P')
				(*player)++;
			else if (current_char == 'C')
				(*collectable)++;
			j++;
		}
		i++;
	}
	if (*exit != 1 || *player != 1 || *collectable < 1)
		return (0);
	return (1);
}

int	check_rectangular_shape(t_map *map)
{
	int	i;
	int	first_row_length;

	i = 0;
	first_row_length = ft_strlen(map->data[0]);
	while (i < map->rows)
	{
		if (ft_strlen(map->data[i]) != first_row_length)
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->cols)
	{
		if (map->data[0][i] != '1' || map->data[map->rows - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->rows)
	{
		if (map->data[i][0] != '1' || map->data[i][map->cols - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
