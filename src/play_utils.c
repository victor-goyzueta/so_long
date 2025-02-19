/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:29:04 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/19 20:44:32 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_progress(t_game *game)
{
	game->map->count_collec--;
		if (game->map->count_collec == 0)
			game->map->matrix[game->map->end->y][game->map->end->x] = 'F'; //exit avaliable
}

static void move_player(t_game *game, int col, int row)
{
	int	x;
	int	y;
	int	new_x;
	int new_y;

	x = game->player->player->x;
	y = game->player->player->y;
	new_x = game->player->player->x + col;
	new_y = game->player->player->y + row;
	if (game->map->matrix[new_y][new_x] == '1')
		return ;
	else if (game->map->matrix[new_y][new_x] == 'F')
		free_exit(EXIT_SUCCESS);
	else if (game->map->matrix[new_y][new_x] == 'C')
		set_progress(game);
	if (game->map->matrix[y][x] == 'T')
		game->map->matrix[y][x] =  'E';
	else
		game->map->matrix[y][x] = '0';
	if (game->map->matrix[new_y][new_x] ==  'E')
		game->map->matrix[new_y][new_x] = 'T'; //player on top of exit
	else
		game->map->matrix[new_y][new_x] = 'P';
	render_map(game);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC)
		free_exit(EXIT_FAILURE);
	else if (keycode == 'w' || keycode == 'W' || keycode == W)
		move_player(game, 0, -1);
	else if (keycode == 'a' || keycode == 'A' || keycode == A)
		move_player(game, -1, 0);
	else if (keycode == 's' || keycode == 'S' || keycode == S)
		move_player(game, 0, 1);
	else if (keycode == 'd' || keycode == 'D' || keycode == D)
		move_player(game, 1, 0);
	return (0);
}
