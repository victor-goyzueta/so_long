/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:47 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/19 23:12:16 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_texture(t_texture *texture, char **current)
{
	if (!texture)
		ft_perror(FAIL_ALLOC);
	texture->player = NULL;
	texture->close = NULL;
	texture->item = NULL;
	texture->wall = NULL;
	texture->floor = NULL;
	texture->open = NULL;
	texture->top = NULL;
	*current = ft_strdup("");
	if (!*current)
		ft_perror(FAIL_ALLOC);
}

static void	set_current(char *path, char *texture, char **current)
{
	if (*current)
		free(*current);
	*current = NULL;
	if (!path || !*path || !texture || !*texture)
		ft_perror(FAIL_ALLOC);
	*current = so_strjoin(path, texture);
	if (!*current)
		ft_perror(FAIL_ALLOC);
}

void	load_object(t_game *game)
{
	char	*cur;

	cur = NULL;
	if (!game || !game->texture)
		ft_perror(FAIL_ALLOC);
	set_texture(game->texture, &cur);
	set_current(PATH_TEXT, "player.xpm", &cur);
	game->texture->player = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->size), &(game->window->size));
	set_current(PATH_TEXT, "close.xpm", &cur);
	game->texture->close = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->size), &(game->window->size));
	set_current(PATH_TEXT, "item.xpm", &cur);
	game->texture->item = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->size), &(game->window->size));
	set_current(PATH_TEXT, "wall.xpm", &cur);
	game->texture->wall = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->size), &(game->window->size));
	set_current(PATH_TEXT, "floor.xpm", &cur);
	game->texture->floor = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->size), &(game->window->size));
	set_current(PATH_TEXT, "open.xpm", &cur);
	game->texture->open = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->size), &(game->window->size));
	set_current(PATH_TEXT, "top.xpm", &cur);
	game->texture->top = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->size), &(game->window->size));
	free(cur);
}

static void	set_put_img_to_window(t_game *game, char id, int x, int y)
{
	if (!game)
		ft_perror(FAIL_ALLOC);
	if (id == 'P')
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->player, x * SIZE, y * SIZE);
	else if (id == 'E')
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->close, x * SIZE, y * SIZE);
	else if (id == 'C')
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->item, x * SIZE, y * SIZE);
	else if (id == '1')
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->wall, x * SIZE, y * SIZE);
	else if (id == '0')
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->floor, x * SIZE, y * SIZE);
	else if (id == 'T')
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->top, x * SIZE, y * SIZE);
	else if (id == 'F')
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->open, x * SIZE, y * SIZE);
}

void	render_map(t_game *game)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < game->map->row)
	{
		x = 0;
		while (x < game->map->col)
		{
			set_put_img_to_window(game, game->map->matrix[y][x], x, y);
			x++;
		}
		y++;
	}
}
