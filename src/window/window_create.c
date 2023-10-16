/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:09:49 by plopes-c          #+#    #+#             */
/*   Updated: 2023/10/16 21:50:08 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_press(int button, int x, int y);

void	window_create(void)
{
	cub()->window.mlx = mlx_init();
	cub()->window.win = mlx_new_window(cub()->window.mlx, WIDTH, HEIGHT,
		"Cub3D");
	cub()->window.img.img = mlx_new_image(cub()->window.mlx, WIDTH, HEIGHT);
	cub()->window.img.addr = mlx_get_data_addr(cub()->window.img.img, &(cub()->window.img.bits_per_pixel),
			&(cub()->window.img.line_length), &(cub()->window.img.endian));
	mlx_hook(cub()->window.win, EVENT_CLOSE_BTN, 0, cub()->exit, NULL);
	mlx_mouse_hook(cub()->window.win, mouse_press, NULL);
	mlx_hook(cub()->window.win, 2, 1L<<0, key_press, NULL);
	mlx_hook(cub()->window.win, 3, 1L<<1, key_release, NULL);
	mlx_loop_hook(cub()->window.mlx, draw_game, NULL);
	mlx_loop(cub()->window.mlx);
}
