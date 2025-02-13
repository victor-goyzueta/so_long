/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:12:46 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/13 17:15:29 by vgoyzuet         ###   ########.fr       */
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
	map->collec = NULL;
	map->start = ft_calloc(1, sizeof(t_pos));
	if (!map->start)
		ft_perror(FAIL_ALLOC);
	map->start->next = NULL;
	map->end = ft_calloc(1, sizeof(t_pos));
	if (!map->end)
		ft_perror(FAIL_ALLOC);
	map->end->next = NULL;
	map->collec = ft_calloc(1, sizeof(t_pos));
	if (!map->collec)
		ft_perror(FAIL_ALLOC);
	map->collec->next = NULL;
}

void	allocate_map(t_map *map)
{
	int	fd;

	allocate_matrix(map, &fd);
	allocate_pos(map);
}

void	count_object(unsigned int *count, t_pos **object, int x, int y)
{
	t_pos 			*current;
	unsigned int	i;
	static int		here;

	here += 1;
	ft_printf("%d\n", here);
	if (!count || !object || !*object)
		ft_perror(FAIL_ALLOC);
	i = 0;
	current = ft_calloc(1, sizeof(t_pos));
	if (!current)
		ft_perror(FAIL_ALLOC);
	while (i < *count)
	{
		*object = (* object)->next;
		i++;
	}
	*count += 1;
	*object = current;
	(* object)->x = x;
	(* object)->y = y;
	(* object)->next = NULL;
}

// void	check_map_playable(t_map *map)
// {
// 	//
// }
