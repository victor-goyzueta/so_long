/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:28:21 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/28 21:21:06 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_pos(t_pos *object)
{
	if (!object)
		return ;
	object->count = 0;
	object->x = 0;
	object->y = 0;
}

void	set_window(t_game *game)
{
	if (!game || !game->window)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	game->window->new = NULL;
	game->window->width = 0;
	game->window->height = 0;
	game->window->width = WIDTH;
	game->window->height = HEIGHT;
}

void	set_texture(t_game *game)
{
	if (!game || !game->texture)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	game->texture->player = NULL;
	game->texture->close = NULL;
	game->texture->item = NULL;
	game->texture->floor = NULL;
	game->texture->open = NULL;
	game->texture->top = NULL;
	game->texture->enemy = NULL;
	game->texture->wall_cc = NULL;
	game->texture->wall_cl = NULL;
	game->texture->wall_cr = NULL;
	game->texture->wall_dc = NULL;
	game->texture->wall_dl = NULL;
	game->texture->wall_dr = NULL;
	game->texture->wall_uc = NULL;
	game->texture->wall_ul = NULL;
	game->texture->wall_ur = NULL;
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

void	set_enemy(t_game *game, t_enemy **enemy, int x, int y)
{
	unsigned int	cur;
	t_enemy			*new_enemy;

	cur = 1;
	if (!enemy)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	game->map->count_enemy++;
	new_enemy = ft_calloc(1, sizeof(t_enemy *));
	if (!new_enemy)
		free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
	new_enemy->x = 0;
	new_enemy->y = 0;
	new_enemy->next = NULL;
	while (cur < game->map->count_enemy)
	{
		new_enemy = (*enemy)->next;
		cur++;
	}
	new_enemy->x = x;
	new_enemy->y = y;
}

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
