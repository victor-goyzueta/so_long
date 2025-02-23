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

/*same function for all other objects*/
void	load_object(t_game *game)
{
	char	*cur;

	cur = NULL;
	if (!game || !game->texture)
		ft_perror(FAIL_ALLOC);
	set_texture(game, &cur);
	set_current(game, PATH_TEXT, "player.xpm", &cur);
	game->texture->player = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->width), &(game->window->height));
	set_current(game, PATH_TEXT, "close.xpm", &cur);
	game->texture->close = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->width), &(game->window->height));
	set_current(game, PATH_TEXT, "item.xpm", &cur);
	game->texture->item = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->width), &(game->window->height));
	set_current(game, PATH_TEXT, "wall.xpm", &cur);
	game->texture->wall = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->width), &(game->window->height));
	set_current(game, PATH_TEXT, "floor.xpm", &cur);
	game->texture->floor = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->width), &(game->window->height));
	set_current(game, PATH_TEXT, "open.xpm", &cur);
	game->texture->open = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->width), &(game->window->height));
	set_current(game, PATH_TEXT, "top.xpm", &cur);
	game->texture->top = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->width), &(game->window->height));
	free(cur);
}

/*same function for all other textures*/
static void	set_put_img_to_window(t_game *game, char id, int x, int y)
{
	if (!game)
		ft_perror(FAIL_ALLOC);
	if (id == 'P')
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->player, x * WIDTH, y * HEIGHT);
	else if (id == 'E')
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->close, x * WIDTH, y * HEIGHT);
	else if (id == 'C')
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->item, x * WIDTH, y * HEIGHT);
	else if (id == '1')
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->wall, x * WIDTH, y * HEIGHT);
	else if (id == '0')
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->floor, x * WIDTH, y * HEIGHT);
	else if (id == 'T')
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->top, x * WIDTH, y * HEIGHT);
	else if (id == 'F')
		mlx_put_image_to_window(game->mlx, game->window->new,
			game->texture->open, x * WIDTH, y * HEIGHT);
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
