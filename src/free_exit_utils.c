/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:14:51 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/24 02:06:30 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->matrix)
		free_array(map->matrix);
	if (map->path)
		free(map->path);
	if (map->start)
		free(map->start);
	if (map->end)
		free(map->end);
	free(map);
}

static void	free_player(t_pos *player)
{
	if (!player)
		return ;
	free(player);
}

static void	free_texture(t_game *game)
{
	if (!game->texture)
		return ;
	if (game->texture->wall)
		mlx_destroy_image(game->mlx, game->texture->wall);
	if (game->texture->floor)
		mlx_destroy_image(game->mlx, game->texture->floor);
	if (game->texture->item)
		mlx_destroy_image(game->mlx, game->texture->item);
	if (game->texture->player)
		mlx_destroy_image(game->mlx, game->texture->player);
	if (game->texture->close)
		mlx_destroy_image(game->mlx, game->texture->close);
	if (game->texture->open)
		mlx_destroy_image(game->mlx, game->texture->open);
	if (game->texture->top)
		mlx_destroy_image(game->mlx, game->texture->top);
	set_texture(game);
	free(game->texture);
}

void	free_all(t_game *game)
{
	if (!game)
		return ;
	free_map(game->map);
	free_player(game->player);
	free_texture(game);
	if (game->mlx && game->window->new)
	{
		mlx_clear_window(game->mlx, game->window->new);
		mlx_destroy_window(game->mlx, game->window->new);
	}
	game->window->new = NULL;
	free(game->window);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	game->mlx = NULL;
	free(game);
}
