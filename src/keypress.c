/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:35:53 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/08 18:18:06 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/so_long.h"

void	keypress_d(t_map *map, t_mlx *mlx)
{
	move_player(map, mlx, 1, 0);
}

void	keypress_w(t_map *map, t_mlx *mlx)
{
	move_player(map, mlx, 0, -1);
}

void	keypress_a(t_map *map, t_mlx *mlx)
{
	move_player(map, mlx, -1, 0);
}

void	keypress_s(t_map *map, t_mlx *mlx)
{
	move_player(map, mlx, 0, 1);
}
