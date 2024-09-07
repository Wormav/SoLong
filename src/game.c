/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:13:52 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/07 21:01:30 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>

#include "../includes/so_long.h"

int handle_keypress(int keycode, t_game *game)
{
	if (keycode == 2)  // Touche D
		keypress_d(game->map);

	if (keycode == 53)  // Touche Échap
	{
		if (game->mlx->win)  // Vérifie si la fenêtre existe
		{
			mlx_destroy_window(game->mlx->mlx, game->mlx->win);
			game->mlx->win = NULL;  // Mets à NULL après destruction
		}
		exit(0);  // Quitte le programme proprement
	}
	return (0);
}

void game(t_mlx *mlx, t_map *map)
{
	t_game game;

	game.mlx = mlx;
	game.map = map;
	mlx_hook(mlx->win, 2, 1L << 0, handle_keypress, &game);
}