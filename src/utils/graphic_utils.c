/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:30:42 by chaleira          #+#    #+#             */
/*   Updated: 2023/11/02 18:45:55 by plopes-c         ###   ########.fr       */
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

void	draw_line(double x0, double y0, double angle, int lenght, int color)
{
	double	angle_x;
	double	angle_y;
	int		i;

	angle_x = (double)cos(angle);
	angle_y = (double)sin(angle);
	i = 0;
    while (i <= lenght)
    {
        buffer_mlx_pixel_put((int)x0, (int)y0, color);
        x0 += angle_x;
        y0 += angle_y;
		i++;
    }
}

void draw_point(int x, int y, int size, int color)
{
	int i;
	int j;
	int center[2];

	i = -size;
	center[X] = x + size;
	center[Y] = y + size;
	while (++i < size)
	{
		j = -size;
		while (++j < size)
		{
			if (i * i + j * j <= size * size)
				buffer_mlx_pixel_put(center[X] + i, center[Y] + j, color);
		}
	}
}
void clear_screen(void)
{
	int j = 0;
	while (j < WIDTH)
	{
		draw_line(j, 0, (PI / 2), HEIGHT, 0x000000);
		j++;
	}
}

void draw_square(int x, int y, int width, int height, int color)
{
	int i;
	int j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			buffer_mlx_pixel_put(x + i, y + j, color);
	}
}
