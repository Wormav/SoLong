/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:04:12 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/02 19:49:02 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 4096

typedef struct s_img
{
	void	*img_player;
	void	*img_wall;
	void	*img_collect;
	void	*img_enemy;
	void	*img_exit;
	int		height;
	int		width;
}				t_img;

typedef struct s_pos
{
	int		x;
	int		y;
}				t_pos;

char	**read_map(const char *filename, int *rows, int *cols);

#endif