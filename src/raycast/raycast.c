/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:40:19 by plopes-c          #+#    #+#             */
/*   Updated: 2024/01/05 12:46:05 by dinunes-         ###   ########.fr       */
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
// void	draw_fov(void)
// {
// 	ray()->angle = -(FOV / 2) + player()->angle;
// 	while (ray()->angle < (FOV / 2) + player()->angle)
// 	{
// 		draw_line(player()->pos[X], player()->pos[Y], ray()->angle, raycast(),
// 			0xFFF100);
// 		ray()->angle += ANGLE;
// 	}
// }

void	ceiling_floor(void)
{
	int x;
	int y;

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

void	draw_fov(void)
{
	double distance;
	
    ray()->angle = -(FOV / 2) + player()->angle;
	ceiling_floor();
    for (int x = 0; x < WIDTH; x++)
    {
		raycast();
		if (!ray()->side)
			distance = (ray()->side_dist[X] - ray()->delta_dist[X]);
		else
			distance = (ray()->side_dist[Y] - ray()->delta_dist[Y]);
		distance /= SCALE;
		if (distance < 0.0001)
			distance = 0.1;
        int wallheight = (int)(HEIGHT / distance);
		int drawStart = -wallheight / 2 + HEIGHT / 2;
	    if(drawStart < 0) drawStart = 0;
	    int drawEnd = wallheight / 2 + HEIGHT / 2;
	    if(drawEnd >= HEIGHT) drawEnd = HEIGHT - 1;
        for (int y = drawStart; y < drawEnd; y++)
		{
			if(ray()->side)
            	buffer_mlx_pixel_put(x, y, 0xFF0000);
			else
				buffer_mlx_pixel_put(x, y, 0xFF9633);
		}
        ray()->angle += ANGLE;
    }
}

