/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:09:49 by plopes-c          #+#    #+#             */
/*   Updated: 2023/10/16 15:40:23 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	window_create(void)
{
	cub()->window.mlx = mlx_init();
	cub()->window.win = mlx_new_window(cub()->window.mlx, WIDTH, HEIGHT,
		"Cub3D");
	draw_menu();
	mlx_hook(cub()->window.win, EVENT_CLOSE_BTN, 0, cub()->exit, NULL);
	mlx_key_hook(cub()->window.win, key_hook, NULL);
	mlx_loop(cub()->window.mlx);
}
