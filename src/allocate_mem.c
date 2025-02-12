/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:12:46 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/12 21:56:32 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	allocate_map(char *file, t_map *map)
{
	int		fd;
	char	*line;
	char	*add;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	line = get_next_line(fd);
	if (!line)
		exit(EXIT_FAILURE);
	add = get_next_line(fd);
	if (!add)
		exit(EXIT_FAILURE);
	while (add)
	{
		line = ft_strjoin(line, add);
		free(add);
		add = get_next_line(fd);
	}
	free(add);
	map->matrix = ft_split(line, '\n');
	if (!map->matrix)
		exit(EXIT_FAILURE);
	free(line);
	close(fd);
}
