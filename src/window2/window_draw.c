/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:25:15 by dinunes-          #+#    #+#             */
/*   Updated: 2023/11/02 12:38:10 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int draw_collum(double lenght, int color)
{
	static int j;
	double lineH;

	lineH = (double)(((SCALE) / (double)lenght)) * (double)HEIGHT;
	if (lineH > HEIGHT)
		lineH = HEIGHT;
	draw_line(j, 0, (PI / 2), (HEIGHT / 2 - lineH / 2), 0x001489);
	draw_line(j, (double)(HEIGHT / 2 - lineH / 2), (PI / 2), lineH, color);
	draw_line(j, (double)(HEIGHT / 2 + lineH / 2), (PI / 2), (HEIGHT / 2 - lineH / 2), 0x5C4033);
	if (j == WIDTH)
		return (j = 0);
	j++;
	return (0);
}

double raycast(double x, double y, double angle, int *color)
{
	while (cub()->map->map[(int)(y / SCALE) + 1][(int)(x / SCALE) + 1] != '1')
	{
		x += cos(angle);
		if (cub()->map->map[(int)(y / SCALE) + 1][(int)(x / SCALE) + 1] == '1')
		{
			if (color)
				*color = 0x00d4ff;
			break;
		}
		y += sin(angle);
		if (cub()->map->map[(int)(y / SCALE) + 1][(int)(x / SCALE) + 1] == '1')
		{
			if (color)
				*color = 0x00da4fe;
			break;
		}
	}
	return (sqrt(pow(x - cub()->player.pos[X], 2) + pow(y - cub()->player.pos[Y], 2)));
}

void draw_screen(void)
{
	double pov = -(FOV / 2);
	double increment = FOV / WIDTH;
	int color = 0x007f99;
	double dist;

	while (pov <= FOV / 2)
	{
		dist = raycast(cub()->player.pos[X], cub()->player.pos[Y], cub()->player.angle + pov, &color);
		draw_collum((double)(dist * cos(pov)), color);
		pov += increment;
	}
}

void	draw_map(void)
{
	// int	x;
	// int	y;
	// int	j;
	// int	i;

	// y = 0;
	draw_screen();
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
	// draw_line(cub()->player.pos[X], cub()->player.pos[Y], cub()->player.angle, raycast(cub()->player.pos[X], cub()->player.pos[Y], cub()->player.angle, NULL), 0xFF0000);
	mlx_put_image_to_window(cub()->window.mlx, cub()->window.win,
		cub()->window.img.img, 0, 0);
}
