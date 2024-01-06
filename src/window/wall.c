/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 05:12:18 by dinunes-          #+#    #+#             */
/*   Updated: 2024/01/06 12:55:33 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_wall_height_and_draw_limits(void)
{
	ray()->wallheight = (int)(HEIGHT / ray()->correctdistance);
	ray()->drawstart = -(ray()->wallheight) / 2 + HEIGHT / 2;
	if (ray()->drawstart < 0)
		ray()->drawstart = 0;
	ray()->drawend = ray()->wallheight / 2 + HEIGHT / 2;
	if (ray()->drawend >= HEIGHT)
		ray()->drawend = HEIGHT - 1;
	if (ray()->side == 0)
		ray()->wallx = (cub()->player.pos[Y] / SCALE) + ray()->correctdistance
		* ray()->dir[Y];
	else
		ray()->wallx = (cub()->player.pos[X] / SCALE) + ray()->correctdistance
		* ray()->dir[X];
	ray()->wallx -= floor(ray()->wallx);
	ray()->tex[X] = (int)(ray()->wallx * (double)TEX_WIDTH);
	if (ray()->side == 0 && ray()->dir[X] > 0)
		ray()->tex[X] = TEX_WIDTH - ray()->tex[X] - 1;
	if (ray()->side == 1 && ray()->dir[Y] < 0)
		ray()->tex[X] = TEX_WIDTH - ray()->tex[X] - 1;
}

int	get_texture_number(void)
{
	if (ray()->side == 0)
	{
		if (ray()->dir[0] > 0)
			return (EA);
		else
			return (WE);
	}
	if (ray()->dir[1] > 0)
		return (SO);
	else
		return (NO);
}

void	draw_wall(int x)
{
	int	y;

	ray()->texnum = get_texture_number();
	ray()->texheight = cub()->map->textures[ray()->texnum].height;
	ray()->texstep = 1.0 * ray()->texheight / ray()->wallheight;
	ray()->texpos = (ray()->drawstart - HEIGHT / 2 + ray()->wallheight / 2)
	* ray()->texstep;
	y = ray()->drawstart - 1;
	while (++y < ray()->drawend)
	{
		ray()->tex[Y] = (int)ray()->texpos & (ray()->texheight - 1);
		ray()->texpos += ray()->texstep;
		ray()->color = ((int *)cub()->map->textures[ray()->texnum].addr)
	[ray()->texheight * ray()->tex[Y] + ray()->tex[X]];
		if (ray()->side == 1)
			ray()->color = (ray()->color >> 1) & 8355711;
		buffer_mlx_pixel_put(x, y, ray()->color);
	}
}

// void	draw_wall(int x)
// {
// 	int y;
// 	int texNum;
// 	int color;
// 	int texHeight;
// 	double step;
// 	double texPos;

// 	texNum = get_texture_number();
// 	texHeight = cub()->map->textures[texNum].height;
// 	step = 1.0 * texHeight / ray()->wallheight;
// 	texPos = (ray()->drawstart - HEIGHT / 2 + ray()->wallheight / 2) * step;
// 	y = ray()->drawstart - 1;
// 	while (++y < ray()->drawend)
// 	{
// 		ray()->tex[Y] = (int)texPos & (texHeight - 1);
// 		texPos += step;
// 		color = ((int *)cub()->map->textures[texNum].addr)[texHeight
// 		* ray()->tex[Y] + ray()->tex[X]];
// 		if (ray()->side == 1)
// 			color = (color >> 1) & 8355711;
// 		buffer_mlx_pixel_put(x, y, color);
// 	}
// }