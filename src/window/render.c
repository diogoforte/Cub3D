/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:57:22 by plopes-c          #+#    #+#             */
/*   Updated: 2024/01/06 12:56:13 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render(void)
{
	draw_fov();
	cub()->draw_minimap();
	cub()->move();
	mlx_put_image_to_window(cub()->window.mlx, cub()->window.win,
		cub()->window.img.img, 0, 0);
	fps();
	return (0);
}
