/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:47:37 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/18 02:10:41 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_map *map)
{
	int	i = 0;
	printf("\n--- MAPA CARGADO ---\n");
	while (map->matrix[i])
	{
		printf("%s\n", map->matrix[i]);
		i++;
	}
	printf("---------------------\n");
}

void	print_objects(t_map *map)
{
	ft_printf("Collectables: %u\n", (unsigned int)map->count_collec);
	ft_printf("Player[%i][%i]: %u\n", (int)map->start->y, (int)map->start->x, (unsigned int)map->start->count);
	ft_printf("Exit[%i][%i]: %u\n", (int)map->end->y, (int)map->end->x, (unsigned int)map->end->count);
}
