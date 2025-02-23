/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:25:25 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/19 23:03:24 by vgoyzuet         ###   ########.fr       */
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

/*free map->start*/
void	allocate_player(t_game *game)
{
	if (!game)
		ft_perror(FAIL_ALLOC);
	game->player->count = 0;
	game->player->x = 0;
	game->player->y = 0;
	game->player->x = game->map->start->x;
	game->player->y = game->map->start->y;
}

void	allocate_struct(t_game **game)
{
	if (!game)
		ft_perror(FAIL_ALLOC);
	*game = NULL;
	*game = ft_calloc(1, sizeof(t_game));
	if (!*game)
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
	(*game)->player = ft_calloc(1, sizeof(t_pos));
	if (!(*game)->player)
		ft_perror(FAIL_ALLOC);
	(*game)->texture = ft_calloc(1, sizeof(t_texture));
	if (!(*game)->texture)
		ft_perror(FAIL_ALLOC);
}
