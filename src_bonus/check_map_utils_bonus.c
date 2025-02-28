/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:42:04 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/28 21:08:43 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_map_format(char *file, t_game *game)
{
	size_t	len;

	len = 0;
	if (!game)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	if (!file || !*file)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	len = ft_strlen(file);
	if (ft_strncmp(file + (len - 4), ".ber", 4) != 0
		|| file[len - 5] == '/' || len < 5)
		free_exit(EXIT_FAILURE, game, USAGE, NULL);
	game->map->path = NULL;
	game->map->path = ft_strdup(PATH_MAP);
	if (!game->map->path)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	game->map->path = ft_strjoin(game->map->path, file);
	if (!game->map->path)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
}

void	check_map_rectangular(t_game *game)
{
	int		i;
	size_t	current;
	size_t	compared;

	if (!game)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	i = 0;
	current = ft_strlen(game->map->matrix[i]);
	while (game->map->matrix[++i])
	{
		compared = ft_strlen(game->map->matrix[i]);
		if (current != compared)
			free_exit(EXIT_FAILURE, game, FAIL_RECT, NULL);
	}
	if (i < 3)
		free_exit(EXIT_FAILURE, game, FAIL_PLAY, NULL);
}

void	check_map_walls(t_game *game)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	if (!game)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	game->map->col = ft_strlen(game->map->matrix[y]);
	while (game->map->matrix[game->map->row])
		game->map->row++;
	while (x < game->map->col)
	{
		if (game->map->matrix[y][x] != '1' ||
			game->map->matrix[game->map->row - 1][x] != '1')
			free_exit(EXIT_FAILURE, game, FAIL_WALLS, NULL);
		x++;
	}
	x = 0;
	while (y < game->map->row)
	{
		if (game->map->matrix[y][x] != '1' ||
			game->map->matrix[y][game->map->col - 1] != '1')
			free_exit(EXIT_FAILURE, game, FAIL_WALLS, NULL);
		y++;
	}
}

void	check_map_composition(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->matrix[y])
	{
		x = 0;
		while (game->map->matrix[y][x] && game->map->matrix[y][x] != '\n')
		{
			if (game->map->matrix[y][x] == 'C')
				game->map->count_collec += 1;
			else if (game->map->matrix[y][x] == 'P')
				set_object(game, game->map->start, x, y);
			else if (game->map->matrix[y][x] == 'E')
				set_object(game, game->map->end, x, y);
			else if (game->map->matrix[y][x] == 'B')
				set_enemy(game, game->map->enemy, x, y);
			else if (game->map->matrix[y][x] != '1' &&
				game->map->matrix[y][x] != '0' && game->map->matrix[y][x] != 'B')
				free_exit(EXIT_FAILURE, game, FAIL_COMP, NULL);
			x++;
		}
		y++;
	}
	if (game->map->count_collec < 1
		|| game->map->start->count != 1 || game->map->end->count != 1)
		free_exit(EXIT_FAILURE, game, FAIL_COMP, NULL);
}

void	check_map_playable(t_game *game)
{
	int				i;
	char			**cpy;
	unsigned char	count;

	cpy = NULL;
	cpy = ft_calloc(game->map->row + 1, sizeof(char *));
	if (!cpy)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, cpy);
	count = 0;
	count = game->map->count_collec;
	i = 0;
	while (game->map->matrix[i])
	{
		cpy[i] = ft_strdup(game->map->matrix[i]);
		if (!cpy[i])
			free_exit(EXIT_FAILURE, game, FAIL_ALLOC, cpy);
		i++;
	}
	cpy[i] = NULL;
	flood_fill(game, cpy, game->map->start->x, game->map->start->y);
	if (game->map->count_collec != 0 || game->map->end->count != 0)
		free_exit(EXIT_FAILURE, game, FAIL_PLAY, cpy);
	game->map->count_collec = count;
	game->map->end->count = 1;
	free_array(cpy);
}
