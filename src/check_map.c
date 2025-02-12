/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:42:04 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/12 21:56:16 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map_format(char *file)
{
	size_t	len;

	len = 0;
	if (!file || !*file)
		exit(EXIT_FAILURE);
	len = ft_strlen(file);
	if (ft_strncmp(file + (len - 4), ".ber", 4) != 0) //manage hide file
		exit(EXIT_FAILURE);
}

static void	check_map_rectangular(t_map *map)
{
	int	i;
	size_t	current;
	size_t	compared;

	i = 0;
	current = ft_strlen(map->matrix[i]);
	while (map->matrix[i++])
	{
		compared = ft_strlen(map->matrix[i]);
		if (current != compared)
			exit(EXIT_FAILURE); //free others
	}
	ft_printf("%d\n", i);
	if (i < 3)
		exit(EXIT_FAILURE); //free others
}

static void	check_map_walls(t_map *map)
{
	int	x;
	int	y;
	int	ymax;
	int	xmax;

	x = 0;
	y = 0;
	xmax = 0;
	ymax = 0;
	xmax = ft_strlen(map->matrix[y]) - 1;
	while (map->matrix[ymax + 1])
		ymax++;
	while (map->matrix[y][x] && map->matrix[ymax][x])
	{
		if (map->matrix[y][x] != '1' || map->matrix[ymax][x] != '1')
			exit(EXIT_FAILURE); //free others
		x++;
	}
	while (map->matrix[y][x] && map->matrix[y][xmax])
	{
		if (map->matrix[y][x] != '1' || map->matrix[y][xmax] != '1')
			exit(EXIT_FAILURE); //free others
		y++;
	}
}

void	check_map(char *file)
{
	t_map	*map;

	if (!file || !*file)
		exit(EXIT_FAILURE);
	map = NULL;
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		exit(EXIT_FAILURE);
	check_map_format(file);
	allocate_map(file, map);
	check_map_rectangular(map);
	check_map_walls(map);
	/*
	check_map_gameplay (floodfill)
	check_map_composition (0 | 1 | C | E | P)
	*/
}
