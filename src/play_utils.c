/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:29:04 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/27 14:45:39 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_progress(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	x = game->map->end->x;
	y = game->map->end->y;
	game->map->count_collec--;
	if (game->map->count_collec == 0)
		game->map->matrix[y][x] = 'F';
}

static void	update_render_pos(t_game *game, int x, int y)
{
	if (!game)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	game->player->count++;
	ft_printf("Movements: %u\n", game->player->count);
	if (game->map->matrix[game->map->end->y][game->map->end->x] == 'F')
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->open,
			game->map->end->x * WIDTH, game->map->end->y * HEIGHT);
	if (game->map->matrix[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->floor, x * WIDTH, y * HEIGHT);
	else if (game->map->matrix[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->close, x * WIDTH, y * HEIGHT);
	else if (game->map->matrix[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->player, x * WIDTH, y * HEIGHT);
	else if (game->map->matrix[y][x] == 'T')
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->top, x * WIDTH, y * HEIGHT);
	if (game->player->x == x && game->player->y == y)
		return ;
	game->player->x = x;
	game->player->y = y;
}

static void	move_player(t_game *game, int col, int row)
{
	int	x;
	int	y;
	int	new_x;
	int	new_y;

	x = game->player->x;
	y = game->player->y;
	new_x = ft_abs(x + col);
	new_y = ft_abs(y + row);
	if (game->map->matrix[new_y][new_x] == '1')
		return ;
	else if (game->map->matrix[new_y][new_x] == 'F')
		free_exit(EXIT_SUCCESS, game, FAIL_ALLOC, NULL);
	else if (game->map->matrix[new_y][new_x] == 'C')
		update_progress(game);
	if (game->map->matrix[y][x] == 'T')
		game->map->matrix[y][x] = 'E';
	else
		game->map->matrix[y][x] = '0';
	if (game->map->matrix[new_y][new_x] == 'E')
		game->map->matrix[new_y][new_x] = 'T';
	else
		game->map->matrix[new_y][new_x] = 'P';
	update_render_pos(game, x, y);
	update_render_pos(game, new_x, new_y);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC || keycode == Q)
		free_exit(EXIT_SUCCESS, game, CLOSE_WIN, NULL);
	else if (keycode == UP || keycode == W)
		move_player(game, 0, -1);
	else if (keycode == LEFT || keycode == A)
		move_player(game, -1, 0);
	else if (keycode == DOWN || keycode == S)
		move_player(game, 0, 1);
	else if (keycode == RIGHT || keycode == D)
		move_player(game, 1, 0);
	return (0);
}

int	handle_exit(t_game *game)
{
	free_exit(EXIT_SUCCESS, game, CLOSE_WIN, NULL);
	return (0);
}
