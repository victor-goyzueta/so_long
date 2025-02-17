/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:13:31 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/17 19:26:56 by vgoyzuet         ###   ########.fr       */
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
	unsigned int	count;
}	t_pos;

typedef struct s_map
{
	char			**matrix;
	char			*path;
	unsigned int	row;
	unsigned int	col;
	unsigned int	count_collec;
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
/*allocate_mem*/
void	allocate_map(t_map *map);
void	allocate_matrix(t_map *map, int *fd);
void	allocate_object(t_map *map);
/*check_map_utils*/
void	set_object(t_pos *object, int x, int y);
void	check_map_playable(t_map *map);
/*other*/
void	print_map(t_map *map);
void	print_objects(t_map *map);

#endif
