/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:25:15 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/16 22:41:11 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	buffer_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;
	
	if (x >= WIDTH ||y >= HEIGHT)
		return ;
	dst = cub()->window.img.addr + (y * cub()->window.img.line_length + x * (cub()->window.img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_player(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub()->window.tile_size / 5)
	{
		j = -1;
		while (++j < cub()->window.tile_size / 5)
			buffer_mlx_pixel_put(cub()->player.x + i, cub()->player.y + j, 0xFF0000);
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
						buffer_mlx_pixel_put(x * cub()->window.tile_size + i, y
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
						buffer_mlx_pixel_put(x * cub()->window.tile_size + i, y
							* cub()->window.tile_size + j, 0x0);
				}
			}
			if (x < cub()->map->map_width - 1)
			{
				i = -1;
				while (++i < cub()->window.tile_size)
					buffer_mlx_pixel_put((x + 1) * cub()->window.tile_size - 1,
						y * cub()->window.tile_size + i, 0x808080);
			}
			if (y < cub()->map->map_height - 1)
			{
				i = -1;
				while (++i < cub()->window.tile_size)
					buffer_mlx_pixel_put(x * cub()->window.tile_size + i, (y
						+ 1) * cub()->window.tile_size - 1, 0x808080);
			}
		}
		mlx_put_image_to_window(cub()->window.mlx, cub()->window.win,
			cub()->window.img.img, 0, 0);
	}
	draw_player();
}
