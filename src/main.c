/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:07:54 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/11 18:54:22 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_arguments(int argc, char **argv)
{
	if (argc != 2)
		exit(EXIT_FAILURE);
	check_map(argv[1]);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;	
	validate_arguments(argc, argv);
	init(game);
}
