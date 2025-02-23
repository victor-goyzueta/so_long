/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:12:46 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/18 19:52:57 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*add t_game *game to free*/
void	set_object(t_game *game, t_pos *object, int x, int y)
{
	(void)game;
	if (!object)
		ft_perror(FAIL_ALLOC);
	if (object->count != 0)
		ft_perror(FAIL_COMP);
	object->count = 1;
	object->x = x;
	object->y = y;
}

void	flood_fill(t_game *game, char **cpy, unsigned int x, unsigned int y)
{
	static int	loop;

	loop++;
	if (loop > LOOP_MAX)
		ft_perror("Map size is too long");
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
		ft_perror(FAIL_ALLOC);
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
		ft_perror(FAIL_ALLOC);
	free(*current);
	*current = NULL;
	if (!game || !path || !*path || !texture || !*texture)
		ft_perror(FAIL_ALLOC);
	*current = so_strjoin(path, texture);
	if (!*current)
		ft_perror(FAIL_ALLOC);
}

int	free_exit(int EXIT, t_game *game, char *error)
{
	free_all(game);
	if (EXIT == EXIT_SUCCESS)
	{
		ft_printf("Victory");
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_perror(error);
		exit(EXIT_FAILURE);
	}
}
