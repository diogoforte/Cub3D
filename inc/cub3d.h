/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:53:38 by chaleira          #+#    #+#             */
/*   Updated: 2024/01/08 17:40:26 by dinunes-         ###   ########.fr       */
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

# define THERE write(1, "THERE\n", 6)
# define HERE write(1, "HERE\n", 6)

# define WIDTH 1080
# define HEIGHT 1080
# define SCALE 50
# define MM_SCALE (ft_min(HEIGHT, WIDTH) / 20)
# define MM_WIDTH (WIDTH / 6)
# define MM_HEIGHT (HEIGHT * 0.83)
# define FOV (PI / 3)
# define ANGLE (FOV / WIDTH)
# define TEX_WIDTH 64
# define MOVE_SPEED 500
# define ROT_SPEED 5
# define FPS 1000
# define FRAME_TIME_NS (1000000000L / FPS)

# define THREADS 8
# define THREAD_WIDTH (WIDTH / THREADS)
# define THREAD_HEIGHT (HEIGHT / THREADS)

# define X 0
# define Y 1
# define PI 3.14159265359
# define SPACERS " \t\n\v\f\r"
# define OUTLINE 'a'
# define FILLER 'b'
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
# define NO 0
# define SO 1
# define WE 2
# define EA 3

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
# define KEY_SPACE 32
# define EVENT_CLOSE_BTN 17

typedef struct s_map		t_map;
typedef struct s_texture	t_texture;
typedef struct s_cub		t_cub;
typedef struct s_window		t_window;
typedef struct s_player		t_player;
typedef struct s_image		t_image;
typedef struct s_ray		t_ray;
typedef struct s_tdata		t_tdata;
typedef void				(*array_func)();

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
	int						map_number;
	char					*map_name;
	bool					playable;
	char					*error;
	char					**map;
	char					*cords[6];
	int						FC[2];
	int						map_width;
	int						map_height;
	int						start_x;
	int						start_y;
	char					start_dir;
	t_texture				textures[5];

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
	int						texnum;
	int						texheight;
	double					texpos;
	double					texstep;
	int						color;
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
};

struct						s_cub
{
	t_map					*map;
	t_map					*maps;
	int						status;
	void					(*map_load)(char **av);
	int						(*exit)(char *str);
	void					(*maps_destroy)();
	t_map					*(*map_new)(char *file_path);
	void					(*map_extract_data)(t_map *map);
	void					(*draw_screen)();
	void					(*draw_minimap)();
	void					(*move)();
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
t_ray						*ray(void);
t_window					*window(void);
t_player					*player(void);
t_map						*map_new(char *file_path);
void						map_extract_file(t_map *map, char *file_path);
int							err(char *str, t_map *map);
void						print_matrix(char **matrix);
int							exit_cub(char *str);
void						maps_destroy(void);
void						map_add_back(t_map **map, t_map *new_map);
void						map_load(char **argv);
void						map_extract_data(t_map *map);
void						map_print(t_map *map);
int							all_filled(t_map *map);
void						map_extract_map(char **grid, t_map *map);
t_map						*map_new(char *file_path);
void						map_destroy_map(t_map *map);
void						map_destroy_error(t_map *map);
void						map_destroy_cords(t_map *map);
void						map_clear(t_map *map);
void						map_check(t_map *map);
int							map_invalid_char(t_map *map);
int							matrix_biggest_string(char **str);

void						window_create(void);
int							key_press(int keycode);
int							key_release(int keycode);
void						draw_map(void);
int							render(void);
void						movement(void);

void						buffer_mlx_pixel_put(int x, int y, int color);
void						draw_line(double x0, double y0, double angle,
								double lenght, int color);
void						draw_point(int x, int y, int size, int color);

void						draw_square(int x, int y, int width, int height,
								int color);
void						draw_screen(void);
void						draw_circle(int x_center, int y_center, int radius,
								int color);
void						fps(void);
int							draw_collum(double lenght, int color);
void						clear_screen(void);
int							stoi(double nb);
double						itos(int nb);
void						draw_minimap(void);
double						raycast(t_tdata *data);
t_tdata						*tdata(int threadid);

void						*draw_fov(void *arg);
void						draw_fov_threads(void);
void						calculate_wall_height_and_draw_limits(t_tdata *data);
void						draw_wall(int x, t_tdata *data);
#endif