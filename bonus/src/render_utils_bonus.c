/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 02:19:59 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/03/03 19:19:43 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	select_wall_1(t_game *game, unsigned int x, unsigned int y)
{
	if (!game)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	if (y == 0 && x == 0)
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->wall_ul, x * WIDTH, y * HEIGHT);
	else if (y == 0 && x == game->map->col - 1)
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->wall_ur, x * WIDTH, y * HEIGHT);
	else if (y == game->map->row - 1 && x == 0)
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->wall_dl, x * WIDTH, y * HEIGHT);
	else if (y == game->map->row - 1 && x == game->map->col - 1)
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->wall_dr, x * WIDTH, y * HEIGHT);
}

static void	select_wall_2(t_game *game, unsigned int x, unsigned int y)
{
	if (!game)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	if (y == 0 && (x != 0 && x != game->map->col - 1))
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->wall_uc, x * WIDTH, y * HEIGHT);
	else if (y == game->map->row - 1 && (x != 0 && x != game->map->col - 1))
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->wall_dc, x * WIDTH, y * HEIGHT);
	else if (x == 0 && (y != 0 && y != game->map->row - 1))
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->wall_cl, x * WIDTH, y * HEIGHT);
	else if (x == game->map->col - 1 && (y != 0 && y != game->map->row - 1))
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->wall_cr, x * WIDTH, y * HEIGHT);
	else if ((x != 0 && x != game->map->col - 1)
		|| (y != 0 && y != game->map->row - 1))
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->wall_cc, x * WIDTH, y * HEIGHT);
}

static void	set_put_img_to_window(t_game *game, char id, int x, int y)
{
	if (!game)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	if (id == 'P')
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->player, x * WIDTH, y * HEIGHT);
	else if (id == 'E')
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->close, x * WIDTH, y * HEIGHT);
	else if (id == 'C')
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->item, x * WIDTH, y * HEIGHT);
	else if (id == '1')
	{
		select_wall_1(game, x, y);
		select_wall_2(game, x, y);
	}
	else if (id == '0')
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->floor, x * WIDTH, y * HEIGHT);
	else if (id == 'T')
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->top, x * WIDTH, y * HEIGHT);
	else if (id == 'F')
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->open, x * WIDTH, y * HEIGHT);
}

static void	select_trap(t_game *game, int x, int y)
{
	if (!game)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	if ((game->player->y == (y - 1) && game->player->x == x)
		|| (game->player->y == (y + 1) && game->player->x == x)
		|| (game->player->y == y && game->player->x == (x - 1))
		|| (game->player->y == y && game->player->x == (x + 1)))
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->trap_2, x * WIDTH, y * HEIGHT);
	else
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->trap_1, x * WIDTH, y * HEIGHT);
}

void	render_map(t_game *game)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < game->map->row)
	{
		x = 0;
		while (x < game->map->col)
		{
			if (game->map->matrix[y][x] == 'B')
				select_trap(game, x, y);
			else
				set_put_img_to_window(game, game->map->matrix[y][x], x, y);
			x++;
		}
		y++;
	}
	mlx_string_put(game->mlx, game->window->new,
		0 * WIDTH, game->map->row * HEIGHT, COLOR, "Movements: ");
}
