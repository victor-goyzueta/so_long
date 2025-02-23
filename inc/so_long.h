/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:13:31 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/19 23:12:31 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <math.h>

# define USAGE "Usage: ./so_long [map_name.ber]"
# define PATH_MAP "assets/maps/"
# define PATH_TEXT "assets/textures/"
# define FAIL_ALLOC "Failed memory allocation"
# define FAIL_COMP "The composition of the map is incorrect"

# define LOOP_MAX 4242
# define WIDTH 64
# define HEIGHT 64

# define CLIC_X 17
# define ESC 65307

# define W	119
# define A	97
# define S	115
# define D	100

# define UP		65362
# define LEFT	65361
# define DOWN	65364
# define RIGHT	65363

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
	int		width;
	int		height;
}	t_window;

typedef struct s_player
{
	t_pos	*player;
}	t_player;

typedef struct s_texture
{
	void	*wall;
	void	*floor;
	void	*item;
	void	*player;
	void	*close;
	void	*open;
	void	*top;
}	t_texture;

typedef struct s_game
{
	void		*mlx;
	t_map		*map;
	t_window	*window;
	t_player	*player;
	t_texture	*texture;
}	t_game;

void	init(t_game *game);
void	play(t_game *game);
/*check_map*/
void	check_map(char *file, t_game *game);
void	check_map_format(char *file, t_game *game);
void	check_map_rectangular(t_game *game);
void	check_map_walls(t_game *game);
void	check_map_composition(t_game *game);
void	check_map_playable(t_game *game);
/*check_map_utils*/
void	set_object(t_game *game, t_pos *object, int x, int y);
void	flood_fill(t_game *game, char **cpy, unsigned int x, unsigned int y);
/*init_utils*/
void	load_object(t_game *game);
void	render_map(t_game *game);
/*play_utils*/
int		handle_keypress(int keycode, t_game *game);
/*allocate*/
void	allocate_mem(t_game **game);
void	allocate_map(t_game *game);
void	allocate_matrix(t_game *game, int *fd);
void	allocate_object(t_game *game);
void	allocate_player(t_game *game);
/*free*/
int		free_exit(int EXIT);
/*others*/
void	print_map(t_map *map);
void	print_objects(t_map *map);

#endif
