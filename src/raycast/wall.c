/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 05:12:18 by dinunes-          #+#    #+#             */
/*   Updated: 2024/01/23 19:06:04 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_wall_height_and_draw_limits(t_tdata *data)
{
	data->ray.wallheight = (int)(HEIGHT / data->ray.correctdistance);
	data->ray.drawstart = ((-(data->ray.wallheight) / 2 + HEIGHT / 2) + cub()->window.mid);
	if (data->ray.drawstart < 0)
		data->ray.drawstart = 0;
	data->ray.drawend = ((data->ray.wallheight / 2 + HEIGHT / 2) + cub()->window.mid);
	if (data->ray.drawend >= HEIGHT)
		data->ray.drawend = HEIGHT;
	if (data->ray.side == 0)
		data->ray.wallx = (cub()->player.pos[Y] / SCALE)
			+ data->ray.distance * data->ray.dir[Y];
	else
		data->ray.wallx = (cub()->player.pos[X] / SCALE)
			+ data->ray.distance * data->ray.dir[X];
	data->ray.wallx -= floor(data->ray.wallx);
	data->ray.tex[X] = (int)(data->ray.wallx * (double)TEX_WIDTH);
	if (data->ray.side == 0 && data->ray.dir[X] > 0)
		data->ray.tex[X] = TEX_WIDTH - data->ray.tex[X] - 1;
	if (data->ray.side == 1 && data->ray.dir[Y] < 0)
		data->ray.tex[X] = TEX_WIDTH - data->ray.tex[X] - 1;
	if (data->ray.side == 2)
		data->ray.tex[X] = TEX_WIDTH - data->ray.tex[X] - 1;
}

int	get_texture_number(t_tdata *data)
{
	if (data->ray.door == true)
		return (4);
	if (data->ray.side == 0)
	{
		if (data->ray.dir[0] > 0)
			return (EA);
		else
			return (WE);
	}
	if (data->ray.dir[1] > 0)
		return (SO);
	else
		return (NO);
}

void	draw_wall(int x, int y, t_tdata *data)
{
	int		texnum;
	int		color;
	int		texheight;
	double	step;
	double	texpos;

	texnum = get_texture_number(data);
	texheight = cub()->map->textures[texnum].height;
	step = (double)texheight / (double)data->ray.wallheight;
	texpos = (data->ray.drawstart - cub()->window.mid - HEIGHT / 2 + data->ray.wallheight / 2)
		* step;
	y = data->ray.drawstart - 1;
	while (++y < data->ray.drawend)
	{
		data->ray.tex[Y] = (int)texpos & (texheight - 1);
		texpos += step;
		color = ((int *)cub()->map->textures[texnum].addr)[texheight
			* data->ray.tex[Y] + data->ray.tex[X]];
		if (data->ray.side == 1)
			color = (color >> 1) & 8355711;
		buffer_mlx_pixel_put(x, y, color);
	}
}
