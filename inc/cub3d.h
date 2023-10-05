/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:08:53 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/05 07:09:25 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/inc/libft.h"
# include "../minilibx-linux/mlx.h"
# include "structs.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800

# define THERE write(1, "THERE\n", 6)
# define HERE write(1, "HERE\n", 6)

t_engine	*engine(void);
void		engine_start(void);
void		engine_free(t_map *map);
void		map_loader(char **av, int argc);
void    	*ft_realloc(void *ptr, size_t nitems, size_t size);
void		print_vars(t_map *map);
char 		***arr_type(t_map	*map);
void		do_exit(char *str);
int 		all_filled(t_map *map);
int			err(char *str, t_map *map);




#endif