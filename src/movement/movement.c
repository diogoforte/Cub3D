/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:29:41 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/17 12:44:54 by dinunes-         ###   ########.fr       */
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

	x = cub()->player.x + key * cub()->player.delta_x;
	y = cub()->player.y + key * cub()->player.delta_y;
	if (!collision((int)x / cub()->window.tile_size, (int)y
			/ cub()->window.tile_size))
	{
		cub()->player.x = x;
		cub()->player.y = y;
	}
}

static void	strafe(int key)
{
	float	x;
	float	y;

	x = (cub()->player.x + key * cos(cub()->player.angle - (PI / 2)) * 5);
	y = (cub()->player.y + key * sin(cub()->player.angle - (PI / 2)) * 5);
	if (!collision((int)x / cub()->window.tile_size, (int)y
			/ cub()->window.tile_size))
	{
		cub()->player.x = x;
		cub()->player.y = y;
	}
}

static void	rotate(int key)
{
	cub()->player.angle += key * 0.1;
	if (cub()->player.angle < 0)
		cub()->player.angle += 2 * PI;
	if (cub()->player.angle > 2 * PI)
		cub()->player.angle -= 2 * PI;
	cub()->player.delta_x = cos(cub()->player.angle) * 5;
	cub()->player.delta_y = sin(cub()->player.angle) * 5;
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
}
