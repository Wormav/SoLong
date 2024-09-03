/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:04:12 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/03 14:06:30 by jlorette         ###   ########.fr       */
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

typedef struct s_map
{
	int		cols;
	int		rows;
	char	**map;
}				t_map;

char	**allocate_map(int rows, int cols);
t_map	*create_map_structure(const char *filename);
void	free_map(t_map *map_struct);

#endif