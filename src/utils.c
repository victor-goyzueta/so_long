/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:12:46 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/23 23:45:19 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*add t_game *game to free*/
void	set_object(t_game *game, t_pos *object, int x, int y)
{
	(void)game;
	if (!object)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	if (object->count != 0)
		free_exit(EXIT_FAILURE, game, FAIL_COMP, NULL);
	object->count = 1;
	object->x = x;
	object->y = y;
}

void	flood_fill(t_game *game, char **cpy, unsigned int x, unsigned int y)
{
	static int	loop;

	loop++;
	if (loop > LOOP_MAX)
		return ;
	if (x >= game->map->col || y >= game->map->row
		|| cpy[y][x] == '1' || cpy[y][x] == 'F')
		return ;
	if (cpy[y][x] == 'C')
		game->map->count_collec--;
	if (cpy[y][x] == 'E')
		game->map->end->count--;
	if (cpy[y][x] != 'P')
		cpy[y][x] = 'F';
	flood_fill(game, cpy, x + 1, y);
	flood_fill(game, cpy, x, y + 1);
	flood_fill(game, cpy, x - 1, y);
	flood_fill(game, cpy, x, y - 1);
}

void	set_texture(t_game *game)
{
	if (!game || !game->texture)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	game->texture->player = NULL;
	game->texture->close = NULL;
	game->texture->item = NULL;
	game->texture->wall = NULL;
	game->texture->floor = NULL;
	game->texture->open = NULL;
	game->texture->top = NULL;
}

void	set_current(t_game *game, char *path, char *texture, char **current)
{
	if (!current || !*current)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	free(*current);
	*current = NULL;
	if (!game || !path || !*path || !texture || !*texture)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	*current = so_strjoin(path, texture);
	if (!*current)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
}

int	free_exit(int EXIT, t_game *game, char *error, char **cur)
{
	free_all(game);
	if (cur)
		free_array(cur);
	if (!*cur)
		free(*cur);
	if (EXIT == EXIT_FAILURE)
		ft_perror(error);
	else if (EXIT == EXIT_SUCCESS)
	{
		ft_printf("Successfully completed");
		exit(EXIT);
	}
	exit(EXIT_FAILURE);
}
