/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:12:46 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/17 21:22:59 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	allocate_matrix(t_map *map, int *fd)
{
	char	*line;
	char	*add;

	*fd = open(map->path, O_RDONLY);
	if (*fd < 0)
		ft_perror("Failed to open fd");
	line = ft_strdup("");
	if (!line)
		ft_perror(FAIL_ALLOC);
	add = get_next_line(*fd);
	if (!add)
		ft_perror(FAIL_ALLOC);
	while (add)
	{
		line = ft_strjoin(line, add);
		if (!line)
			ft_perror(FAIL_ALLOC);
		free(add);
		add = get_next_line(*fd);
	}
	(*map).matrix = ft_split(line, '\n');
	if (!(*map).matrix)
		ft_perror(FAIL_ALLOC);
	free_arrays(3, map->path, line, add);
	close(*fd);
}

void	allocate_object(t_map *map)
{
	map->start = NULL;
	map->end = NULL;
	map->start = ft_calloc(1, sizeof(t_pos));
	if (!map->start)
		ft_perror(FAIL_ALLOC);
	map->end = ft_calloc(1, sizeof(t_pos));
	if (!map->end)
		ft_perror(FAIL_ALLOC);
	map->count_collec = 0;
	map->start->count = 0;
	map->end->count = 0;
}

void	set_object(t_pos *object, int x, int y)
{
	if (!object)
		ft_perror(FAIL_ALLOC);
	if ((*object).count != 0)
		ft_perror(FAIL_COMP);
	object->count = 1;
	object->x = x;
	object->y = y;
}

static void	flood_fill(t_map *map, unsigned int x, unsigned int y)
{
	if (x < 0 || y < 0 || x >= map->col || y >= map->row ||
		map->matrix[y][x] == '1' || map->matrix[y][x] == 'F')
		return ;
	if (map->matrix[y][x] == 'C')
		map->count_collec--;
	if (map->matrix[y][x] == 'E')
		map->end->count--;
	if (map->matrix[y][x] != 'P')
		map->matrix[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y - 1);
}

void	check_map_playable(t_map *map)
{
	int				i;
	char			**cpy;
	unsigned char	count;

	cpy = NULL;
	cpy = ft_calloc(map->row, sizeof(char *));
	if (!cpy || !map)
		ft_perror(FAIL_ALLOC);
	count = 0;
	count = map->count_collec;
	i = -1;
	while (map->matrix[++i])
	{
		cpy[i] = ft_strdup(map->matrix[i]);
		if (!cpy[i])
			ft_perror(FAIL_ALLOC);
	}
	cpy[i] = NULL;
	flood_fill(map, map->start->x, map->start->y);
	if (map->count_collec != 0 || map->end->count != 0)
		ft_perror("Map is not playable");
	map->count_collec = count;
	map->end->count = 1;
	map->matrix = cpy;
	free(cpy);
}
