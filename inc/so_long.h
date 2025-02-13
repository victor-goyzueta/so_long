/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:13:31 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/13 06:16:53 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
//# include <mlx.h>
# include <math.h>

# define USAGE "Usage: ./so_long [name_map.ber]"
# define PATH "assets/maps/"
# define FAIL_ALLOC "Failed memory allocation"

// typedef struct s_player
// {
// 	/*data*/
// }	t_player;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	char			**matrix;
	char			*path;
	unsigned int	row;
	unsigned int	col;
	unsigned int	collec;
	unsigned int	count_end;
	unsigned int	count_start;
	t_pos			*end;
	t_pos			*start;
}	t_map;

// typedef struct s_game
// {
// 	t_player	*player;
// 	t_map		*map;
// }	t_game;

void	validate_arguments(int argc, char **argv);
void	check_map(char *file);
/*allocate mem*/
void	allocate_map(t_map *map);

#endif
