/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:40:19 by plopes-c          #+#    #+#             */
/*   Updated: 2024/01/24 18:21:15 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ceiling_floor(void *arg)
{
	int		x;
	int		y;
	t_tdata	*data;

	data = (t_tdata *)arg;
	x = data->fc_start - 1;
	while (++x < data->fc_end)
	{
		y = -1;
		while (++y < (HEIGHT / 2 + cub()->window.mid))
			buffer_mlx_pixel_put(x, y, cub()->map->FC[1]);
		while (++y < HEIGHT)
			buffer_mlx_pixel_put(x, y, cub()->map->FC[0]);
	}
	return (NULL);
}

void	ray_side(t_tdata *data)
{
	if (data->ray.dir[X] < 0)
	{
		data->ray.step[X] = -1;
		data->ray.side_dist[X] = (player()->pos[X] - data->ray.map_pos[X])
			* data->ray.delta_dist[X];
	}
	else
	{
		data->ray.step[X] = 1;
		data->ray.side_dist[X] = (data->ray.map_pos[X] + 1.0 - player()->pos[X])
			* data->ray.delta_dist[X];
	}
	if (data->ray.dir[Y] < 0)
	{
		data->ray.step[Y] = -1;
		data->ray.side_dist[Y] = (player()->pos[Y] - data->ray.map_pos[Y])
			* data->ray.delta_dist[Y];
	}
	else
	{
		data->ray.step[Y] = 1;
		data->ray.side_dist[Y] = (data->ray.map_pos[Y] + 1.0 - player()->pos[Y])
			* data->ray.delta_dist[Y];
	}
}

double	raycast(t_tdata *data, bool flag)
{
	ray_side(data);
	while (1)
	{
		if (data->ray.side_dist[X] < data->ray.side_dist[Y])
		{
			data->ray.side_dist[X] += data->ray.delta_dist[X];
			data->ray.map_pos[X] += data->ray.step[X];
			data->ray.side = 0;
		}
		else
		{
			data->ray.side_dist[Y] += data->ray.delta_dist[Y];
			data->ray.map_pos[Y] += data->ray.step[Y];
			data->ray.side = 1;
		}
		if (cub()->map->map[(data->ray.map_pos[Y] / SCALE)
				+ 1][(data->ray.map_pos[X] / SCALE) + 1] == '1'
				|| cub()->map->map[(data->ray.map_pos[Y] / SCALE)
				+ 1][(data->ray.map_pos[X] / SCALE) + 1] == 'D'
				|| (flag && cub()->map->map[(data->ray.map_pos[Y] / SCALE)
				+ 1][(data->ray.map_pos[X] / SCALE) + 1] == 'O'))
		{
			if (cub()->map->map[(data->ray.map_pos[Y] / SCALE)
				+ 1][(data->ray.map_pos[X] / SCALE) + 1] == 'D')
				data->ray.door = true;
			break ;
		}
	}
	return (0);
}

void	calculate_distance(t_tdata *data, bool flag)
{
	data->ray.dir[X] = cos(data->ray.angle);
	data->ray.dir[Y] = sin(data->ray.angle);
	data->ray.map_pos[X] = (int)player()->pos[X];
	data->ray.map_pos[Y] = (int)player()->pos[Y];
	data->ray.delta_dist[X] = fabs(1 / data->ray.dir[X]);
	data->ray.delta_dist[Y] = fabs(1 / data->ray.dir[Y]);
	data->ray.door = false;
	raycast(data, flag);
	if (!data->ray.side)
		data->ray.distance = (data->ray.side_dist[X] - data->ray.delta_dist[X]);
	else if (data->ray.side == 1)
		data->ray.distance = (data->ray.side_dist[Y] - data->ray.delta_dist[Y]);
	data->ray.distance /= SCALE;
	if (!flag)
		data->ray.correctdistance = (data->ray.distance * cos(data->ray.angle
				- player()->angle));
}

void check_door(t_tdata *data)
{
	if (cub()->player.f && has_passed_x_seconds(0.5))
	{
		data->ray.angle = player()->angle;
		calculate_distance(data, 1);
		if (cub()->map->map[(data->ray.map_pos[Y] / SCALE)
					+ 1][(data->ray.map_pos[X] / SCALE) + 1] == 'O' && data->ray.distance < 1.5)
		{
			cub()->map->map[(data->ray.map_pos[Y] / SCALE)
					+ 1][(data->ray.map_pos[X] / SCALE) + 1] = 'D';
			if (collision(player()->pos[X], player()->pos[Y]))
				cub()->map->map[(data->ray.map_pos[Y] / SCALE)
					+ 1][(data->ray.map_pos[X] / SCALE) + 1] = 'O';
		}
		else if (cub()->map->map[(data->ray.map_pos[Y] / SCALE)
					+ 1][(data->ray.map_pos[X] / SCALE) + 1] == 'D' && data->ray.distance < 1.5)
		{
			cub()->map->map[(data->ray.map_pos[Y] / SCALE)
					+ 1][(data->ray.map_pos[X] / SCALE) + 1] = 'O';
		}
	}
}		

void	*draw_fov(void *arg)
{
	t_tdata	*data;
	int		x;

	data = (t_tdata *)arg;
	x = data->raycast_start - 1;
	if (!cub()->map->playable)
		return (NULL);
	check_door(data);
	data->ray.angle = -(FOV / 2) + player()->angle + data->raycast_start
		* ANGLE;
	while (++x < data->raycast_end)
	{
		calculate_distance(data, 0);
		calculate_wall_height_and_draw_limits(data);
		draw_wall(x, 0, data);
		data->ray.angle += ANGLE;
	}
	return (NULL);
}
