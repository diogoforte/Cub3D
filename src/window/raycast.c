/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:14:20 by plopes-c          #+#    #+#             */
/*   Updated: 2023/11/06 18:04:54 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int draw_collum(double lenght, int color)
{
	static int j;

	double lineH = (double)(HEIGHT / lenght);
	if (lineH > HEIGHT)
		lineH = HEIGHT;
	draw_line(j, 0, (PI / 2), (HEIGHT / 2 - lineH / 2), 0x001489);
	draw_line(j, (HEIGHT / 2 - lineH / 2), (PI / 2), lineH, color);
	draw_line(j, (HEIGHT / 2 + lineH / 2), (PI / 2), (HEIGHT / 2 - lineH / 2), 0x5C4033);
	if (j == WIDTH)
		return (j = 0);
	else
		j++;
	return (0);
}

void set_dist_to_side(double vector[2])
{
	if (vector[X] < 0)
	{
		ray()->step[X] = -1;
		ray()->prep_hit_dist[X] = cub()->player.pos[X] - (int)(cub()->player.map_pos[X] * SCALE);
		ray()->first_hit[X] = -(cub()->player.pos[X] - (int)cub()->player.pos[X]);
		ray()->dist_to_side[X] = ((cub()->player.map_pos[X]) - ray()->map_pos[X]) * ray()->dist_between[X];
	}
	else
	{
		ray()->step[X] = 1;
		ray()->prep_hit_dist[X] = (int)((cub()->player.map_pos[X] + 1) * SCALE) + cub()->player.pos[X];
		ray()->first_hit[X] = (cub()->player.pos[X] - (int)cub()->player.pos[X]);
		ray()->dist_to_side[X] = (ray()->map_pos[X] + 1.0 - (cub()->player.map_pos[X])) * ray()->dist_between[X];
	}
	if (vector[Y] < 0)
	{
		ray()->step[Y] = -1;
		ray()->prep_hit_dist[Y] = cub()->player.pos[Y] - (int)(cub()->player.map_pos[Y] * SCALE);
		ray()->first_hit[Y] = -(cub()->player.pos[Y] - (int)cub()->player.pos[Y]);
		ray()->dist_to_side[Y] = ((cub()->player.map_pos[Y]) - ray()->map_pos[Y]) * ray()->dist_between[Y];
	}
	else
	{
		ray()->step[Y] = 1;
		ray()->prep_hit_dist[Y] = (int)((cub()->player.map_pos[Y] + 1) * SCALE) - cub()->player.pos[Y];
		ray()->first_hit[Y] = (cub()->player.pos[Y] - (int)cub()->player.pos[Y]);
		ray()->dist_to_side[Y] = (ray()->map_pos[Y] + 1.0 - (cub()->player.map_pos[Y])) * ray()->dist_between[Y];
	}
	printf("ray()->prep_hit_dist[X]: %f\n", ray()->prep_hit_dist[X]);
	printf("ray()->prep_hit_dist[Y]: %f\n", ray()->prep_hit_dist[Y]);
}

void set_dist_between(double vector[2])
{
	ray()->map_pos[X] = cub()->player.map_pos[X];
	ray()->map_pos[Y] = cub()->player.map_pos[Y];
	if (vector[X] == 0)
		ray()->dist_between[X] = 10000000000000;
	else
		ray()->dist_between[X] = fabs(1 / vector[X]);
	if (vector[Y] == 0)
		ray()->dist_between[Y] = 10000000000000;
	else
		ray()->dist_between[Y] = fabs(1 / vector[Y]);
}

double	raycast(double vector[2])
{
	set_dist_between((double []){vector[X], vector[Y]});
	set_dist_to_side((double []){vector[X], vector[Y]});
	ray()->wall_hit = 0;
	while (ray()->wall_hit == 0)
	{
		if (ray()->dist_to_side[X] < ray()->dist_to_side[Y])
		{
			ray()->dist_to_side[X] += ray()->dist_between[X];
			ray()->map_pos[X] += ray()->step[X];
			ray()->side = 0x00d4ff;
		}
		else
		{
			ray()->dist_to_side[Y] += ray()->dist_between[Y];
			ray()->map_pos[Y] += ray()->step[Y];
			ray()->side = 0x00da4fe;
		}
		ray()->wall_hit = (cub()->map->map[ray()->map_pos[Y] + 1][ray()->map_pos[X] + 1] == '1');
	}
	if (ray()->side == 0x00d4ff)
		ray()->distance = (ray()->dist_to_side[X] - ray()->dist_between[X]) + ray()->prep_hit_dist[X];
	else
		ray()->distance = (ray()->dist_to_side[Y] - ray()->dist_between[Y]) + ray()->prep_hit_dist[Y];
	return (ray()->distance);
}
