/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:47 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/19 17:13:29 by vgoyzuet         ###   ########.fr       */
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
		while (x < game->map->col)
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

void	init_mlx(t_game *game)
{
	if (!game)
		ft_perror(FAIL_ALLOC);
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_perror(FAIL_ALLOC);
	game->window->new = NULL;
	game->window->size = 0;
	game->window->size = SIZE;
	load_object(game);
	game->window->new = mlx_new_window(game->mlx, game->map->col * SIZE, game->map->row * SIZE, "so_long");
	if (!game->window->new)
		ft_perror(FAIL_ALLOC);
	render_map(game);
}
