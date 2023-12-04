/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:40:19 by plopes-c          #+#    #+#             */
/*   Updated: 2023/12/04 16:05:53 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void delta_dist(double ray_dir[2])
{
	ray()->delta_dist[X] = fabs(1 / ray_dir[X]);
	ray()->delta_dist[Y] = fabs(1 / ray_dir[Y]);
}

void draw_fov(void)
{
	double x;
	double y;
	double fov;
	double increment;
	double dist;

	x = player()->pos[X];
	y = player()->pos[Y];
	increment = FOV / WIDTH;
	fov = -(FOV / 2) + player()->angle;
	while (fov < (FOV / 2) + player()->angle)
	{
		dist = raycast(fov);
		draw_line(x, y, fov, dist, 0xFF0000);
		fov += increment;
	}

}

int raycast(double angle)
{
	double x;
	double y;
	int dist = 0;

	x = player()->pos[X];
	y = player()->pos[Y];
	while (cub()->map->map[stoi(y) + 1][stoi(x) + 1] != '1')
	{
		x += cos(angle);
		y += sin(angle);
		dist++;
	}
	return (dist);
}
