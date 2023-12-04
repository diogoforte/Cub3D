/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_calls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:04:19 by chaleira          #+#    #+#             */
/*   Updated: 2023/12/04 14:27:43 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <time.h>

void	fps(void)
{
	static clock_t	prev_time;
	clock_t			curr_time;
	double			frame_time;
	char			tmp[12];

	curr_time = clock();
	frame_time = (double)(curr_time - prev_time) / CLOCKS_PER_SEC;
	prev_time = curr_time;
	cub()->window.fps = 1.0 / frame_time;
	// mlx_string_put(cub()->window.mlx, cub()->window.win, WIDTH - (WIDTH / cub()->window.tile_size) - 10, 10, 0xFFFFFF,
	// 	"fps");
	mlx_string_put(cub()->window.mlx, cub()->window.win, WIDTH - 50, 10, 0xFFFFFF,
		ft_itoa_address(tmp, (int)cub()->window.fps));
	mlx_string_put(cub()->window.mlx, cub()->window.win, 10, 1070, 0xFFFFFF,
		"@diogoforte & @chaleira");
}

// int	render(void)
// {
// 	cub()->draw_screen();
// 	cub()->draw_minimap();
// 	cub()->move();
// 	mlx_put_image_to_window(cub()->window.mlx, cub()->window.win,
// 		cub()->window.img.img, 0, 0);
// 	fps();
// 	return (0);
// }

t_player	*player(void)
{
	return (&cub()->player);
}

t_window	*window(void)
{
	return (&cub()->window);
}

t_ray	*ray(void)
{
	return (&cub()->player.ray);
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
