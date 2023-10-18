/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:25:15 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/18 23:52:01 by plopes-c         ###   ########.fr       */
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

void	draw_line(float x0, float y0, float x1, float y1, int lenght, int color)
{
	float	angle_x;
	float	angle_y;
	int		i;

	angle_x = cos(cub()->player.angle + x1);
	angle_y = sin(cub()->player.angle + y1);
	i = 0;
    while (i <= lenght)
    {
        buffer_mlx_pixel_put((int)x0, (int)y0, color);
        x0 += angle_x;
        y0 += angle_y;
		i++;
    }
}

int draw_screen(float lenght, int color)
{
	static int j;
	int i;
	double lineH;

	// printf("lenght: %f\n", lenght);
	lineH = (double)(27 / lenght) * (double)HEIGHT;
	i = 0;
	// printf("lineH: %f\n", lineH);
	if (lineH > HEIGHT)
		lineH = HEIGHT;
	while (i < HEIGHT / 2 - lineH / 2)
	{
		buffer_mlx_pixel_put(j, i, 0x001489);
		i++;
	}
	while (i < HEIGHT / 2 + lineH / 2)
	{
		buffer_mlx_pixel_put(j, i, color);
		i++;
	}
	while (i < HEIGHT)
	{
		buffer_mlx_pixel_put(j, i, 0x96666);
		i++;
	}
	if (j == WIDTH)
	{
		j = 0;
		return (1);
	}
	j++;
	return (0);
}

void raycast(void)
{
	double pov = -(PI / 2);
	double increment = (PI / 2) / WIDTH;
	int color = 0x007f99;
	while (pov < (PI / 2))
	{
		float x = cub()->player.x;
		float y = cub()->player.y;
		int lenght = 0;
		while (cub()->map->map[((int)y / (int)cub()->window.tile_size) + 1][((int)x / (int)cub()->window.tile_size) + 1] != '1')
		{
			x += cos(cub()->player.angle + pov + (PI / 4));
			if (cub()->map->map[((int)y / (int)cub()->window.tile_size) + 1][((int)x / (int)cub()->window.tile_size) + 1] == '1')
			{
				color = 0x00d4ff;
				break;
			}
			y += sin(cub()->player.angle + pov + (PI / 4));
			if (cub()->map->map[((int)y / (int)cub()->window.tile_size) + 1][((int)x / (int)cub()->window.tile_size) + 1] == '1')
			{
				color = 0x007f99;
				break;
			}
			lenght++;
		}
		if (draw_screen(lenght, color))
			break;
		pov += increment;
		// printf("x: %f, y: %f, lenght: %d\n", x, y, lenght);
	}
}

void raycast2(void)
{
	float pov = -(PI / 4);
	float increment = (PI / 2) / WIDTH;
	while (pov <= (PI / 4))
	{
		float x = cub()->player.x;
		float y = cub()->player.y;
		int lenght = 0;
		while (cub()->map->map[((int)y / (int)cub()->window.tile_size) + 1][((int)x / (int)cub()->window.tile_size) + 1] != '1')
		{
			x += cos(cub()->player.angle + pov);
			if (cub()->map->map[((int)y / (int)cub()->window.tile_size) + 1][((int)x / (int)cub()->window.tile_size) + 1] == '1')
				break;
			y += sin(cub()->player.angle + pov);
			lenght++;
		}
		draw_line(cub()->player.x, cub()->player.y, pov, pov, lenght, 0xFF0000);
		draw_line(cub()->player.x, cub()->player.y, 0, 0, lenght, 0x00FF00);
		pov += increment;
		// printf("x: %f, y: %f, lenght: %d\n", x, y, lenght);
	}
}

void	draw_player(void)
{
	int	i;
	int	j;
	int	radius;
	int	center_x;
	int	center_y;
	// int	dir_x;
	// int	dir_y;

	radius = cub()->window.tile_size / 3;
	center_x = cub()->player.x + cub()->window.tile_size / 100;
	center_y = cub()->player.y + cub()->window.tile_size / 100;
	// dir_x = center_x + cub()->player.delta_x * radius;
	// dir_y = center_y + cub()->player.delta_y * radius;
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
	raycast2();
}

void	draw_map(void)
{
	// int	x;
	// int	y;
	// int	j;
	// int	i;

	// y = 0;
	raycast();
	cub()->move();
	// while (++y < cub()->map->map_height - 1)
	// {
	// 	x = 0;
	// 	while (++x < cub()->map->map_width - 1)
	// 	{
	// 		if (cub()->map->map[y][x] == '1')
	// 		{
	// 			i = -1;
	// 			while (++i < cub()->window.tile_size)
	// 			{
	// 				j = -1;
	// 				while (++j < cub()->window.tile_size)
	// 					buffer_mlx_pixel_put((x - 1) * cub()->window.tile_size
	// 						+ i, (y - 1) * cub()->window.tile_size + j,
	// 						0xFFFFFF);
	// 			}
	// 		}
	// 		else
	// 		{
	// 			i = -1;
	// 			while (++i < cub()->window.tile_size)
	// 			{
	// 				j = -1;
	// 				while (++j < cub()->window.tile_size)
	// 					buffer_mlx_pixel_put((x - 1) * cub()->window.tile_size
	// 						+ i, (y - 1) * cub()->window.tile_size + j, 0x0);
	// 			}
	// 		}
	// 		if (x < cub()->map->map_width - 1)
	// 		{
	// 			i = -1;
	// 			while (++i < cub()->window.tile_size)
	// 				buffer_mlx_pixel_put((x)*cub()->window.tile_size - 1, (y
	// 						- 1) * cub()->window.tile_size + i, 0x808080);
	// 		}
	// 		if (y < cub()->map->map_height - 1)
	// 		{
	// 			i = -1;
	// 			while (++i < cub()->window.tile_size)
	// 				buffer_mlx_pixel_put((x - 1) * cub()->window.tile_size + i,
	// 					y * cub()->window.tile_size - 1, 0x808080);
	// 		}
	// 	}
	// }
	// draw_player();
	mlx_put_image_to_window(cub()->window.mlx, cub()->window.win,
		cub()->window.img.img, 0, 0);
}
