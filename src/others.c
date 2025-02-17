/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:47:37 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/17 21:32:37 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_map *map)
{
	int	y = 0;
	printf("\n--- MAPA CARGADO ---\n");
	while (map->matrix[y])
	{
		printf("%s\n", map->matrix[y]);
		y++;
	}
	printf("---------------------\n");
}

void	print_objects(t_map *map)
{
	ft_printf("Collectables: %u\n", (unsigned int)map->count_collec);
	ft_printf("Player[%i][%i]: %u\n", (int)map->start->y, (int)map->start->x, (unsigned int)map->start->count);
	ft_printf("Exit[%i][%i]: %u\n", (int)map->end->y, (int)map->end->x, (unsigned int)map->end->count);
}
