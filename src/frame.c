/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:57:47 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/13 13:50:42 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "../includes/libft.h"
#include "../includes/so_long.h"

static void	draw_tile(t_mlx *mlx, int x, int y, char *tile)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx_xpm_file_to_image(mlx->mlx, tile, &mlx->width, &mlx->height),
		x * SIZE_IMG, y * SIZE_IMG);
}

static int	can_move(t_game *game, t_pos pos, t_pos offset)
{
	int		new_i;
	int		new_j;
	t_pos	end_pos;

	new_i = pos.y + offset.y;
	new_j = pos.x + offset.x;
	if (game->map->map[new_i][new_j] == 'C')
		game->map->collectible--;
	if (game->map->map[new_i][new_j] == 'E' && game->map->collectible == -1)
	{
		ft_putnbr_fd(game->mlx->moves + 1, 1);
		ft_putchar_fd('\n', 1);
		ft_putstr_fd("Congratulations you won with: ", 1);
		ft_putnbr_fd(game->mlx->moves + 1, 1);
		ft_putstr_fd(" moves!", 1);
		close_game(game);
	}
	if (game->map->collectible == 0)
	{
		end_pos = find_end_position(game->map);
		draw_tile(game->mlx, end_pos.x, end_pos.y, "textures/end.xpm");
		game->map->collectible--;
	}
	return (new_i >= 0 && new_i < game->map->rows && new_j
		>= 0 && new_j < game->map->cols && game->map->map[new_i][new_j] != '1');
}

static void	update_position(t_map *map, t_mlx *mlx, t_pos pos, t_pos offset)
{
	if (pos.x == map->end_pos.x && pos.y == map->end_pos.y )
		map->map[pos.y][pos.x] = 'E';
	else
		map->map[pos.y][pos.x] = '0';
	draw_tile(mlx, pos.x, pos.y, "textures/floor.xpm");
	map->map[pos.y + offset.y][pos.x + offset.x] = 'P';
	draw_tile(mlx, pos.x + offset.x, pos.y + offset.y, "textures/drago.xpm");
}

void	move_player(t_game *game, int x_offset, int y_offset)
{
	t_pos	pos;
	t_pos	offset;

	offset.y = y_offset;
	offset.x = x_offset;
	pos = find_player_position(game->map);
	if (can_move(game, pos, offset))
	{
		update_position(game->map, game->mlx, pos, offset);
		game->mlx->moves++;
		ft_putnbr_fd(game->mlx->moves, 1);
		ft_putchar_fd('\n', 1);
	}
}
