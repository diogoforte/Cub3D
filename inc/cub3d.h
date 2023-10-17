/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:53:38 by chaleira          #+#    #+#             */
/*   Updated: 2023/10/17 12:43:08 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/inc/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

# define THERE write(1, "THERE\n", 6)
# define HERE write(1, "HERE\n", 6)

# define WIDTH 1920
# define HEIGHT 1080
# define MINIMAP_WIDTH 500
# define MINIMAP_HEIGHT 500

# define SPACERS " \t\n\v\f\r"
# define OUTLINE -1
# define PLAYER_START "NSEW"
# define VALID_CHARS "01NSEW_ "
# define EMPTY '0'
# define WALL '1'
# define W 1
# define S -1
# define A 1
# define D -1
# define E 1
# define Q -1

# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_Q 113
# define KEY_E 101
# define KEY_F1 65470
# define EVENT_CLOSE_BTN 17

# define PI 3.14159265359

typedef struct s_map 		t_map;
typedef struct s_cub 		t_cub;
typedef struct s_window 	t_window;
typedef struct s_player 	t_player;
typedef struct s_image 		t_image;

struct s_map
{
	int		map_number;
	char	*map_name;
	bool	playable;
	char	*error;
	char	**map;
	char 	*cords[6];
	int		map_width;
	int		map_height;
	int		start_x;
	int		start_y;

	void	(*print)();
	void	(*destroy_file)(t_map *map);
	void	(*destroy_map)(t_map *map);
	void	(*destroy_cords)(t_map *map);
	void	(*destroy_error)(t_map *map);
	
	t_map	*next;
};

struct	s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct s_window
{
	void	*mlx;
	void	*win;
	float	tile_size;
	t_image	img;
};

struct s_player
{
	float		x;
	float		y;
	float		delta_x;
	float		delta_y;
	float		angle;
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	q;
	bool	e;
};

struct s_cub
{
	t_map 		*map;
	t_map		*maps;
	int			status;
	void		(*map_add_list)(char *file_path);
	void		(*map_load)(char **av);
	int		(*exit)(char *str);
	void		(*maps_destroy)();
	t_map		*(*map_new)(char *file_path);
	void		(*map_extract_data)(t_map *map);
	void		(*draw)();
	void		(*move)();	
	t_window	window;
	t_player	player;

};

t_cub	*cub(void);
t_map	*map_new(char *file_path);
void	map_add_list(char *file_path);
void	map_extract_file(t_map *map, char *file_path);
int		err(char *str, t_map *map);
void	print_matrix(char **matrix);
int		exit_cub(char *str);
void	maps_destroy(void);
void	map_add_back(t_map **map, t_map *new_map);
void	map_load(char **argv);
void	map_extract_data(t_map *map);
void	map_print(t_map *map);
int		all_filled(t_map *map);
void	map_extract_map(char **grid, t_map *map);
t_map	*map_new(char *file_path);
void 	map_destroy_map(t_map *map);
void 	map_destroy_error(t_map *map);
void 	map_destroy_cords(t_map *map);
void	map_clear(t_map *map);
void	map_check(t_map *map);
int		map_invalid_char(t_map *map);
int		matrix_biggest_string(char **str);

void	window_create(void);
void	draw_menu(void);
int		key_press(int keycode);
int		key_release(int keycode);
void	draw_map(void);
void	draw_menu(void);
int 	draw_game(void);
void	movement(void);

#endif