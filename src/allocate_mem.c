/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:12:46 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/13 06:25:51 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	allocate_matrix(t_map *map, int *fd)
{
	char	*line;
	char	*add;

	*fd = open(map->path, O_RDONLY);
	if (*fd < 0)
		ft_perror("Failed to open fd");
	line = get_next_line(*fd);
	if (!line)
		exit(EXIT_FAILURE);
	add = get_next_line(*fd);
	if (!add)
		exit(EXIT_FAILURE);
	while (add)
	{
		line = ft_strjoin(line, add);
		if (!line)
			exit(EXIT_FAILURE);
		free(add);
		add = get_next_line(*fd);
	}
	map->matrix = ft_split(line, '\n');
	if (!map->matrix)
		exit(EXIT_FAILURE);
	free_arrays(3, map->path, add, line);
	close(*fd);
}

static void	allocate_pos(t_map *map)
{
	map->start = NULL;
	map->end = NULL;
	map->start = ft_calloc(1, sizeof(t_pos));
	if (!map->start)
		ft_perror(FAIL_ALLOC);
	map->end = ft_calloc(1, sizeof(t_pos));
	if (!map->end)
		ft_perror(FAIL_ALLOC);
}

void	allocate_map(t_map *map)
{
	int	fd;

	allocate_matrix(map, &fd);
	allocate_pos(map);
}
