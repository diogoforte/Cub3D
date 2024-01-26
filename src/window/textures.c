/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:35:10 by dinunes-          #+#    #+#             */
/*   Updated: 2024/01/26 12:08:17 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_texture(char *path, t_texture *texture)
{
	texture->img = mlx_xpm_file_to_image(cub()->window.mlx, path,
			&texture->width, &texture->height);
	if (!texture->img && exit_cub("Failed to load textures"))
		return ;
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
			&texture->line_length, &texture->endian);
}

void	load_door_textures(void)
{
	int			i;
	static char	*paths[] = {"./textures/fixed_textures/planet1.xpm",
		"./textures/fixed_textures/planet2.xpm",
		"./textures/fixed_textures/planet3.xpm",
		"./textures/fixed_textures/planet4.xpm",
		"./textures/fixed_textures/planet5.xpm",
		"./textures/fixed_textures/planet6.xpm"};

	i = -1;
	while (++i < 5)
	{
		cub()->map->door_texture_path[i] = paths[i];
		load_texture(cub()->map->door_texture_path[i],
			&cub()->map->door_texture[i]);
	}
}

void	load_textures(void)
{
	int	i;

	i = -1;
	while (++i < 4)
		load_texture(cub()->map->cords[i], &cub()->map->textures[i]);
	load_door_textures();
}
