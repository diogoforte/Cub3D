/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 05:12:18 by dinunes-          #+#    #+#             */
/*   Updated: 2024/01/26 13:43:47 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_limits(t_tdata *data)
{
	data->ray.wallheight = (int)(HEIGHT / data->ray.correctdistance);
	data->ray.drawstart = ((-(data->ray.wallheight) / 2 + HEIGHT / 2)
			+ cub()->window.mid);
	if (data->ray.drawstart < 0)
		data->ray.drawstart = 0;
	data->ray.drawend = ((data->ray.wallheight / 2 + HEIGHT / 2)
			+ cub()->window.mid);
	if (data->ray.drawend >= HEIGHT)
		data->ray.drawend = HEIGHT;
	if (data->ray.side == 0)
		data->ray.wallx = (cub()->player.pos[Y] / SCALE) + data->ray.distance
			* data->ray.dir[Y];
	else
		data->ray.wallx = (cub()->player.pos[X] / SCALE) + data->ray.distance
			* data->ray.dir[X];
	data->ray.wallx -= floor(data->ray.wallx);
	data->ray.tex[X] = (int)(data->ray.wallx * (double)TEX_WIDTH);
	if (data->ray.side == 0 && data->ray.dir[X] > 0)
		data->ray.tex[X] = TEX_WIDTH - data->ray.tex[X] - 1;
	if (data->ray.side == 1 && data->ray.dir[Y] < 0)
		data->ray.tex[X] = TEX_WIDTH - data->ray.tex[X] - 1;
	if (data->ray.side == 2)
		data->ray.tex[X] = TEX_WIDTH - data->ray.tex[X] - 1;
}

bool	texture_seconds(double time_in_secs)
{
	static clock_t	start_time;
	clock_t			current_time;
	double			elapsed_time;

	current_time = clock();
	elapsed_time = (double)(current_time - start_time) / CLOCKS_PER_SEC;
	if (start_time == 0)
	{
		start_time = clock();
		return (0);
	}
	if (elapsed_time >= time_in_secs)
	{
		start_time = 0;
		return (1);
	}
	else
		return (0);
}

t_texture	get_texture(t_tdata *data)
{
	static int	texnum;

	if (texture_seconds(.6))
		texnum++;
	texnum = texnum % 5;
	if (data->ray.door == true)
		return (map()->door_texture[texnum]);
	if (data->ray.side == 0)
	{
		if (data->ray.dir[0] > 0)
			return (map()->textures[EA]);
		else
			return (map()->textures[WE]);
	}
	if (data->ray.dir[1] > 0)
		return (map()->textures[SO]);
	else
		return (map()->textures[NO]);
}

void	draw_wall(int x, int y, t_tdata *data)
{
	t_texture	tex;
	int			color;
	int			texheight;
	double		step;
	double		texpos;

	tex = get_texture(data);
	texheight = tex.height;
	step = (double)texheight / (double)data->ray.wallheight;
	texpos = (data->ray.drawstart - cub()->window.mid - HEIGHT / 2
			+ data->ray.wallheight / 2) * step;
	y = data->ray.drawstart - 1;
	while (++y < data->ray.drawend)
	{
		data->ray.tex[Y] = (int)texpos & (texheight - 1);
		texpos += step;
		color = ((int *)tex.addr)[texheight * data->ray.tex[Y]
			+ data->ray.tex[X]];
		if (data->ray.side == 1)
			color = (color >> 1) & 8355711;
		buffer_mlx_pixel_put(x, y, color);
	}
}

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
			buffer_mlx_pixel_put(x, y, map()->fc[1]);
		while (++y < HEIGHT)
			buffer_mlx_pixel_put(x, y, map()->fc[0]);
	}
	return (NULL);
}
