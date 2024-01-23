/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:05:44 by plopes-c          #+#    #+#             */
/*   Updated: 2024/01/23 19:19:39 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_empty_tile(int dx, int dy, int radius, int color)
{
	int	pixel_dx;
	int	pixel_dy;
	int	pixel_distance;
	int	i;
	int	j;

	i = 0;
	while (i < MM_SCALE)
	{
		j = 0;
		while (j < MM_SCALE)
		{
			pixel_dx = dx + i - MM_SCALE / 30;
			pixel_dy = dy + j - MM_SCALE / 30;
			pixel_distance = sqrt(pixel_dx * pixel_dx + pixel_dy * pixel_dy);
			if (pixel_distance <= radius * MM_SCALE)
				buffer_mlx_pixel_put(MM_WIDTH + dx + i, MM_HEIGHT + dy + j,
					color);
			++j;
		}
		++i;
	}
}

void	draw_outside_map(int dx, int dy, int radius)
{
	int	pixel_dx;
	int	pixel_dy;
	int	pixel_distance;
	int	i;
	int	j;

	i = 0;
	while (i < MM_SCALE)
	{
		j = 0;
		while (j < MM_SCALE)
		{
			pixel_dx = dx + i - MM_SCALE / 30;
			pixel_dy = dy + j - MM_SCALE / 30;
			pixel_distance = sqrt(pixel_dx * pixel_dx + pixel_dy * pixel_dy);
			if (pixel_distance <= radius * MM_SCALE)
			{
				buffer_mlx_pixel_put(MM_WIDTH + dx + i, MM_HEIGHT + dy + j,
					0x139);
			}
			++j;
		}
		++i;
	}
}

void	draw_minimap_tiles(int player_x, int player_y, int radius)
{
	int	distance[2];
	int	coord[2];

	coord[Y] = player_y / MM_SCALE - radius;
	while (coord[Y] <= player_y / MM_SCALE + radius)
	{
		coord[X] = player_x / MM_SCALE - radius;
		while (coord[X] <= player_x / MM_SCALE + radius)
		{
			distance[X] = coord[X] * MM_SCALE - player_x;
			distance[Y] = coord[Y] * MM_SCALE - player_y;
			if (coord[Y] >= 0 && coord[Y] < cub()->map->map_height
				&& coord[X] >= 0 && coord[X] < cub()->map->map_width)
			{
				if (cub()->map->map[coord[Y]][coord[X]] == '1')
					draw_empty_tile(distance[X], distance[Y], radius, 0x3386FF);
				else if (cub()->map->map[coord[Y]][coord[X]] == 'D')
					draw_empty_tile(distance[X], distance[Y], radius, 0xFF0000);
				else if (cub()->map->map[coord[Y]][coord[X]] == 'O')
					draw_empty_tile(distance[X], distance[Y], radius, (0x00139 >> 1) & 8355711);
				else
					draw_empty_tile(distance[X], distance[Y], radius, 0x00139);
			}
			else
				draw_outside_map(distance[X], distance[Y], radius);
			++coord[X];
		}
		++coord[Y];
	}
}

void	draw_minimap(void)
{
	int	player_x;
	int	player_y;
	int	radius;

	player_x = (player()->pos[X] / SCALE) * MM_SCALE + MM_SCALE;
	player_y = (player()->pos[Y] / SCALE) * MM_SCALE + MM_SCALE;
	radius = MM_SCALE / 15;
	draw_minimap_tiles(player_x, player_y, radius);
	minimap_player(0xFFFFFF);
	minimap_player_angle(0xFFFFFF);
}
