/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:42:04 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/18 21:19:48 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_format(char *file, t_map *map)
{
	size_t	len;

	len = 0;
	if (!file || !*file)
		ft_perror(USAGE);
	len = ft_strlen(file);
	if (ft_strncmp(file + (len - 4), ".ber", 4) != 0
		|| file[len - 5] == '/' || len < 5)
		ft_perror(USAGE);
	map->path = NULL;
	map->path = ft_strdup(PATH_MAP);
	if (!map->path)
		ft_perror(FAIL_ALLOC);
	map->path = ft_strjoin(map->path, file);
	if (!map->path)
		ft_perror(FAIL_ALLOC);
}

void	check_map_rectangular(t_map *map)
{
	int		i;
	size_t	current;
	size_t	compared;

	if (!map)
		ft_perror(FAIL_ALLOC);
	i = 0;
	current = ft_strlen(map->matrix[i]);
	while (map->matrix[++i])
	{
		compared = ft_strlen(map->matrix[i]);
		if (current != compared)
			ft_perror("Map is not rectangular"); //free others
	}
	if (i < 3)
		ft_perror("Map is not playable"); //free others
}

void	check_map_walls(t_map *map)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	if (!map)
		ft_perror(FAIL_ALLOC);
	map->col = ft_strlen(map->matrix[y]);
	while (map->matrix[map->row])
		map->row++;
	while (x < map->col)
	{
		if (map->matrix[y][x] != '1' || map->matrix[map->row - 1][x] != '1')
			ft_perror("Map is not surrounded by walls"); //free others
		x++;
	}
	x = 0;
	while (y < map->row)
	{
		if (map->matrix[y][x] != '1' || map->matrix[y][map->col - 1] != '1')
			ft_perror("Map is not surrounded by walls"); //free others
		y++;
	}
}

void	check_map_composition(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->matrix[y])
	{
		x = 0;
		while (map->matrix[y][x] && map->matrix[y][x] != '\n')
		{
			if (map->matrix[y][x] == 'C')
				map->count_collec += 1;
			else if (map->matrix[y][x] == 'P')
				set_object(map->start, x, y);
			else if (map->matrix[y][x] == 'E')
				set_object(map->end, x, y);
			else if (map->matrix[y][x] != '1' && map->matrix[y][x] != '0')
				ft_perror(FAIL_COMP);
			x++;
		}
		y++;
	}
	if (map->count_collec < 1 || map->start->count != 1 || map->end->count != 1)
		ft_perror(FAIL_COMP);
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
	flood_fill(map, cpy, map->start->x, map->start->y);
	if (map->count_collec != 0 || map->end->count != 0)
		ft_perror("Map is not playable");
	map->count_collec = count;
	map->end->count = 1;
	free(cpy);
}
