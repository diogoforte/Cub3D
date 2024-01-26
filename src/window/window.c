/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:05:14 by plopes-c          #+#    #+#             */
/*   Updated: 2024/01/26 13:07:16 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_dir(void)
{
	if (cub()->map->start_dir == 'N')
		player()->angle = 3 * PI / 2;
	else if (cub()->map->start_dir == 'S')
		player()->angle = PI / 2;
	else if (cub()->map->start_dir == 'E')
		player()->angle = 0;
	else if (cub()->map->start_dir == 'W')
		player()->angle = PI;
}

void	player_prepare(void)
{
	player()->map_pos[X] = cub()->map->start_x + 1;
	player()->map_pos[Y] = cub()->map->start_y + 1;
	player()->pos[X] = (player()->map_pos[X] + 0.5) * SCALE;
	player()->pos[Y] = (player()->map_pos[Y] + 0.5) * SCALE;
	player_dir();
	player()->vector[X] = cos(player()->angle);
	player()->vector[Y] = sin(player()->angle);
}

void	window_create(void)
{
	t_window	*win;

	win = window();
	win->mlx = mlx_init();
	load_textures();
	win->win = mlx_new_window(win->mlx, WIDTH, HEIGHT, "cub3D");
	win->img.img = mlx_new_image(win->mlx, WIDTH, HEIGHT);
	win->img.addr = mlx_get_data_addr(win->img.img, &win->img.bits_per_pixel,
			&win->img.line_length, &win->img.endian);
}

void	window_loop(void)
{
	has_passed_x_seconds(0);
	window_create();
	player_prepare();
	mlx_hook(window()->win, EVENT_CLOSE_BTN, 0, cub()->exit, NULL);
	if (cub()->map->playable)
		mlx_loop_hook(window()->mlx, render, NULL);
	mlx_loop_hook(window()->mlx, render, NULL);
	mlx_hook(window()->win, 2, 1L << 0, (void *)key_press, NULL);
	mlx_hook(window()->win, 3, 1L << 1, (void *)key_release, NULL);
	mlx_loop(window()->mlx);
}
