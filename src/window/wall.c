/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 05:12:18 by dinunes-          #+#    #+#             */
/*   Updated: 2024/01/06 06:56:30 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_wall_height_and_draw_limits(void)
{
	ray()->wallheight = (int)(HEIGHT / ray()->correctdistance);
	ray()->drawstart = -(ray()->wallheight) / 2 + HEIGHT / 2;
	if (ray()->drawstart < 0)
		ray()->drawstart = 0;
	ray()->drawend = ray()->wallheight / 2 + HEIGHT / 2;
	if (ray()->drawend >= HEIGHT)
		ray()->drawend = HEIGHT - 1;
}

void	draw_wall(int x)
{
	int	y;

	y = ray()->drawstart;
	while (y < ray()->drawend)
	{
		if (ray()->side)
			buffer_mlx_pixel_put(x, y, 0xFF0000);
		else
			buffer_mlx_pixel_put(x, y, 0xFF9633);
		y++;
	}
}