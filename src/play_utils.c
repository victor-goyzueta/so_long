/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:29:04 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/19 23:40:02 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_progress(t_game **game)
{
	int x;
	int y;

	x = 0;
	y = 0;
	x = (*game)->map->end->x;
	y = (*game)->map->end->y;
	(*game)->map->count_collec--;
	ft_printf("%u\n", (*game)->map->count_collec);
	if ((*game)->map->count_collec == 0)
		(*game)->map->matrix[y][x] = 'F'; //exit avaliable
}

// static void	new_render_map(t_game *game, int x, int y)
// {
// 	if (!game)
// 		ft_perror(FAIL_ALLOC);
// 	if (game->map->matrix[y][x] == 'P')
// 		mlx_put_image_to_window(game->mlx, game->window->new,
// 			game->texture->player, x * SIZE, y * SIZE);
// 	else if (game->map->matrix[y][x] == '0')
// 		mlx_put_image_to_window(game->mlx, game->window->new,
// 			game->texture->floor, x * SIZE, y * SIZE);
// 	else if (game->map->matrix[y][x] == 'E')
// 		mlx_put_image_to_window(game->mlx, game->window->new,
// 			game->texture->close, x * SIZE, y * SIZE);
// 	else if (game->map->matrix[y][x] == 'T')
// 		mlx_put_image_to_window(game->mlx, game->window->new,
// 			game->texture->top, x * SIZE, y * SIZE);
// 	else if (game->map->matrix[y][x] == 'F')
// 		mlx_put_image_to_window(game->mlx, game->window->new,
// 			game->texture->open, x * SIZE, y * SIZE);
// }

static void move_player(t_game *game, int col, int row)
{
	int	x;
	int	y;
	int	new_x;
	int new_y;

	x = game->player->player->x;
	y = game->player->player->y;
	new_x = abs(x + col);
	new_y = abs(y + row);
	if (game->map->matrix[new_y][new_x] == '1')
		return ;
	else if (game->map->matrix[new_y][new_x] == 'F')
		free_exit(EXIT_SUCCESS);
	else if (game->map->matrix[new_y][new_x] == 'C')
		set_progress(&game);
	if (game->map->matrix[y][x] == 'T')
		game->map->matrix[y][x] =  'E';
	else
		game->map->matrix[y][x] = '0';
	if (game->map->matrix[new_y][new_x] ==  'E')
		game->map->matrix[new_y][new_x] = 'T'; //player on top of exit
	else
		game->map->matrix[new_y][new_x] = 'P';
	game->player->player->x = new_x;
	game->player->player->y = new_y;
	render_map(game);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC)
		free_exit(EXIT_FAILURE);
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
