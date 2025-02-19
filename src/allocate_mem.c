/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:25:25 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/19 17:44:12 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	allocate_mem(t_game **game)
{
	if (!game)
		ft_perror(FAIL_ALLOC);
	*game = NULL;
	*game = ft_calloc(1, sizeof(t_game));
	if (!game)
		ft_perror(FAIL_ALLOC);
	(*game)->mlx = NULL;
	(*game)->map = NULL;
	(*game)->window = NULL;
	(*game)->player = NULL;
	(*game)->texture = NULL;
	(*game)->map = ft_calloc(1, sizeof(t_map));
	if (!(*game)->map)
		ft_perror(FAIL_ALLOC);
	(*game)->window = ft_calloc(1, sizeof(t_window));
	if (!(*game)->window)
		ft_perror(FAIL_ALLOC);
	(*game)->player = ft_calloc(1, sizeof(t_player));
	if (!(*game)->player)
		ft_perror(FAIL_ALLOC);
	(*game)->texture = ft_calloc(1, sizeof(t_texture));
	if (!(*game)->texture)
		ft_perror(FAIL_ALLOC);
}
