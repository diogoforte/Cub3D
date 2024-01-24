/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:05:14 by plopes-c          #+#    #+#             */
/*   Updated: 2024/01/24 18:54:29 by plopes-c         ###   ########.fr       */
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

void load_fixed_textures(void)
{
	int	i;

	i = -1;
	cub()->maps->door_texture_path[0] = "./fixed_textures/gate1.xpm";
	cub()->maps->door_texture_path[1] = "./fixed_textures/gate2.xpm";
	while (++i < 2)
	{
		cub()->map->door_texture[i].img = mlx_xpm_file_to_image(cub()->window.mlx,
			cub()->maps->door_texture_path[i], &cub()->map->door_texture[i].width,
			&cub()->map->door_texture[i].height);
		if (!cub()->map->door_texture[i].img && err("Failed to load textures\n", cub()->map))
			return ;
		cub()->map->door_texture[i].addr = mlx_get_data_addr(cub()->map->door_texture[i].img,
			&cub()->map->door_texture[i].bits_per_pixel,
		&cub()->map->door_texture[i].line_length,
			&cub()->map->door_texture[i].endian);
	}
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
	load_fixed_textures();
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
	has_passed_x_seconds(0);
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
