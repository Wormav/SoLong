/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:56:16 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/03 14:00:13 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../includes/so_long.h"

static void	count_rows(const char *buffer, int *rows)
{
	int	i;

	i = 0;
	*rows = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			(*rows)++;
		i++;
	}
	if (buffer[i - 1] != '\n')
		(*rows)++;
}

static void	count_columns(const char *buffer, int *max_cols)
{
	int	i;
	int	c_count;

	i = 0;
	c_count = 0;
	*max_cols = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			if (c_count > *max_cols)
				*max_cols = c_count;
			c_count = 0;
		}
		else
		{
			c_count++;
		}
		i++;
	}
	if (c_count > *max_cols)
		*max_cols = c_count;
}

static void	copy_buffer_to_map(const char *buffer, char **map, int rows)
{
	int	i;
	int	row;
	int	col;

	row = 0;
	i = 0;
	while (row < rows)
	{
		col = 0;
		while (buffer[i] != '\n' && buffer[i] != '\0')
		{
			map[row][col] = buffer[i];
			col++;
			i++;
		}
		map[row][col] = '\0';
		row++;
		i++;
	}
}

static char	**read_map(const char *filename, int *rows, int *cols)
{
	int		fd;
	int		bytes_read;
	char	buffer[BUFFER_SIZE];
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		perror("Error reading file");
		close(fd);
		exit(EXIT_FAILURE);
	}
	buffer[bytes_read] = '\0';
	count_rows(buffer, rows);
	count_columns(buffer, cols);
	map = allocate_map(*rows, *cols);
	copy_buffer_to_map(buffer, map, *rows);
	close(fd);
	return (map);
}

t_map	*create_map_structure(const char *filename)
{
	int		rows;
	int		cols;
	char	**raw_map;
	t_map	*map_struct;

	rows = 0;
	cols = 0;
	raw_map = read_map(filename, &rows, &cols);
	map_struct = malloc(sizeof(t_map));
	if (!map_struct)
	{
		perror("Error allocating memory for map structure");
		exit(EXIT_FAILURE);
	}
	map_struct->rows = rows;
	map_struct->cols = cols;
	map_struct->map = raw_map;
	return (map_struct);
}
