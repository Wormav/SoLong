/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:13:52 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/13 14:08:47 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "../includes/libft.h"
#include "../includes/so_long.h"

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx->mlx, game->mlx->win);
	free(game);
	exit (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 13)
		keypress_w(game);
	else if (keycode == 0)
		keypress_a(game);
	else if (keycode == 1)
		keypress_s(game);
	else if (keycode == 2)
		keypress_d(game);
	else if (keycode == 53)
		close_game(game);
	return (0);
}

void	game(t_mlx *mlx, t_map *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_putstr_fd("Error\nMemory allocation failed!\n", 2);
		return ;
	}
	game->mlx = mlx;
	game->map = map;
	game->mlx->win = mlx_new_window(game->mlx->mlx, map->cols * SIZE_IMG,
			map->rows * SIZE_IMG, "So_long");
	generate_map(game->map, game->mlx);
	mlx_hook(game->mlx->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->mlx->win, 17, 0, close_game, game);
	mlx_loop(game->mlx->mlx);
	free_map(game->map);
	free(game);
}
