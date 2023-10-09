/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:09:49 by plopes-c          #+#    #+#             */
/*   Updated: 2023/10/10 00:12:29 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void   window_create(t_cub *cub)
{
	cub->window.mlx = mlx_init();
	cub->window.win = mlx_new_window(cub->window.mlx, WIDTH, HEIGHT, "Cub3D");
	mlx_loop(cub->window.mlx);
}
