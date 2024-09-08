/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:13:52 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/08 12:18:00 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include <stdlib.h>
#include "../includes/libft.h"
#include "../includes/so_long.h"

int render_next_frame(t_game *game)
{
	if(game)
		return (0);
	return (0);
}

int close_game(t_game *game)
{
	if (game)
		free(game);
	exit(0);
}

int handle_keypress(int keycode, t_game *game)
{
	if (keycode == 13) // Touche "W" pour monter
	{
		keypress_w(game->map, game->mlx);
	}
	else if (keycode == 0) // Touche "A" pour aller à gauche
	{
		keypress_a(game->map, game->mlx);
	}
	else if (keycode == 1) // Touche "S" pour descendre
	{
		keypress_s(game->map, game->mlx);
	}
	else if (keycode == 2) // Touche "D" pour aller à droite
	{
		keypress_d(game->map, game->mlx);
	}
	else if (keycode == 53) // Touche "Échap" pour quitter
	{
		close_game(game);
	}
	return (0);
}

void game(t_mlx *mlx, t_map *map)
{
	t_game *game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_putstr_fd("Error\nMemory allocation failed!\n", 2);
		return;
	}
	game->mlx = mlx;
	game->map = map;

	game->mlx->win = mlx_new_window(game->mlx->mlx, map->cols * SIZE_IMG, map->rows * SIZE_IMG, "So_long");

	// Générer la carte initiale une seule fois
	generate_map(game->map, game->mlx);

	mlx_hook(game->mlx->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->mlx->win, 17, 0, close_game, game);
	mlx_loop(game->mlx->mlx);

	free(game);
}