/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_calls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:04:19 by chaleira          #+#    #+#             */
/*   Updated: 2023/10/17 15:27:10 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <time.h>

void	fps(void)
{
	static clock_t	prev_time;
	clock_t			curr_time;
	double			frame_time;

	curr_time = clock();
	frame_time = (double)(curr_time - prev_time) / CLOCKS_PER_SEC;
	prev_time = curr_time;
	cub()->window.fps = 1.0 / frame_time;
	mlx_string_put(cub()->window.mlx, cub()->window.win, 1860, 10, 0xFFFFFF,
		"fps");
	mlx_string_put(cub()->window.mlx, cub()->window.win, 1880, 10, 0xFFFFFF,
		ft_itoa((int)cub()->window.fps));
	mlx_string_put(cub()->window.mlx, cub()->window.win, 10, 1070, 0xFFFFFF,
		"@diogoforte & @chaleira");
}

int	draw_game(void)
{
	cub()->move();
	cub()->draw();
	fps();
	return (0);
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
		draw_menu,
		movement,
		{},
		{}
	};

	return (&cub);
}
