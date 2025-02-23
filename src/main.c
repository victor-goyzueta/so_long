/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:07:54 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/19 23:12:36 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(char *file, t_game *game)
{
	int	fd;

	fd = 0;
	if (!file || !*file)
		ft_perror(USAGE);
	if (!game)
		ft_perror(FAIL_ALLOC);
	game->map->matrix = NULL;
	check_map_format(file, game);
	allocate_matrix(game, &fd);
	allocate_object(game);
	check_map_rectangular(game);
	check_map_walls(game);
	check_map_composition(game);
	check_map_playable(game);
}

void	init(t_game *game)
{
	if (!game)
		ft_perror(FAIL_ALLOC);
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_perror(FAIL_ALLOC);
	game->window->new = NULL;
	game->window->width = 0;
	game->window->height = 0;
	game->window->width = WIDTH;
	game->window->height = HEIGHT;
	load_object(game);
	game->window->new = mlx_new_window(game->mlx,
			game->map->col * WIDTH, game->map->row * HEIGHT, "so_long");
	if (!game->window->new)
		ft_perror(FAIL_ALLOC);
	render_map(game);
	allocate_player(game);
}

void	play(t_game *game)
{
	if (!game)
		ft_perror(FAIL_ALLOC);
	mlx_key_hook(game->window->new, handle_keypress, game);
	mlx_hook(game->window->new, CLIC_X, 0, free_exit, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game		*game;

	if (argc != 2)
		ft_perror(USAGE);
	allocate_struct(&game);
	check_map(argv[1], game);
	init(game);
	play(game);
}
