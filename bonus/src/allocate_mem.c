/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:25:25 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/27 18:00:41 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_matrix(t_game *game, char *line, int *fd)
{
	int		i;
	int		count;

	i = 0;
	while (line[i])
	{
		count = 0;
		while (line[i + count] && line[i + count] == '\n')
			count++;
		if (count > 1 && line[i + count] != '\0')
		{
			free(line);
			fd_free_exit(*fd, game, FAIL_COMP, NULL);
		}
		i++;
	}
	game->map->matrix = ft_split(line, '\n');
	if (!game->map->matrix)
	{
		free(line);
		fd_free_exit(*fd, game, FAIL_ALLOC, NULL);
	}
	free(line);
}

void	allocate_matrix(t_game *game, int *fd)
{
	char	*line;
	char	*add;

	*fd = open(game->map->path, O_RDONLY);
	if (*fd < 0)
		free_exit(EXIT_FAILURE, game, FAIL_FD, NULL);
	line = ft_strdup("");
	if (!line)
		fd_free_exit(*fd, game, FAIL_ALLOC, NULL);
	add = get_next_line(*fd);
	if (!add)
		fd_free_exit(*fd, game, FAIL_ALLOC, &line);
	while (add)
	{
		line = ft_strjoin(line, add);
		if (!line)
			fd_free_exit(*fd, game, FAIL_ALLOC, &add);
		free(add);
		add = get_next_line(*fd);
	}
	check_matrix(game, line, fd);
	if (!game->map->matrix)
		fd_free_exit(*fd, game, FAIL_ALLOC, NULL);
	close(*fd);
}

void	allocate_object(t_game *game)
{
	game->map->start = NULL;
	game->map->end = NULL;
	game->map->start = ft_calloc(1, sizeof(t_pos));
	if (!game->map->start)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	game->map->end = ft_calloc(1, sizeof(t_pos));
	if (!game->map->end)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	game->map->row = 0;
	game->map->col = 0;
	game->map->count_collec = 0;
	set_pos(game->map->start);
	set_pos(game->map->end);
}

void	allocate_player(t_game *game)
{
	if (!game)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
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
		free_exit(EXIT_FAILURE, *game, FAIL_ALLOC, NULL);
	(*game)->window = ft_calloc(1, sizeof(t_window));
	if (!(*game)->window)
		free_exit(EXIT_FAILURE, *game, FAIL_ALLOC, NULL);
	(*game)->player = ft_calloc(1, sizeof(t_pos));
	if (!(*game)->player)
		free_exit(EXIT_FAILURE, *game, FAIL_ALLOC, NULL);
	(*game)->texture = ft_calloc(1, sizeof(t_texture));
	if (!(*game)->texture)
		free_exit(EXIT_FAILURE, *game, FAIL_ALLOC, NULL);
}
