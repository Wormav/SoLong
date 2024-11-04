/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:13:48 by jlorette          #+#    #+#             */
/*   Updated: 2024/11/04 10:13:50 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include "../includes/so_long.h"

void	keypress_d(t_game *game)
{
	move_player(game, 1, 0);
}

void	keypress_w(t_game *game)
{
	move_player(game, 0, -1);
}

void	keypress_a(t_game *game)
{
	move_player(game, -1, 0);
}

void	keypress_s(t_game *game)
{
	move_player(game, 0, 1);
}
