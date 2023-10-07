/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaleira <chaleira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:53:38 by chaleira          #+#    #+#             */
/*   Updated: 2023/10/07 05:58:41 by chaleira         ###   ########.fr       */
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
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# define WIDTH 800
# define HEIGHT 800

# define THERE write(1, "THERE\n", 6)
# define HERE write(1, "HERE\n", 6)

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define F 4
# define C 5

typedef struct s_map 		t_map;
typedef struct s_cub 		t_cub;
typedef struct s_window 	t_window;

struct s_map
{
	bool	playable;
	char	**file;
	char	**map;
	char 	*cords[6];
	int		width;
	int		height;
	int		map_number;
	char	*error;

	void	(*print_variables)();
	void	(*destroy_file)(t_map *map);
	void	(*destroy_map)(t_map *map);
	void	(*destroy_cords)(t_map *map);
	void	(*destroy_error)(t_map *map);
	
	t_map	*next;
};

struct s_window
{
	void	*mlx;
	void	*win;
};

struct s_cub
{
	t_map		*map;
	t_window	window;
	int			status;

	void		(*map_add_list)(char *file_path);
	void		(*load_all_maps)(char **av);
	void		(*exit)(char *str);
	void		(*maps_destroy)();
	t_map		*(*map_new)(char *file_path);
	void		(*map_extract_data)(t_map *map);
};


t_cub	*cub(void);
t_map	*map_new(char *file_path);
void	map_add_list(char *file_path);
void	map_extract_file(t_map *map, char *file_path);
int		err(char *str, t_map *map);
void	matrix_add_back(char ***matrix, char *str);
void	print_matrix(char **matrix);
void	exit_cub(char *str);
void	maps_destroy(void);
void	map_add_back(t_map **map, t_map *new_map);
void	load_all_maps(char **argv);
void	map_extract_data(t_map *map);
void	map_print(t_map *map);
int		all_filled(t_map *map);
int		map_extract_map(char **grid, t_map *map);
t_map	*map_new(char *file_path);
char	*ft_stradd(char **original, char *add);
void 	map_destroy_file(t_map *map);
void 	map_destroy_map(t_map *map);
void 	map_destroy_error(t_map *map);
void 	map_destroy_cords(t_map *map);
void	map_clear(t_map *map);


#endif