/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:40:19 by plopes-c          #+#    #+#             */
/*   Updated: 2023/12/04 18:17:42 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void update_ray(double ray_dir[2])
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

double raycast(double angle)
{
	double x;
	double y;
	int dist = 0;

	x = player()->pos[X];
	y = player()->pos[Y];
	while (cub()->map->map[stoi(y) + 1][stoi(x) + 1] != '1')
	{
		x += (cos(angle));
		y += (sin(angle));
		dist++;
	}
	x -= cos(angle);
	y -= sin(angle);
	return (dist);
}

// int draw_collum(double lenght, int color)
// {
// 	static int j;

// 	double lineH = (double)(HEIGHT / lenght);
// 	if (lineH > HEIGHT)
// 		lineH = HEIGHT;
// 	draw_line(j, 0, (PI / 2), (HEIGHT / 2 - lineH / 2), 0x001489);
// 	draw_line(j, (HEIGHT / 2 - lineH / 2), (PI / 2), lineH, color);
// 	draw_line(j, (HEIGHT / 2 + lineH / 2), (PI / 2), (HEIGHT / 2 - lineH / 2), 0x5C4033);
// 	if (j == WIDTH)
// 		return (j = 0);
// 	else
// 		j++;
// 	return (0);
// }

// void draw_screen(void)
// {
// 	double pov = -(FOV / 2);
// 	double increment = FOV / WIDTH;
// 	double dist;

// 	while (pov <= FOV / 2)
// 	{
// 		dist = raycast(pov + player()->angle);
// 		draw_collum(dist, ray()->side);
// 		pov += increment;
// 	}
// 	// (void)dist;
// }