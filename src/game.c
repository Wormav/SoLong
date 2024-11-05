/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:13:34 by jlorette          #+#    #+#             */
/*   Updated: 2024/11/05 15:45:26 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../mlx_linux/mlx.h"
#include "../libft/libft.h"
#include "../includes/so_long.h"

int	close_game(t_game *game)
{
	mlx_clear_window(game->mlx->mlx, game->mlx->win);
	mlx_destroy_window(game->mlx->mlx, game->mlx->win);
	mlx_destroy_display(game->mlx->mlx);
	free_map(game->map);
	free(game->mlx->mlx);
	free(game);
	exit(0);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 119)
		keypress_w(game);
	else if (keycode == 97)
		keypress_a(game);
	else if (keycode == 115)
		keypress_s(game);
	else if (keycode == 100)
		keypress_d(game);
	else if (keycode == 65307)
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
	mlx_loop_end(game->mlx);
}
