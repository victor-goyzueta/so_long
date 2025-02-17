/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:12:46 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/17 17:57:58 by vgoyzuet         ###   ########.fr       */
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

static void	allocate_object(t_map *map)
{
	map->start = NULL;
	map->end = NULL;
	map->start = ft_calloc(1, sizeof(t_pos));
	if (!map->start)
		ft_perror(FAIL_ALLOC);
	map->end = ft_calloc(1, sizeof(t_pos));
	if (!map->end)
		ft_perror(FAIL_ALLOC);
	(*map).count_collec = 0;
	(*map).start->x= 0;
	(*map).start->y = 0;
}

void	allocate_map(t_map *map)
{
	int	fd;

	allocate_matrix(map, &fd);
	allocate_object(map);
}

void	set_object(t_pos *object, int x, int y)
{
	if (!object)
		ft_perror(FAIL_ALLOC);
	if ((*object).count != 0)
		ft_perror(FAIL_COMP);
	(*object).count = 1;
	object->count = 1;
	(*object).x = x;
	(*object).y = y;
}

// void	check_map_playable(t_map *map)
// {
// 	//
// }
