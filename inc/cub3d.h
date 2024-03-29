/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:53:38 by chaleira          #+#    #+#             */
/*   Updated: 2024/01/26 13:53:51 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/inc/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <time.h>
# include <unistd.h>

# define WIDTH 1000
# define HEIGHT 1000
# define SCALE 50
# define MM_SCALE 50 // (HEIGHT / 20)
# define MM_WIDTH 166.6666666667 // (WIDTH / 6)
# define MM_HEIGHT 830 // (HEIGHT * 0.83)
# define FOV 1.0471975512 // (PI / 3)
# define ANGLE 0.0010471976 // (FOV / WIDTH)
# define TEX_WIDTH 64
# define MOVE_SPEED 40
# define ROT_SPEED 0.001

# define THREADS 8
# define THREAD_WIDTH 125 // (WIDTH / THREADS)
# define THREAD_HEIGHT 125 // (HEIGHT / THREADS)

# define X 0
# define Y 1
# define PI 3.14159265359
# define SPACERS " \t\n\v\f\r"
# define OUTLINE 97
# define FILLER 98
# define PLAYER_START "NSEW"
# define VALID_CHARS "01NSEW_D "
# define EMPTY 48
# define WALL 49
# define W 1
# define S -1
# define A 1
# define D -1
# define E 10
# define Q -10
# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define DOOR 52

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
# define KEY_F 102
# define KEY_SPACE 32
# define KEY_CTRL 65507
# define KEY_SHIFT 65505
# define EVENT_CLOSE_BTN 17

typedef struct s_map		t_map;
typedef struct s_texture	t_texture;
typedef struct s_cub		t_cub;
typedef struct s_window		t_window;
typedef struct s_player		t_player;
typedef struct s_image		t_image;
typedef struct s_ray		t_ray;
typedef struct s_tdata		t_tdata;
typedef void				(*t_array_func)();

struct						s_texture
{
	void					*img;
	char					*addr;
	int						bits_per_pixel;
	int						line_length;
	int						endian;
	int						width;
	int						height;
};

struct						s_map
{
	char					*map_name;
	bool					playable;
	char					*error;
	char					**map;
	char					*cords[6];
	int						fc[2];
	int						map_width;
	int						map_height;
	int						start_x;
	int						start_y;
	char					start_dir;
	t_texture				textures[4];
	t_texture				door_texture[6];
	char					*door_texture_path[6];

	void					(*print)();
	void					(*destroy_file)(t_map *map);
	void					(*destroy_map)(t_map *map);
	void					(*destroy_cords)(t_map *map);
	void					(*destroy_error)(t_map *map);

	t_map					*next;
};

struct						s_image
{
	void					*img;
	char					*addr;
	int						bits_per_pixel;
	int						line_length;
	int						endian;
};

struct						s_window
{
	void					*mlx;
	void					*win;
	int						minimap_scale;
	t_image					img;
	double					tile_size;
	double					fps;
	double					frame_time;
	double					mid;
};

struct						s_ray
{
	double					dir[2];
	double					side_dist[2];
	double					delta_dist[2];
	double					step[2];
	double					angle;
	int						map_pos[2];
	int						side;
	double					distance;
	int						wallheight;
	int						drawstart;
	int						drawend;
	double					correctdistance;
	double					wallx;
	int						tex[2];
	bool					door;
};

struct						s_player
{
	double					pos[2];
	double					angle;
	int						mouse_x;
	int						mouse_y;
	double					vector[2];
	int						map_pos[2];
	t_ray					ray;
	bool					w;
	bool					a;
	bool					s;
	bool					d;
	bool					q;
	bool					e;
	bool					f;
	bool					control;
	bool					space;
	bool					shift;
};

struct						s_cub
{
	int						status;
	void					(*map_load)(char **av);
	int						(*exit)(char *str);
	void					(*maps_destroy)();
	t_map					*(*map_new)(char *file_path, t_map *map);
	void					(*map_extract_data)(t_map *map);
	void					(*draw_screen)();
	void					(*draw_minimap)();
	void					(*move)();
	t_map					map;
	t_window				window;
	t_player				player;
};

typedef struct s_tdata
{
	int						id;
	int						raycast_start;
	int						raycast_end;
	int						fc_start;
	int						fc_end;
	t_ray					ray;
}							t_tdata;

t_cub						*cub(void);
t_window					*window(void);
t_player					*player(void);
t_map						*map(void);
t_map						*map_new(char *file_path, t_map *map);
void						map_extract_file(t_map *map, char *file_path);
int							err(char *str, t_map *map);
int							exit_cub(char *str);
void						map_destroy(t_map *map);
void						map_load(char **argv);
void						map_extract_data(t_map *map);
int							all_filled(t_map *map);
void						map_extract_map(char **grid, t_map *map);
void						map_destroy_map(t_map *map);
void						map_destroy_error(t_map *map);
void						map_destroy_cords(t_map *map);
void						map_check(t_map *map);
int							map_invalid_char(t_map *map);
int							matrix_biggest_string(char **str);
void						window_loop(void);
int							key_press(int keycode);
int							key_release(int keycode);
int							render(void);
void						movement(void);
void						buffer_mlx_pixel_put(int x, int y, int color);
void						fps(void);
void						draw_minimap(void);
double						raycast(t_tdata *data, bool flag);
t_tdata						*tdata(int threadid);
void						*draw_fov(void *arg);
void						draw_fov_threads(void);
void						draw_limits(t_tdata *data);
void						draw_wall(int x, int y, t_tdata *data);
void						minimap_player_angle(int color);
void						minimap_player(int color);
void						*ceiling_floor(void *arg);
void						create_and_join_threads(pthread_t *threads,
								t_tdata **data, void *(*func)(void *));
void						draw_fov_threads(void);
bool						has_passed_x_seconds(double time_in_secs);
bool						collision(double x, double y);
void						check_door(t_tdata *data);
bool						texture_seconds(double time_in_secs);
int							print_matrix(char **matrix);
void						load_textures(void);
void						calculate_distance(t_tdata *data, bool flag);
void						map_add_outline(t_map *map, char c);

#endif