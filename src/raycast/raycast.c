/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:40:19 by plopes-c          #+#    #+#             */
/*   Updated: 2024/01/06 03:50:28 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_side(void)
{
	if (ray()->dir[X] < 0)
	{
		ray()->step[X] = -1;
		ray()->side_dist[X] = (player()->pos[X] - ray()->map_pos[X])
			* ray()->delta_dist[X];
	}
	else
	{
		ray()->step[X] = 1;
		ray()->side_dist[X] = (ray()->map_pos[X] + 1.0 - player()->pos[X])
			* ray()->delta_dist[X];
	}
	if (ray()->dir[Y] < 0)
	{
		ray()->step[Y] = -1;
		ray()->side_dist[Y] = (player()->pos[Y] - ray()->map_pos[Y])
			* ray()->delta_dist[Y];
	}
	else
	{
		ray()->step[Y] = 1;
		ray()->side_dist[Y] = (ray()->map_pos[Y] + 1.0 - player()->pos[Y])
			* ray()->delta_dist[Y];
	}
}

double	ray_distance(void)
{
	if (ray()->side_dist[X] < ray()->side_dist[Y])
		return ((ray()->map_pos[X] - player()->pos[X] + (1 - ray()->step[X])
				/ 2) / ray()->dir[X]);
	else
		return ((ray()->map_pos[Y] - player()->pos[Y] + (1 - ray()->step[Y])
				/ 2) / ray()->dir[Y]);
}

double	raycast(void)
{
	ray()->dir[X] = cos(ray()->angle);
	ray()->dir[Y] = sin(ray()->angle);
	ray()->map_pos[X] = (int)player()->pos[X];
	ray()->map_pos[Y] = (int)player()->pos[Y];
	ray()->delta_dist[X] = fabs(1 / ray()->dir[X]);
	ray()->delta_dist[Y] = fabs(1 / ray()->dir[Y]);
	ray_side();
	while (1)
	{
		if (ray()->side_dist[X] < ray()->side_dist[Y])
		{
			ray()->side_dist[X] += ray()->delta_dist[X];
			ray()->map_pos[X] += ray()->step[X];
			ray()->side = 0;
		}
		else
		{
			ray()->side_dist[Y] += ray()->delta_dist[Y];
			ray()->map_pos[Y] += ray()->step[Y];
			ray()->side = 1;
		}
		if (cub()->map->map[stoi(ray()->map_pos[Y]) + 1][stoi(ray()->map_pos[X])
			+ 1] == '1')
			break ;
	}
	return (ray_distance());
}

void	ceiling_floor(void)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y++ < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
			buffer_mlx_pixel_put(x++, y, cub()->map->FC[1]);
	}
	while (y++ < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			buffer_mlx_pixel_put(x++, y, cub()->map->FC[0]);
	}
}

void	calculate_distance(void)
{
	raycast();
	if (!ray()->side)
		ray()->distance = (ray()->side_dist[X] - ray()->delta_dist[X]);
	else
		ray()->distance = (ray()->side_dist[Y] - ray()->delta_dist[Y]);
	ray()->distance /= SCALE;
	ray()->correctdistance = ray()->distance * cos(ray()->angle
			- player()->angle);
	if (ray()->correctdistance < 0.0001)
		ray()->correctdistance = 0.1;
}

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

void	draw_fov(void)
{
	int	x;

	x = -1;
	if (!cub()->map->playable)
		return ;
	ray()->angle = -(FOV / 2) + player()->angle;
	ceiling_floor();
	while (++x < WIDTH)
	{
		calculate_distance();
		calculate_wall_height_and_draw_limits();
		draw_wall(x);
		ray()->angle += ANGLE;
	}
}
