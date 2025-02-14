/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:42:04 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/14 03:33:50 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map_format(char *file, t_map *map)
{
	size_t	len;

	len = 0;
	if (!file || !*file)
		exit(EXIT_FAILURE);
	len = ft_strlen(file);
	if (ft_strncmp(file + (len - 4), ".ber", 4) != 0
		|| file[len - 5] == '/' || len < 5)
		ft_perror(USAGE);
	map->path = NULL;
	map->path = ft_strdup(PATH);
	if (!map->path)
		ft_perror(FAIL_ALLOC);
	map->path = ft_strjoin(map->path, file);
	if (!map->path)
		ft_perror(FAIL_ALLOC);
}

static void	check_map_rectangular(t_map *map)
{
	int		i;
	size_t	current;
	size_t	compared;

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

static void	check_map_walls(t_map *map)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
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

static void	check_map_composition(t_map *map)
{
	int				x;
	int				y;

	map->count_collec = 0;
	map->count_start = 0;
	map->count_end = 0;
	y = 0;
	while (map->matrix++)
	{
		x = 0;
		while (map->matrix[y][x])
		{
			ft_printf("map->matrix[%d][%d] = %c | Dirección: %p\n", y, x, map->matrix[y][x], map->matrix);
			ft_printf("Encontrado '%c' en (%u, %u)\n", map->matrix[y][x], y, x);
			if (map->matrix[y][x] == 'C')
				map->count_collec += 1;
			else if (map->matrix[y][x] == 'P' || map->matrix[y][x] == 'E')
				set_object(map, x, y, map->matrix[y][x]);
			else if (map->matrix[y][x] != '1' && map->matrix[y][x] != '0')
				ft_perror(FAIL_COMP);
			x++;
		}
		y++;
	}
	if (map->count_collec < 1)
		ft_perror(FAIL_COMP);
}

void	check_map(char *file)
{
	t_map	*map;

	if (!file || !*file)
		exit(EXIT_FAILURE);
	map = NULL;
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		ft_perror(FAIL_ALLOC);
	check_map_format(file, map);
	allocate_map(map);
	print_map(map);
	check_map_rectangular(map);
	check_map_walls(map);
	check_map_composition(map);
	//check_map_playable(map);
}
