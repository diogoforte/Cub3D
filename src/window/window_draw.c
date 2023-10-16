/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:25:15 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/16 15:40:14 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub()->window.tile_size)
	{
		j = -1;
		while (++j < cub()->window.tile_size)
		{
			mlx_pixel_put(cub()->window.mlx, cub()->window.win, cub()->player.x
				+ i, cub()->player.y + j, 0xFF0000);
		}
	}
}
void	draw_map(void)
{
	int	x;
	int	y;
	int	j;
	int	i;

	mlx_clear_window(cub()->window.mlx, cub()->window.win);
	y = -1;
	while (++y < cub()->map->map_height)
	{
		x = -1;
		while (++x < cub()->map->map_width)
		{
			if (cub()->map->map[y][x] == '1')
			{
				i = -1;
				while (++i < cub()->window.tile_size)
				{
					j = -1;
					while (++j < cub()->window.tile_size)
						mlx_pixel_put(cub()->window.mlx, cub()->window.win, x
							* cub()->window.tile_size + i, y
							* cub()->window.tile_size + j, 0xFFFFFF);
				}
			}
			else
			{
				i = -1;
				while (++i < cub()->window.tile_size)
				{
					j = -1;
					while (++j < cub()->window.tile_size)
						mlx_pixel_put(cub()->window.mlx, cub()->window.win, x
							* cub()->window.tile_size + i, y
							* cub()->window.tile_size + j, 0);
				}
			}
			if (x < cub()->map->map_width - 1)
			{
				i = -1;
				while (++i < cub()->window.tile_size)
					mlx_pixel_put(cub()->window.mlx, cub()->window.win, (x + 1)
						* cub()->window.tile_size - 1, y
						* cub()->window.tile_size + i, 0x808080);
			}
			if (y < cub()->map->map_height - 1)
			{
				i = -1;
				while (++i < cub()->window.tile_size)
					mlx_pixel_put(cub()->window.mlx, cub()->window.win, x
						* cub()->window.tile_size + i, (y + 1)
						* cub()->window.tile_size - 1, 0x808080);
			}
		}
	}
	draw_player();
}
