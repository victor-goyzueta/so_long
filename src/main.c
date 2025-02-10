/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:07:54 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/10 21:19:26 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map_format(char *format)
{
	int	len;

	len = 0;
	if (!format || !*format)
		exit(EXIT_FAILURE);
	len = ft_strlen;
	if (ft_strncmp(format, ".ber", 4) != 0)
		exit(EXIT_FAILURE);
}

void	validate_arguments(int argc, char **argv)
{
	if (argc != 2)
		exit(EXIT_FAILURE);
	check_map_format(argv[1]);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;	
	validate_arguments(argc, argv);
	init(game);
}