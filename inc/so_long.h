/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:13:31 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/14 02:44:26 by vgoyzuet         ###   ########.fr       */
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
# define FAIL_COMP "The composition of the map is incorrect"

// typedef struct s_player
// {
// 	/*data*/
// }	t_player;

typedef struct s_pos
{
	int				x;
	int				y;
}	t_pos;

typedef struct s_map
{
	char			**matrix;
	char			*path;
	unsigned int	row;
	unsigned int	col;
	unsigned int	count_collec;
	unsigned int	count_start;
	unsigned int	count_end;
	t_pos			*start;
	t_pos			*end;
}	t_map;

// typedef struct s_game
// {
// 	t_player	*player;
// 	t_map		*map;
// }	t_game;

void	validate_arguments(int argc, char **argv);
void	check_map(char *file);
/*check_map_utils*/
void	allocate_map(t_map *map);
void	set_object(t_map *map, int x, int y, char type);
void	print_map(t_map *map);

#endif
