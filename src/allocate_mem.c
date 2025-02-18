/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:25:25 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/18 17:32:22 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	allocate_mem(t_game *game)
{
	t_map		*map;
	t_window	*window;

	map = NULL;
	window = NULL;
	if (!game)
		ft_perror(FAIL_ALLOC);
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		ft_perror(FAIL_ALLOC);
	game->map = map;
	window = ft_calloc(1, sizeof(t_window));
	if (!window)
		ft_perror(FAIL_ALLOC);
	game->window = window;
}
