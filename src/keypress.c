/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:35:53 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/10 16:29:37 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
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
