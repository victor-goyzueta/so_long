/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:47 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/18 22:08:45 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_map(t_game *game)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < game->map->row)
	{
		x = 0;
		while (x < game->map->col && game->map->matrix[y][x] != '\n')
		{
			if (game->map->matrix[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->window->new, game->texture->player, x * SIZE, y * SIZE);
			else if (game->map->matrix[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window->new, game->texture->exit, x * SIZE, y * SIZE);
			else if (game->map->matrix[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window->new, game->texture->item, x * SIZE, y * SIZE);
			else if (game->map->matrix[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->window->new, game->texture->wall, x * SIZE, y * SIZE);
			else if (game->map->matrix[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->window->new, game->texture->floor, x * SIZE, y * SIZE);
			x++;
		}
		y++;
	}
}

static void	render_window(t_game *game)
{
	load_object(game);
	render_map(game);
	/*render_player*/
}

void	init_mlx(t_game *game)
{
	if (!game)
		ft_perror(FAIL_ALLOC);
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_perror(FAIL_ALLOC);
	game->window->new = NULL;
	game->window->new = mlx_new_window(game->mlx, 800, 600, "so_long");
	if (!game->window->new)
		ft_perror(FAIL_ALLOC);
	render_window(game);
}
