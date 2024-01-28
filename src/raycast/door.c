/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:15:53 by dinunes-          #+#    #+#             */
/*   Updated: 2024/01/26 10:16:00 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_door(t_tdata *data)
{
	if (cub()->player.f && has_passed_x_seconds(0.5))
	{
		data->ray.angle = player()->angle;
		calculate_distance(data, 1);
		if (map()->map[(data->ray.map_pos[Y] / SCALE)
				+ 1][(data->ray.map_pos[X] / SCALE) + 1] == 'O'
			&& data->ray.distance < 1.5)
		{
			map()->map[(data->ray.map_pos[Y] / SCALE)
			+ 1][(data->ray.map_pos[X] / SCALE) + 1] = 'D';
			if (collision(player()->pos[X], player()->pos[Y]))
				map()->map[(data->ray.map_pos[Y] / SCALE)
				+ 1][(data->ray.map_pos[X] / SCALE) + 1] = 'O';
		}
		else if (map()->map[(data->ray.map_pos[Y] / SCALE)
				+ 1][(data->ray.map_pos[X] / SCALE) + 1] == 'D'
			&& data->ray.distance < 1.5)
		{
			map()->map[(data->ray.map_pos[Y] / SCALE)
			+ 1][(data->ray.map_pos[X] / SCALE) + 1] = 'O';
		}
	}
}
