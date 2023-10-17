/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:25:15 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/17 11:50:46 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	buffer_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	dst = cub()->window.img.addr + (y * cub()->window.img.line_length + x
		* (cub()->window.img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(int x0, int y0, int x1, int y1, int color)
{
	float	dx;
	float	dy;
	float	steps;
	float	x;
	float	y;
	int		i;

	dx = x1 - x0;
	dy = y1 - y0;
	steps = fmaxf(fabsf(dx), fabsf(dy));
	dx /= steps;
	dy /= steps;
	x = x0;
	y = y0;
	i = 0;
	while (i++ < steps)
	{
		buffer_mlx_pixel_put((int)x, (int)y, color);
		x += dx;
		y += dy;
	}
	buffer_mlx_pixel_put(x1, y1, color);
}

// void	draw_rays(void)
// {
// 	int r, mx, my, mp, dof;
// 	float rx, ry, ra, xo, yo;

// 	ra = pa;
// }

void	draw_player(void)
{
	int	i;
	int	j;
	int	radius;
	int	center_x;
	int	center_y;
	int	dir_x;
	int	dir_y;

	radius = cub()->window.tile_size / 3;
	center_x = cub()->player.x + cub()->window.tile_size / 100;
	center_y = cub()->player.y + cub()->window.tile_size / 100;
	dir_x = center_x + cub()->player.delta_x * radius;
	dir_y = center_y + cub()->player.delta_y * radius;
	i = -radius;
	while (++i < radius)
	{
		j = -radius;
		while (++j < radius)
		{
			if (i * i + j * j <= radius * radius)
				buffer_mlx_pixel_put(center_x + i, center_y + j, 0xFF0000);
		}
	}
	draw_line(center_x, center_y, dir_x, dir_y, 0xFF0000);
}

void	draw_map(void)
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
	draw_player();
	mlx_put_image_to_window(cub()->window.mlx, cub()->window.win,
		cub()->window.img.img, 0, 0);
}
