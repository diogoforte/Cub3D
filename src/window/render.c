/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:57:22 by plopes-c          #+#    #+#             */
/*   Updated: 2024/01/08 17:31:24 by dinunes-         ###   ########.fr       */
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
	double			curr_pos[2] = {player()->pos[X], player()->pos[Y]};
	static double	prev_pos[2] = {0, 0};
	double			distance;
	double			speed;

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
	long int		elapsed_ns;
	struct timespec	start;
	struct timespec	end;

	clock_gettime(CLOCK_MONOTONIC, &start);
	draw_fov_threads();
	draw_minimap();
	movement();
	mlx_put_image_to_window(cub()->window.mlx, cub()->window.win,
		cub()->window.img.img, 0, 0);
	mlx_string_put(cub()->window.mlx, cub()->window.win, 10, 1070, 0xFFFFFF,
		"@diogoforte & @chaleira");
	speed();
	fps();
	clock_gettime(CLOCK_MONOTONIC, &end);
	elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000L + (end.tv_nsec
			- start.tv_nsec);
	while (elapsed_ns < FRAME_TIME_NS)
	{
		clock_gettime(CLOCK_MONOTONIC, &end);
		elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000L + (end.tv_nsec
				- start.tv_nsec);
	}
	return (0);
}

// int	render(void)
// {
// 	draw_fov_threads();
// 	draw_minimap();
// 	movement();
// 	mlx_put_image_to_window(cub()->window.mlx, cub()->window.win,
// 		cub()->window.img.img, 0, 0);
// 	fps();
// 	return (0);
// }
