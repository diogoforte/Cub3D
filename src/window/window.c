/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:05:14 by plopes-c          #+#    #+#             */
/*   Updated: 2024/01/24 14:38:08 by dinunes-         ###   ########.fr       */
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
	player()->shift = false;
	player()->f = true;
}

void	load_textures(void)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		cub()->map->textures[i].img = mlx_xpm_file_to_image(cub()->window.mlx,
			cub()->map->cords[i], &cub()->map->textures[i].width,
			&cub()->map->textures[i].height);
		if (!cub()->map->textures[i].img && err("Failed to load textures\n", cub()->map))
			return ;
		cub()->map->textures[i].addr = mlx_get_data_addr(cub()->map->textures[i].img,
			&cub()->map->textures[i].bits_per_pixel,
		&cub()->map->textures[i].line_length,
		&cub()->map->textures[i].endian);
	}
	cub()->map->textures[i].img = mlx_xpm_file_to_image(cub()->window.mlx,
			"./textures/gate.xpm", &cub()->map->textures[i].width,
			&cub()->map->textures[i].height);
		if (!cub()->map->textures[i].img && err("Failed to load textures\n", cub()->map))
			err("Failed to load textures\n", cub()->map);
						return ;
		cub()->map->textures[i].addr = mlx_get_data_addr(cub()->map->textures[i].img,
			&cub()->map->textures[i].bits_per_pixel,
		&cub()->map->textures[i].line_length,
		&cub()->map->textures[i].endian);
}

void	window_prepare(void)
{
	window()->mlx = mlx_init();
	(window())->win = mlx_new_window(window()->mlx, WIDTH, HEIGHT, "cub3D");
	window()->img.img = mlx_new_image(window()->mlx, WIDTH, HEIGHT);
	window()->img.addr = mlx_get_data_addr(window()->img.img,
		&window()->img.bits_per_pixel, &window()->img.line_length,
	&window()->img.endian);
	cub()->map = cub()->maps;
	load_textures();
}

void	window_create(void)
{
	window_prepare();
	player_prepare();
	mlx_hook(window()->win, EVENT_CLOSE_BTN, 0, cub()->exit, NULL);
	if (cub()->map->playable)
		mlx_loop_hook(window()->mlx, render, NULL);
	mlx_loop_hook(window()->mlx, render, NULL);
	mlx_hook(window()->win, 2, 1L << 0, (void *)key_press, NULL);
	mlx_hook(window()->win, 3, 1L << 1, (void *)key_release, NULL);
	mlx_loop(window()->mlx);
}
