/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:07:54 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/18 17:34:39 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(int argc, char *file, t_game *game)
{
	if (argc != 2)
		ft_perror(USAGE);
	if (!file || !*file)
		ft_perror(USAGE);
	game->map->matrix = NULL;
	check_map_format(file, game->map);
	allocate_map(game->map);
	check_map_rectangular(game->map);
	check_map_walls(game->map);
	check_map_composition(game->map);
	check_map_playable(game->map);
}

int	main(int argc, char **argv)
{
	t_game		*game;

	game = NULL;
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		ft_perror(FAIL_ALLOC);
	allocate_mem(game);
	check_map(argc, argv[1], game);
	init_mlx(game);
}
