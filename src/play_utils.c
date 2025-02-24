/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:29:04 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/24 00:29:35 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_progress(t_game *game)
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

static void	set_player_pos(t_game *game, int new_x, int new_y)
{
	if (!game || !game->player)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	game->player->count++;
	ft_printf("Movements: %u\n", game->player->count);
	game->player->x = new_x;
	game->player->y = new_y;
}

static void	move_player(t_game *game, int col, int row)
{
	int	x;
	int	y;
	int	new_x;
	int	new_y;

	x = game->player->x;
	y = game->player->y;
	new_x = abs(x + col);
	new_y = abs(y + row);
	if (game->map->matrix[new_y][new_x] == '1')
		return ;
	else if (game->map->matrix[new_y][new_x] == 'F')
		free_exit(EXIT_SUCCESS, game, FAIL_ALLOC, NULL);
	else if (game->map->matrix[new_y][new_x] == 'C')
		set_progress(game);
	if (game->map->matrix[y][x] == 'T')
		game->map->matrix[y][x] = 'E';
	else
		game->map->matrix[y][x] = '0';
	if (game->map->matrix[new_y][new_x] == 'E')
		game->map->matrix[new_y][new_x] = 'T';
	else
		game->map->matrix[new_y][new_x] = 'P';
	set_player_pos(game, new_x, new_y);
	render_map(game);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC)
		free_exit(EXIT_FAILURE, game, NULL, NULL);
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
