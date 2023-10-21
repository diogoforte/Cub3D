/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaleira <chaleira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:25:15 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/21 11:21:53 by chaleira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int draw_screen(float lenght, int color)
{
	static int j;
	double lineH;

	lineH = (double)(cub()->window.tile_size / lenght) * (double)HEIGHT;
	if (lineH > HEIGHT)
		lineH = HEIGHT;
	draw_line(j, 0, (PI / 2), HEIGHT / 2 - lineH / 2, 0x001489);
	draw_line(j, HEIGHT / 2 - lineH / 2, (PI / 2), HEIGHT / 2 + lineH / 2, color);
	draw_line(j, HEIGHT / 2 + lineH / 2, (PI / 2), HEIGHT, 0x966666);
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
	double pov = -FOV / 2;
	double increment = FOV / WIDTH;
	int color = 0x007f99;
	while (pov < FOV / 2)
	{
		float x = cub()->player.x;
		float y = cub()->player.y;
		int dist = 0;
		while (cub()->map->map[((int)y / (int)cub()->window.tile_size) + 1][((int)x / (int)cub()->window.tile_size) + 1] != '1')
		{
			x += cos(cub()->player.angle + pov);
			if (cub()->map->map[((int)y / (int)cub()->window.tile_size) + 1][((int)x / (int)cub()->window.tile_size) + 1] == '1')
			{
				color = 0x00d4ff;
				break;
			}
			y += sin(cub()->player.angle + pov);
			if (cub()->map->map[((int)y / (int)cub()->window.tile_size) + 1][((int)x / (int)cub()->window.tile_size) + 1] == '1')
			{
				color = 0x007f99;
				break;
			}
			dist++;
		}
		if (draw_screen(dist * cos(pov), color))
			break;
		pov += increment;
	}
}

// void raycast2(void)
// {
// 	double pov = -FOV / 2;
// 	float increment = FOV / WIDTH;
// 	while (pov < FOV / 2)
// 	{
// 		float x = cub()->player.x;
// 		float y = cub()->player.y;
// 		int lenght = 0;
// 		while (cub()->map->map[((int)y / (int)cub()->window.tile_size) + 1][((int)x / (int)cub()->window.tile_size) + 1] != '1')
// 		{
// 			x += cos(cub()->player.angle + pov);
// 			if (cub()->map->map[((int)y / (int)cub()->window.tile_size) + 1][((int)x / (int)cub()->window.tile_size) + 1] == '1')
// 				break;
// 			y += sin(cub()->player.angle + pov);
// 			lenght++;
// 		}
// 		draw_line(cub()->player.x, cub()->player.y, (cub()->player.angle + pov), lenght, 0xFF0000);
// 		draw_line(cub()->player.x, cub()->player.y, cub()->player.angle, lenght, 0x00FF00);
// 		pov += increment;
// 	}
// }

// void	draw_player(void)
// {
// 	int	i;
// 	int	j;
// 	int	radius;
// 	int	center_x;
// 	int	center_y;

// 	radius = cub()->window.tile_size / 3;
// 	center_x = cub()->player.x + cub()->window.tile_size / 100;
// 	center_y = cub()->player.y + cub()->window.tile_size / 100;
// 	i = -radius;
// 	while (++i < radius)
// 	{
// 		j = -radius;
// 		while (++j < radius)
// 		{
// 			if (i * i + j * j <= radius * radius)
// 				buffer_mlx_pixel_put(center_x + i, center_y + j, 0xFF0000);
// 		}
// 	}
// 	raycast2();
// }

void	draw_map(void)
{
	// int	x;
	// int	y;
	// int	j;
	// int	i;

	// y = 0;
	// raycast();
	// cub()->move();
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
	raycast();
	cub()->move();
	mlx_put_image_to_window(cub()->window.mlx, cub()->window.win,
		cub()->window.img.img, 0, 0);
}
