/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:08:53 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/05 22:12:11 by plopes-c         ###   ########.fr       */
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

typedef struct s_map			t_map;
typedef struct s_engine			t_engine;

struct					s_map
{
	bool				playable;
	int 				map_number;	
	int					fd;
	char				*cords[6];
	char				**grid;
	char				**map;
	int					rows;
	int					cols;
	t_map				*next;
};

struct					s_engine
{
	void				*mlx;
	void				*win;
	t_map				**map;
	void				(*start)(void);
	void				(*free)(t_map *map);
};

//	MAP
// 		MAP_CREATE
void		maps_loader(char **av, int argc);
// 		MAP_CHECK
void	map_checker(t_map	*map);

//	ENGINE
t_engine	*engine(void);
void		engine_start(void);
void		engine_free(t_map *map);

//	EXIT
void		do_exit(char *str);
int			err(char *str, t_map *map);

//	UITLS
// 		MAP_UTILS
int			matrix_biggest_string(char **str);
int 		ft_matrix_len(char **str);
char 		***arr_type(t_map	*map);
int 		all_filled(t_map *map);
// 		UTILS
void    	*ft_realloc(void *ptr, size_t nitems, size_t size);
void		print_vars(t_map *map);

#endif