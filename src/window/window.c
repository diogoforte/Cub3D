/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:56:09 by plopes-c          #+#    #+#             */
/*   Updated: 2023/11/02 21:39:19 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void get_vector(double angle)
{
	cub()->player.ray.vector[X] = cos(cub()->player.angle + angle);
	cub()->player.ray.vector[Y] = sin(cub()->player.angle + angle);
}

void draw_fov(void)
{
	draw_line((stoi(cub()->player.pos[X]) + 1) * cub()->window.minimap_scale + 1, (stoi(cub()->player.pos[Y]) + 1) * cub()->window.minimap_scale + 1, cub()->player.angle - (FOV / 2), 100, 0xFF0000);
	draw_line((stoi(cub()->player.pos[X]) + 1) * cub()->window.minimap_scale + 1, (stoi(cub()->player.pos[Y]) + 1) * cub()->window.minimap_scale + 1, cub()->player.angle + (FOV / 2), 100, 0xFF0000);
}

void draw_screen(void)
{
	double pov = -(FOV / 2);
	double increment = FOV / WIDTH;
	double dist;

	while (pov <= FOV / 2)
	{
		get_vector(pov);
		dist = raycast((double[]){cub()->player.ray.vector[X], cub()->player.ray.vector[Y]});
		draw_collum(dist * cos(pov), ray()->side);
		pov += increment;
	}
	// (void)dist;
}

void draw_minimap(void)
{
	int i;
	int j;
	int scale;

	if (HEIGHT > WIDTH)
		scale = WIDTH / 50;
	else
		scale = HEIGHT / 50;
	cub()->window.minimap_scale = scale;
	i = 0;
	while (i < cub()->map->map_height)
	{
		j = 0;
		while (j < cub()->map->map_width)
		{
			if (cub()->map->map[i][j] == '1')
				draw_square(j * scale - 1, i * scale - 1, scale, scale, 0xFFFFFF);
			else
				draw_square(j * scale - 1, i * scale - 1, scale, scale, 0x000000);
			draw_line(j * scale, i * scale, 0, scale, 0x555555);
			j++;
		}
		draw_line(j * scale, i * scale, (PI / 2), scale, 0x555555);
		i++;
	}
	draw_point(((cub()->player.pos[X] / SCALE) + 1) * scale, ((cub()->player.pos[Y] / SCALE) + 1) * scale, 2, 0xFF0000);
	// draw_fov();
	double dist = raycast((double[]){cub()->player.vector[X], cub()->player.vector[Y]});
	draw_line(((cub()->player.pos[X] / SCALE) + 1) * scale, ((cub()->player.pos[Y] / SCALE) + 1) * scale, cub()->player.angle, dist * scale, 0xFF0000);
	
}
