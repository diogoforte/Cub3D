/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:57:22 by plopes-c          #+#    #+#             */
/*   Updated: 2024/01/05 16:30:04 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_fov_minimap(void)
{
	ray()->angle = -(FOV / 2) + player()->angle;
	while (ray()->angle < (FOV / 2) + player()->angle)
	{
		draw_line(player()->pos[X], player()->pos[Y], ray()->angle, raycast(),
			0xFFF100);
		ray()->angle += ANGLE;
	}
}

int render(void)
{
	draw_fov();
	cub()->draw_minimap();
	// draw_fov_minimap();
	cub()->move();
	mlx_put_image_to_window(cub()->window.mlx, cub()->window.win,
		cub()->window.img.img, 0, 0);
	fps();
	return (0);
}