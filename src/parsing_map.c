/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:56:16 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/02 20:01:08 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../includes/so_long.h"

void count_rows_and_columns(const char *buffer, int *rows, int *max_cols) {
	int i;
	int c_count;

	i = 0;
	c_count = 0;
	*rows = 0;
	*max_cols = 0;
	while (buffer[i] != '\0') {
		if (buffer[i] == '\n') {
			(*rows)++;
			if (c_count > *max_cols) {
				*max_cols = c_count;
			}
			c_count = 0;
		} else {
			c_count++;
		}
		i++;
	}
	if (c_count > 0) {
		(*rows)++;
		if (c_count > *max_cols) {
			*max_cols = c_count;
		}
	}
}

void copy_buffer_to_map(const char *buffer, char **map, int rows, int max_cols) {
	int i = 0;
	int row = 0;
	int col = 0;

	while (row < rows) {
		col = 0;
		while (buffer[i] != '\n' && buffer[i] != '\0') {
			map[row][col] = buffer[i];
			col++;
			i++;
		}
		map[row][col] = '\0';
		row++;
		i++;
	}
}

char	**read_map(const char *filename, int *rows, int *cols)
{
	int		fd;
	int		bytes_read;
	char	buffer[BUFFER_SIZE];
	char	**map;
	int		i;

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
	count_rows_and_columns(buffer, rows, cols);
	map = malloc((*rows) * sizeof(char *));
	if (!map)
	{
		perror("Error allocating memory for map");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < *rows)
	{
		map[i] = malloc((*cols + 1) * sizeof(char));
		if(!map[i])
			perror("Error allocating memory for map");
			// Il faut free les précédent dans ce cas la
		i++;
	}
	copy_buffer_to_map(buffer, map, *rows, *cols);
	close(fd);
	return map;
}
