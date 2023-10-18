/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:09:49 by plopes-c          #+#    #+#             */
/*   Updated: 2023/10/18 23:28:09 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	window_create(void)
{
	cub()->window.mlx = mlx_init();
	cub()->player.mouse_x = 0;
	cub()->window.win = mlx_new_window(cub()->window.mlx, WIDTH, HEIGHT,
		"Cub3D");
	cub()->window.img.img = mlx_new_image(cub()->window.mlx, WIDTH, HEIGHT);
	cub()->window.img.addr = mlx_get_data_addr(cub()->window.img.img,
		&(cub()->window.img.bits_per_pixel), &(cub()->window.img.line_length),
		&(cub()->window.img.endian));
	mlx_hook(cub()->window.win, EVENT_CLOSE_BTN, 0, cub()->exit, NULL);
	mlx_mouse_hook(cub()->window.win, mouse_press, NULL);
	mlx_hook(cub()->window.win, 2, 1L << 0, key_press, NULL);
	mlx_hook(cub()->window.win, 3, 1L << 1, key_release, NULL);
	// mlx_mouse_move(cub()->window.mlx, cub()->window.win, WIDTH / 2, HEIGHT / 2);
	mlx_loop_hook(cub()->window.mlx, draw_game, NULL);
	mlx_loop(cub()->window.mlx);
}
