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

void	allocate_matrix(t_game *game, int *fd)
{
	char	*line;
	char	*add;

	*fd = open(game->map->path, O_RDONLY);
	if (*fd < 0)
		ft_perror("Failed to open fd");
	line = ft_strdup("");
	if (!line)
		ft_perror(FAIL_ALLOC);
	add = get_next_line(*fd);
	if (!add)
		ft_perror(FAIL_ALLOC);
	while (add)
	{
		line = ft_strjoin(line, add);
		if (!line)
			ft_perror(FAIL_ALLOC);
		free(add);
		add = get_next_line(*fd);
	}
	game->map->matrix = ft_split(line, '\n');
	if (!game->map->matrix)
		ft_perror(FAIL_ALLOC);
	free_arrays(3, game->map->path, line, add);
	close(*fd);
}

void	allocate_object(t_game *game)
{
	game->map->start = NULL;
	game->map->end = NULL;
	game->map->start = ft_calloc(1, sizeof(t_pos));
	if (!game->map->start)
		ft_perror(FAIL_ALLOC);
	game->map->end = ft_calloc(1, sizeof(t_pos));
	if (!game->map->end)
		ft_perror(FAIL_ALLOC);
	game->map->count_collec = 0;
	game->map->start->count = 0;
	game->map->end->count = 0;
}

void	allocate_map(t_game *game)
{
	int	fd;

	allocate_matrix(game, &fd);
	allocate_object(game);
}

/*add t_game *game to free*/
void	set_object(t_game *game, t_pos *object, int x, int y)
{
	(void)game; //use in case FAIL
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
