/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:40:19 by plopes-c          #+#    #+#             */
/*   Updated: 2024/01/26 10:20:09 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	update_ray_position(t_tdata *data)
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
}

bool	check_map(t_tdata *data, bool flag)
{
	if (cub()->map->map[(data->ray.map_pos[Y] / SCALE)
			+ 1][(data->ray.map_pos[X] / SCALE) + 1] == '1'
		|| cub()->map->map[(data->ray.map_pos[Y] / SCALE)
		+ 1][(data->ray.map_pos[X] / SCALE) + 1] == 'D' || (flag
			&& cub()->map->map[(data->ray.map_pos[Y] / SCALE)
			+ 1][(data->ray.map_pos[X] / SCALE) + 1] == 'O'))
	{
		if (cub()->map->map[(data->ray.map_pos[Y] / SCALE)
				+ 1][(data->ray.map_pos[X] / SCALE) + 1] == 'D')
			data->ray.door = true;
		return (true);
	}
	return (false);
}

double	raycast(t_tdata *data, bool flag)
{
	ray_side(data);
	while (1)
	{
		update_ray_position(data);
		if (check_map(data, flag))
			break ;
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
