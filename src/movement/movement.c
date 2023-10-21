/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaleira <chaleira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:29:41 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/21 11:18:50 by chaleira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	collision(int x, int y)
{
	return (cub()->map->map[y + 1][x + 1] == '1');
}

static void	move(int key)
{
	float	x;
	float	y;

	x = cub()->player.x + key * cub()->player.delta_x * 0.8;
	y = cub()->player.y + key * cub()->player.delta_y * 0.8;
	if (!collision((int)x / cub()->window.tile_size, (int)cub()->player.y
			/ cub()->window.tile_size))
		cub()->player.x = x;
	if (!collision((int)cub()->player.x / cub()->window.tile_size, (int)y
			/ cub()->window.tile_size))
		cub()->player.y = y;
}

static void	strafe(int key)
{
	float	x;
	float	y;

	x = (cub()->player.x + key * cos(cub()->player.angle - (PI / 2)));
	y = (cub()->player.y + key * sin(cub()->player.angle - (PI / 2)));
	if (!collision((x / cub()->window.tile_size), cub()->player.y / cub()->window.tile_size))
		cub()->player.x = x;
	if (!collision((cub()->player.x / cub()->window.tile_size), y / cub()->window.tile_size))
		cub()->player.y = y;
}

static void	rotate(int key)
{
	cub()->player.angle += key * 0.05;
	if (cub()->player.angle < 0)
		cub()->player.angle += 2 * PI;
	if (cub()->player.angle > 2 * PI)
		cub()->player.angle -= 2 * PI;
	cub()->player.delta_x = cos(cub()->player.angle);
	cub()->player.delta_y = sin(cub()->player.angle);
}


void	movement(void)
{
	if (cub()->player.w)
		move(W);
	if (cub()->player.s)
		move(S);
	if (cub()->player.a)
		strafe(A);
	if (cub()->player.d)
		strafe(D);
	if (cub()->player.q)
		rotate(Q);
	if (cub()->player.e)
		rotate(E);
	// mlx_mouse_get_pos(cub()->window.mlx, cub()->window.win, &cub()->player.mouse_x, &cub()->player.mouse_y);
	// cub()->player.mouse_x -= (WIDTH / 2);
	// rotate(cub()->player.mouse_x);
	// mlx_mouse_move(cub()->window.mlx, cub()->window.win, WIDTH / 2, HEIGHT / 2);
}
