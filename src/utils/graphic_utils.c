/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:30:42 by chaleira          #+#    #+#             */
/*   Updated: 2024/01/09 11:43:41 by dinunes-         ###   ########.fr       */
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

void	minimap_player_angle(int color)
{
	double	x;
	double	y;
	double	angle_x;
	double	angle_y;
	int		i;

	x = MM_WIDTH;
	y = MM_HEIGHT;
	angle_x = (double)cos(cub()->player.angle);
	angle_y = (double)sin(cub()->player.angle);
	i = -1;
	while (++i <= MM_SCALE / 4)
	{
		buffer_mlx_pixel_put((int)x, (int)y, color);
		x += angle_x;
		y += angle_y;
	}
}

void	minimap_player(int color)
{
	int	dx;
	int	dy;
	int	x;
	int	y;

	y = MM_HEIGHT - MM_SCALE / 10;
	while (y <= MM_HEIGHT + MM_SCALE / 10)
	{
		x = MM_WIDTH - MM_SCALE / 10;
		while (x <= MM_WIDTH + MM_SCALE / 10)
		{
			dx = MM_WIDTH - x;
			dy = MM_HEIGHT - y;
			if (dx * dx + dy * dy <= MM_SCALE / 10 * MM_SCALE / 10)
			{
				buffer_mlx_pixel_put(x, y, color);
			}
			x++;
		}
		y++;
	}
}
