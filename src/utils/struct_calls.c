/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_calls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:04:19 by chaleira          #+#    #+#             */
/*   Updated: 2024/01/24 18:13:48 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_player	*player(void)
{
	return (&cub()->player);
}

t_window	*window(void)
{
	return (&cub()->window);
}

t_map	*map(void)
{
	return (&cub()->map);
}

t_cub	*cub(void)
{
	static t_cub	cub = {
		0,
		map_load,
		exit_cub,
		map_destroy,
		map_new,
		NULL,
		NULL,
		draw_minimap,
		movement,
	{},
	{},
	{}
	};

	return (&cub);
}

t_tdata	*tdata(int threadid)
{
	static t_tdata	data[THREADS];
	t_ray			ray;

	ft_bzero(&ray, sizeof(t_ray));
	data[threadid].id = threadid;
	data[threadid].ray = ray;
	return (&data[threadid]);
}
