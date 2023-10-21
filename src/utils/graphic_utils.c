/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaleira <chaleira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:30:42 by chaleira          #+#    #+#             */
/*   Updated: 2023/10/21 22:24:35 by chaleira         ###   ########.fr       */
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
