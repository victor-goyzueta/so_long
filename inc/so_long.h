/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:13:31 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/18 21:41:51 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <math.h>

# define USAGE "Usage: ./so_long [name_map.ber]"
# define PATH_MAP "assets/maps/"
# define PATH_TEXT "assets/textures"
# define FAIL_ALLOC "Failed memory allocation"
# define FAIL_COMP "The composition of the map is incorrect"

# define LOOP_MAX 4242
# define SIZE 64

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

typedef struct s_window
{
	void	*new;
	int		size;
}	t_window;

typedef struct s_player
{
	void	*player;
}	t_player;

typedef struct s_texture
{
	void	*wall;
	void	*floor;
	void	*item;
	void	*player;
	void	*exit;
}	t_texture;

typedef struct s_game
{
	void		*mlx;
	t_map		*map;
	t_window	*window;
	t_player	*player;
	t_texture	*texture;
}	t_game;

void	init_mlx(t_game *game);
/*check_map*/
void	check_map(int argc, char *file, t_game *game);
void	check_map_format(char *file, t_map *map);
void	check_map_rectangular(t_map *map);
void	check_map_walls(t_map *map);
void	check_map_composition(t_map *map);
void	check_map_playable(t_map *map);
/*check_map_utils*/
void	set_object(t_pos *object, int x, int y);
void	flood_fill(t_map *map, char **cpy, unsigned int x, unsigned int y);
/*allocate_mem*/
void	allocate_mem(t_game *game);
void	allocate_map(t_map *map);
void	allocate_matrix(t_map *map, int *fd);
void	allocate_object(t_map *map);
void	load_object(t_game *game);
/*others*/
void	print_map(t_map *map);
void	print_objects(t_map *map);

#endif
