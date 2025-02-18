/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:44:38 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/18 22:00:11 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_texture(t_texture *texture, char *current)
{
	if (!texture)
		ft_perror(FAIL_ALLOC);
	texture->player = NULL;
	texture->exit = NULL;
	texture->item = NULL;
	texture->wall = NULL;
	texture->floor = NULL;
	current = ft_strdup("");
	if (!current)
		ft_perror(FAIL_ALLOC);
}

static void	set_current(char *path, char *texture, char *current)
{
	if (current)
		free(current);
	current = NULL;
	if (!path || !*path || !texture || !*texture)
		ft_perror(FAIL_ALLOC);
	current = so_strjoin(path, texture);
	if (!current)
		ft_perror(FAIL_ALLOC);
}

void	load_object(t_game *game)
{
	char	*cur;
	int		size;

	cur = NULL;
	size = 64;
	if (!game || !game->texture)
		ft_perror(FAIL_ALLOC);
	set_texture(game->texture, cur);
	set_current(PATH_TEXT, "player.xpm", cur);
	game->texture->player = mlx_xpm_file_to_image(game->mlx, cur, &size, &size);
	set_current(PATH_TEXT, "exit.xpm", cur);
	game->texture->exit = mlx_xpm_file_to_image(game->mlx, cur, &size, &size);
	set_current(PATH_TEXT, "item.xpm", cur);
	game->texture->exit = mlx_xpm_file_to_image(game->mlx, cur, &size, &size);
	set_current(PATH_TEXT, "wall.xpm", cur);
	game->texture->exit = mlx_xpm_file_to_image(game->mlx, cur, &size, &size);
	set_current(PATH_TEXT, "floor.xpm", cur);
	game->texture->exit = mlx_xpm_file_to_image(game->mlx, cur, &size, &size);
	set_current(PATH_TEXT, "floor.xpm", cur);
	game->texture->exit = mlx_xpm_file_to_image(game->mlx, cur, &size, &size);
	/*Avaliable to load 4 texture more*/
	free(cur);
}
