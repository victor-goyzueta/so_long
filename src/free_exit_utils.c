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

static void	free_map(t_game *map)
{
	if (!map)
		return ;
	//
}

static void	free_window(t_window *window)
{
	if (!window)
		return ;
	//
}

static void	free_texture(t_texture *texture)
{
	if (!texture)
		return ;
	//
}

static void	free_player(t_pos *player)
{
	if (!player)
		return ;
	//
}

void	free_all(t_game *game)
{
	if (!game)
		return ;
	free_map(game->map);
	free_window(game->window);
	free_texture(game->texture);
	free_player(game->player);
}
