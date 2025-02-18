/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:25:25 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/18 19:09:59 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	allocate_mem(t_game *game)
{
	if (!game)
		ft_perror(FAIL_ALLOC);
	game->mlx = NULL;
	game->map = NULL;
	game->window = NULL;
	game->map = ft_calloc(1, sizeof(t_map));
	if (!game->map)
		ft_perror(FAIL_ALLOC);
	game->window = ft_calloc(1, sizeof(t_window));
	if (!game->window)
		ft_perror(FAIL_ALLOC);
}
