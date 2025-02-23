/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:14:51 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/19 18:17:28 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->matrix)
		free(map->matrix);
	if (map->path)
		free(map->path);
	if (map->start)
		free(map->start);
	if (map->end)
		free(map->end);
	free(map);
}

static void	free_window(t_window *window)
{
	if (!window)
		return ;
	if (window->new)
		free(window->new);
	free(window);
}

static void	free_player(t_pos *player)
{
	if (!player)
		return ;
	free(player);
}

static void	free_texture(t_texture *texture)
{
	if (!texture)
		return ;
	if (texture->wall)
		free(texture->wall);
	if (texture->floor)
		free(texture->floor);
	if (texture->item)
		free(texture->item);
	if (texture->player)
		free(texture->player);
	if (texture->close)
		free(texture->close);
	if (texture->open)
		free(texture->open);
	if (texture->top)
		free(texture->top);
	free(texture);
}

void	free_all(t_game *game)
{
	if (!game)
		return ;
	free_map(game->map);
	free_window(game->window);
	free_player(game->player);
	free_texture(game->texture);
	free(game->mlx);
	free(game);
}
