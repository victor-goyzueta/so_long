/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:14:51 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/03/03 18:52:14 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	set_map(t_game *game)
{
	if (!game || !game->map)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	game->map->matrix = NULL;
	game->map->path = NULL;
	game->map->start = NULL;
	game->map->end = NULL;
	game->map->row = 0;
	game->map->col = 0;
	game->map->count_collec = 0;
	game->map->count_trap = 0;
}

void	free_map(t_game *game)
{
	if (!game->map)
		return ;
	if (game->map->matrix)
		free_array(game->map->matrix);
	if (game->map->path)
		free(game->map->path);
	if (game->map->start)
	{
		set_pos(game->map->start);
		free(game->map->start);
	}
	if (game->map->end)
	{
		set_pos(game->map->end);
		free(game->map->end);
	}
	set_map(game);
	free(game->map);
}

void	free_texture_1(t_game *game)
{
	if (!game->texture)
		return ;
	if (game->texture->wall_cc)
		mlx_destroy_image(game->mlx, game->texture->wall_cc);
	if (game->texture->wall_cl)
		mlx_destroy_image(game->mlx, game->texture->wall_cl);
	if (game->texture->wall_cr)
		mlx_destroy_image(game->mlx, game->texture->wall_cr);
	if (game->texture->wall_dc)
		mlx_destroy_image(game->mlx, game->texture->wall_dc);
	if (game->texture->wall_dl)
		mlx_destroy_image(game->mlx, game->texture->wall_dl);
	if (game->texture->wall_dr)
		mlx_destroy_image(game->mlx, game->texture->wall_dr);
	if (game->texture->wall_uc)
		mlx_destroy_image(game->mlx, game->texture->wall_uc);
	if (game->texture->wall_ul)
		mlx_destroy_image(game->mlx, game->texture->wall_ul);
	if (game->texture->wall_ur)
		mlx_destroy_image(game->mlx, game->texture->wall_ur);
}

void	free_texture_2(t_game *game)
{
	if (!game->texture)
		return ;
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
	if (game->texture->trap_1)
		mlx_destroy_image(game->mlx, game->texture->trap_1);
	if (game->texture->trap_2)
		mlx_destroy_image(game->mlx, game->texture->trap_2);
	set_texture(game);
	free(game->texture);
}

void	free_window(t_game *game)
{
	if (!game->window)
		return ;
	if (game->mlx && game->window->new)
	{
		mlx_clear_window(game->mlx, game->window->new);
		mlx_destroy_window(game->mlx, game->window->new);
	}
	set_window(game);
	free(game->window);
}
