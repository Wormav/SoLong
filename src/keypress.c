/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:35:53 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/07 21:02:29 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int keypress_d(t_map *map)
{
	int	i;
	int	j;
	int find;

	i = 0;
	find = 0;
	while (i < map->rows && find == 0)
	{
		j = 0;
		while (j < map->cols && find == 0)
		{
			if (map->map[i][j] == 'P' &&
				j + 1 < map->cols && map->map[i][j + 1] != '1')
			{
				map->map[i][j + 1] = 'P';
				map->map[i][j] = '0';
				find = 1;
			}
			j++;
		}
		i++;
	}
	return (1);
}
