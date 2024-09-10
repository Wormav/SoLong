/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:07:45 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/10 16:55:36 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_pos	find_player_position(t_map *map)
{
	t_pos	pos;
	int		i;
	int		j;
	int		found;

	i = 0;
	found = 0;
	while (i < map->rows && !found)
	{
		j = 0;
		while (j < map->cols && !found)
		{
			if (map->map[i][j] == 'P')
			{
				pos.x = j;
				pos.y = i;
				found = 1;
			}
			j++;
		}
		i++;
	}
	return (pos);
}

t_pos	find_end_position(t_map *map)
{
	t_pos	pos;
	int		i;
	int		j;
	int		found;

	i = 0;
	found = 0;
	while (i < map->rows && !found)
	{
		j = 0;
		while (j < map->cols && !found)
		{
			if (map->map[i][j] == 'E')
			{
				pos.x = j;
				pos.y = i;
				found = 1;
			}
			j++;
		}
		i++;
	}
	return (pos);
}
