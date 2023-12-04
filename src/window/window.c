/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:05:14 by plopes-c          #+#    #+#             */
/*   Updated: 2023/12/04 15:22:05 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	tile_size(void)
{
	if (cub()->map->map_width < cub()->map->map_height)
	{
		window()->tile_size = MINIMAP_WIDTH / cub()->map->map_width;
		window()->tile_size = WIDTH / window()->tile_size;
	}
	else
	{
		window()->tile_size = MINIMAP_HEIGHT / cub()->map->map_height;
		window()->tile_size = HEIGHT / window()->tile_size;
	}
	window()->tile_size = 50;
}

void player_dir(void)
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

void player_prepare(void)
{
	player()->map_pos[X] = cub()->map->start_x;
	player()->map_pos[Y] = cub()->map->start_y;
	player()->pos[X] = itos(player()->map_pos[X]);
	player()->pos[Y] = itos(player()->map_pos[Y]);
	player_dir();
	player()->vector[X] = cos(player()->angle);
	player()->vector[Y] = sin(player()->angle);
	
}

void window_prepare(void)
{
	window()->mlx = mlx_init();
	window()->win = mlx_new_window(window()->mlx, WIDTH, HEIGHT, "cub3D");
	window()->img.img = mlx_new_image(window()->mlx, WIDTH, HEIGHT);
	window()->img.addr = mlx_get_data_addr(window()->img.img,
		&window()->img.bits_per_pixel, &window()->img.line_length,
		&window()->img.endian);
	cub()->map = cub()->maps;

}

void window_create(void)
{
	window_prepare();
	tile_size();
	player_prepare();
	mlx_hook(window()->win, EVENT_CLOSE_BTN, 0, cub()->exit, NULL);
	mlx_loop_hook(window()->mlx, render, NULL);
	mlx_hook(window()->win, 2, 1L << 0, (void *)key_press, NULL);
	mlx_hook(window()->win, 3, 1L << 1, (void *)key_release, NULL);
	mlx_loop(window()->mlx);
}