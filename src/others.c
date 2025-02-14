/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:47:37 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/14 00:47:59 by vgoyzuet         ###   ########.fr       */
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
