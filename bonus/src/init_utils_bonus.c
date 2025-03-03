/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:47 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/03/03 16:53:20 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_load_texture(t_game *game)
{
	if (!game->texture->player || !game->texture->close
		|| !game->texture->item || !game->texture->floor
		|| !game->texture->open || !game->texture->top
		|| !game->texture->wall_cc || !game->texture->wall_cl
		|| !game->texture->wall_cr || !game->texture->wall_dc
		|| !game->texture->wall_dl || !game->texture->wall_dr
		|| !game->texture->wall_uc || !game->texture->wall_ul
		|| !game->texture->wall_ur || !game->texture->trap)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
}

void	load_texture_1(t_game *game)
{
	char	*cur;

	if (!game)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	cur = NULL;
	cur = ft_strdup("");
	if (!cur)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	set_current(game, PATH_TEXT, "player.xpm", &cur);
	game->texture->player = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->width), &(game->window->height));
	set_current(game, PATH_TEXT, "close.xpm", &cur);
	game->texture->close = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->width), &(game->window->height));
	set_current(game, PATH_TEXT, "item.xpm", &cur);
	game->texture->item = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->width), &(game->window->height));
	set_current(game, PATH_TEXT, "wall_cc.xpm", &cur);
	game->texture->wall_cc = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->width), &(game->window->height));
	set_current(game, PATH_TEXT, "floor.xpm", &cur);
	game->texture->floor = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->width), &(game->window->height));
	free(cur);
}

void	load_texture_2(t_game *game)
{
	char	*cur;

	if (!game)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	cur = NULL;
	cur = ft_strdup("");
	if (!cur)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	set_current(game, PATH_TEXT, "open.xpm", &cur);
	game->texture->open = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->width), &(game->window->height));
	set_current(game, PATH_TEXT, "top.xpm", &cur);
	game->texture->top = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->width), &(game->window->height));
	set_current(game, PATH_TEXT, "wall_cl.xpm", &cur);
	game->texture->wall_cl = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->width), &(game->window->height));
	set_current(game, PATH_TEXT, "wall_cr.xpm", &cur);
	game->texture->wall_cr = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->width), &(game->window->height));
	set_current(game, PATH_TEXT, "wall_dc.xpm", &cur);
	game->texture->wall_dc = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->width), &(game->window->height));
	free(cur);
}

void	load_texture_3(t_game *game)
{
	char	*cur;

	if (!game)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	cur = NULL;
	cur = ft_strdup("");
	if (!cur)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	set_current(game, PATH_TEXT, "wall_dl.xpm", &cur);
	game->texture->wall_dl = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->width), &(game->window->height));
	set_current(game, PATH_TEXT, "wall_dr.xpm", &cur);
	game->texture->wall_dr = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->width), &(game->window->height));
	set_current(game, PATH_TEXT, "wall_uc.xpm", &cur);
	game->texture->wall_uc = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->width), &(game->window->height));
	set_current(game, PATH_TEXT, "wall_ul.xpm", &cur);
	game->texture->wall_ul = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->width), &(game->window->height));
	set_current(game, PATH_TEXT, "wall_ur.xpm", &cur);
	game->texture->wall_ur = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->width), &(game->window->height));
	free(cur);
}

void	load_texture_4(t_game *game)
{
	char	*cur;

	if (!game)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	cur = NULL;
	cur = ft_strdup("");
	if (!cur)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	set_current(game, PATH_TEXT, "trap.xpm", &cur);
	game->texture->trap = mlx_xpm_file_to_image(game->mlx, cur,
			&(game->window->width), &(game->window->height));
	free(cur);
}
