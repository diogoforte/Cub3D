/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:05:44 by plopes-c          #+#    #+#             */
/*   Updated: 2024/01/05 09:18:26 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void draw_minimap(void)
// {
// 	int i;
// 	int j;
// 	int scale;

// 	if (HEIGHT > WIDTH)
// 		scale = WIDTH / 50;
// 	else
// 		scale = HEIGHT / 50;
// 	cub()->window.minimap_scale = scale;
// 	i = 0;
// 	while (i < cub()->map->map_height)
// 	{
// 		j = 0;
// 		while (j < cub()->map->map_width)
// 		{
// 			if (cub()->map->map[i][j] == '1')
// 				draw_square(j * scale - 1, i * scale - 1, scale, scale, 0xFFFFFF);
// 			else
// 				draw_square(j * scale - 1, i * scale - 1, scale, scale, 0x000000);
// 			j++;
// 		}
// 		i++;
// 	}
// 	draw_point(((cub()->player.pos[X] / SCALE) + 1) * scale, ((cub()->player.pos[Y] / SCALE) + 1) * scale, 2, 0xFF0000);
// }

void	draw_minimap(void)
{
	int	x;
	int	y;
	int	j;
	int	i;

	y = 0;
	while (++y < cub()->map->map_height - 1)
	{
		x = 0;
		while (++x < cub()->map->map_width - 1)
		{
			if (cub()->map->map[y][x] == '1')
			{
				i = -1;
				while (++i < cub()->window.tile_size)
				{
					j = -1;
					while (++j < cub()->window.tile_size)
						buffer_mlx_pixel_put((x - 1) * cub()->window.tile_size
							+ i, (y - 1) * cub()->window.tile_size + j,
							0xFFFFFF);
				}
			}
			else
			{
				i = -1;
				while (++i < cub()->window.tile_size)
				{
					j = -1;
					while (++j < cub()->window.tile_size)
						buffer_mlx_pixel_put((x - 1) * cub()->window.tile_size
							+ i, (y - 1) * cub()->window.tile_size + j, 0x0);
				}
			}
			if (x < cub()->map->map_width - 1)
			{
				i = -1;
				while (++i < cub()->window.tile_size)
					buffer_mlx_pixel_put((x)*cub()->window.tile_size - 1, (y
							- 1) * cub()->window.tile_size + i, 0x808080);
			}
			if (y < cub()->map->map_height - 1)
			{
				i = -1;
				while (++i < cub()->window.tile_size)
					buffer_mlx_pixel_put((x - 1) * cub()->window.tile_size + i,
						y * cub()->window.tile_size - 1, 0x808080);
			}
		}
	}
	draw_point(player()->pos[X] - 5, player()->pos[Y] - 5, 5, 0xFF0000);
}