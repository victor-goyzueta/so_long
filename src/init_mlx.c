/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:47 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/18 17:23:03 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx = NULL;
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_perror(FAIL_ALLOC);
	game->window->new_window = mlx_new_window(game->mlx, 800, 600, "New game");
	if (!game->window->new_window)
		ft_perror(FAIL_ALLOC);
}