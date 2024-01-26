/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:35:10 by dinunes-          #+#    #+#             */
/*   Updated: 2024/01/26 09:07:27 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void load_fixed_textures(void)
{
	int	i;

	i = -1;
	cub()->map->door_texture_path[0] = "./textures/fixed_textures/planet1.xpm";
	cub()->map->door_texture_path[1] = "./textures/fixed_textures/planet2.xpm";
	cub()->map->door_texture_path[2] = "./textures/fixed_textures/planet3.xpm";
	cub()->map->door_texture_path[3] = "./textures/fixed_textures/planet4.xpm";
	cub()->map->door_texture_path[4] = "./textures/fixed_textures/planet5.xpm";
	cub()->map->door_texture_path[5] = "./textures/fixed_textures/planet6.xpm";
	while (++i < 5)
	{
		cub()->map->door_texture[i].img = mlx_xpm_file_to_image(cub()->window.mlx,
			cub()->map->door_texture_path[i], &cub()->map->door_texture[i].width,
			&cub()->map->door_texture[i].height);
		if (!cub()->map->door_texture[i].img && exit_cub("Failed to load textures"))
			return ;
		cub()->map->door_texture[i].addr = mlx_get_data_addr(cub()->map->
			door_texture[i].img,
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
		if (!cub()->map->textures[i].img && exit_cub("Failed to load textures"))
			return ;
		cub()->map->textures[i].addr = mlx_get_data_addr(cub()->map->textures[i].img,
			&cub()->map->textures[i].bits_per_pixel,
		&cub()->map->textures[i].line_length,
		&cub()->map->textures[i].endian);
	}
	load_fixed_textures();
}
