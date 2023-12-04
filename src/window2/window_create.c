/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:09:49 by plopes-c          #+#    #+#             */
/*   Updated: 2023/11/02 13:53:44 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void start_angle(void)
{
	if (cub()->map->map[cub()->map->start_y + 2][cub()->map->start_x + 2] == 'N')
		cub()->player.angle = 1.5 * PI;
	else if (cub()->map->map[cub()->map->start_y + 2][cub()->map->start_x + 2] == 'S')
		cub()->player.angle = 0.5 * PI;
	else if (cub()->map->map[cub()->map->start_y + 2][cub()->map->start_x + 2] == 'W')
		cub()->player.angle = PI;
	else if (cub()->map->map[cub()->map->start_y + 2][cub()->map->start_x + 2] == 'E')
		cub()->player.angle = 0;
}

void player_prepare(void)
{
	cub()->player.map_pos[X] = cub()->map->start_x;
	cub()->player.map_pos[Y] = cub()->map->start_y;
	cub()->player.pos[X] = cub()->map->start_x * SCALE;
	cub()->player.pos[Y] = cub()->map->start_y * SCALE;
	start_angle();
	cub()->player.vector[X] = cos(cub()->player.angle);
	cub()->player.vector[Y] = sin(cub()->player.angle);
}

void window_prepare(void)
{
	cub()->window.mlx = mlx_init();
	cub()->player.mouse_x = 0;
	cub()->window.win = mlx_new_window(cub()->window.mlx, WIDTH, HEIGHT,
		"Cub3D");
	cub()->window.img.img = mlx_new_image(cub()->window.mlx, WIDTH, HEIGHT);
	cub()->window.img.addr = mlx_get_data_addr(cub()->window.img.img,
		&(cub()->window.img.bits_per_pixel), &(cub()->window.img.line_length),
		&(cub()->window.img.endian));
	cub()->map = cub()->maps;
}

void	window_create(void)
{
	window_prepare();
	player_prepare();
	mlx_hook(cub()->window.win, EVENT_CLOSE_BTN, 0, cub()->exit, NULL);
	// mlx_mouse_hook(cub()->window.win, mouse_press, NULL);
	mlx_loop_hook(cub()->window.mlx, draw_game, NULL);
	mlx_hook(cub()->window.win, 2, 1L << 0, (void *)key_press, NULL);
	mlx_hook(cub()->window.win, 3, 1L << 1, (void *)key_release, NULL);
	mlx_loop(cub()->window.mlx);
}
