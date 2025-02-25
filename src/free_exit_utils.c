/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:14:51 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/25 21:00:52 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map(t_game *game)
{
	if (!game->map)
		return ;
	if (game->map->matrix)
		free_array(game->map->matrix);
	if (game->map->path)
		free(game->map->path);
	if (game->map->start)
		free(game->map->start);
	if (game->map->end)
		free(game->map->end);
	free(game->map);
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

static void	free_window(t_game *game)
{
	if (!game->window)
		return ;
	if (game->mlx && game->window->new)
	{
		mlx_clear_window(game->mlx, game->window->new);
		mlx_destroy_window(game->mlx, game->window->new);
	}
	game->window->new = NULL;
	free(game->window);
}

void	free_all(t_game *game)
{
	if (!game)
		return ;
	free_map(game);
	if (game->player)
		free(game->player);
	free_texture(game);
	free_window(game);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	game->mlx = NULL;
	free(game);
}

void	fd_free_exit(int fd, t_game *game, char *error, char **cur)
{
	close(fd);
	free_exit(EXIT_FAILURE, game, error, cur);
}
