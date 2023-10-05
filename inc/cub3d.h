/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:08:53 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/04 21:52:51 by dinunes-         ###   ########.fr       */
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

t_engine	*engine(void);
void		engine_start(void);
void		engine_free(void);
int			help_message(int instance);
void		map_loader(char **av);

#endif