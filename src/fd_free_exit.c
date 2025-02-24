/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_free_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:30:28 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/24 17:30:31 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fd_free_exit(int fd, t_game *game, char *error, char **cur)
{
	close(fd);
	free_exit(EXIT_FAILURE, game, error, cur);
}
