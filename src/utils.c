/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:12:46 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/03/03 00:14:41 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *game, char **cpy, unsigned int x, unsigned int y)
{
	static int	loop;

	loop++;
	if (loop > LOOP_MAX)
		free_exit(EXIT_FAILURE, game, FAIL_SIZE, cpy);
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

static void	free_all(t_game *game)
{
	if (!game)
		return ;
	free_map(game);
	if (game->player)
	{
		set_pos(game->player);
		free(game->player);
	}
	free_texture_1(game);
	free_texture_2(game);
	free_window(game);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	game->mlx = NULL;
	free(game);
}

void	free_exit(int EXIT, t_game *game, char *message, char **cur)
{
	if (game->mlx && game->window->new)
		mlx_loop_end(game->window->new);
	free_all(game);
	if (cur)
		free_array(cur);
	if (EXIT == EXIT_SUCCESS)
	{
		if (ft_strncmp(message, CLOSE_WIN, 7) == 0)
			ft_printf("Closed window\n");
		else
			ft_printf("Successfully completed\n");
		exit(EXIT);
	}
	else
		ft_perror(message);
}

void	fd_free_exit(int fd, t_game *game, char *message, char **cur)
{
	close(fd);
	free_exit(EXIT_FAILURE, game, message, cur);
}
