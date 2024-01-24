/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:57:22 by plopes-c          #+#    #+#             */
/*   Updated: 2024/01/24 18:13:31 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fps(void)
{
	static clock_t	prev_time;
	clock_t			curr_time;
	char			tmp[12];

	curr_time = clock();
	cub()->window.frame_time = (double)(curr_time - prev_time) / CLOCKS_PER_SEC;
	prev_time = curr_time;
	cub()->window.fps = 1.0 / cub()->window.frame_time;
	mlx_string_put(cub()->window.mlx, cub()->window.win, WIDTH - 50, 10,
		0xFFFFFF, ft_itoa_address(tmp, (int)cub()->window.fps));
}

void	speed(void)
{
	char			tmp[12];
	double			curr_pos[2];
	static double	prev_pos[2] = {0, 0};
	double			distance;
	double			speed;

	curr_pos[X] = player()->pos[X];
	curr_pos[Y] = player()->pos[Y];
	distance = sqrt(pow(curr_pos[X] - prev_pos[X], 2) + pow(curr_pos[Y]
				- prev_pos[Y], 2));
	speed = distance / cub()->window.frame_time;
	prev_pos[X] = curr_pos[X];
	prev_pos[Y] = curr_pos[Y];
	mlx_string_put(cub()->window.mlx, cub()->window.win, WIDTH - 50, 30,
		0xFFFFFF, ft_itoa_address(tmp, (int)round(speed) / SCALE));
}

int	render(void)
{
	if (!cub()->map->playable)
		return (1);
	draw_fov_threads();
	draw_minimap();
	movement();
	mlx_put_image_to_window(cub()->window.mlx, cub()->window.win,
		cub()->window.img.img, 0, 0);
	mlx_string_put(cub()->window.mlx, cub()->window.win, 10, 1070, 0xFFFFFF,
		"@diogoforte & @chaleira");
	speed();
	fps();
	return (0);
}
