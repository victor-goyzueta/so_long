/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:07:54 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/18 02:21:05 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(int argc, char *file)
{
	t_map	*map;

	if (argc != 2)
		ft_perror(USAGE);
	if (!file || !*file)
		ft_perror(USAGE);
	map = NULL;
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		ft_perror(FAIL_ALLOC);
	map->matrix = NULL;
	check_map_format(file, map);
	allocate_map(map);
	check_map_rectangular(map);
	check_map_walls(map);
	check_map_composition(map);
	check_map_playable(map);
	print_map(map); //delete
	print_objects(map); //delete
}

int	main(int argc, char **argv)
{
	check_map(argc, argv[1]);
	/*init_mxl*/
}
