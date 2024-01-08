/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_calls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:04:19 by chaleira          #+#    #+#             */
/*   Updated: 2024/01/08 17:20:17 by dinunes-         ###   ########.fr       */
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

t_cub	*cub(void)
{
	static t_cub cub = {
		NULL,
		NULL,
		0,
		map_load,
		exit_cub,
		maps_destroy,
		map_new,
		NULL,
		NULL,
		draw_minimap,
		movement,
		{},
		{}
	};

	return (&cub);
}

t_tdata	*tdata(int threadid)
{
	static t_tdata	data[THREADS];
	t_ray ray = {};

	data[threadid].id = threadid;
	data[threadid].ray = ray;
	return (&data[threadid]);
}
