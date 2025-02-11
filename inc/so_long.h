/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:13:31 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/11 21:13:43 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <mlx.h>
# include <math.h>

typedef struct s_player
{
	/*data*/
}	t_player;

typedef struct s_map
{
	char	**matrix;
}	t_map;

typedef struct s_game
{
	t_player	*player;
	t_map		*map;
}	t_game;

void	validate_arguments(int argc, char **argv);
void	check_map(char *file);
/*allocate mem*/
void	allocate_map(char *file, t_map *map);

#endif
