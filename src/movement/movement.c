/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:29:41 by dinunes-          #+#    #+#             */
/*   Updated: 2023/11/02 14:57:19 by plopes-c         ###   ########.fr       */
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

	x = cub()->player.pos[X] + key * (cub()->player.vector[X]);
	y = cub()->player.pos[Y] + key * (cub()->player.vector[Y]);
	if (!collision((int)x / SCALE, (int)cub()->player.pos[Y]
			/ SCALE))
		cub()->player.pos[X] = x;
	if (!collision((int)cub()->player.pos[X] / SCALE, (int)y
			/ SCALE))
		cub()->player.pos[Y] = y;
	cub()->player.map_pos[X] = cub()->player.pos[X] / SCALE;
	cub()->player.map_pos[Y] = cub()->player.pos[Y] / SCALE;
}

static void	strafe(int key)
{
	float	x;
	float	y;

	x = cub()->player.pos[X] + key * (cos(cub()->player.angle - (PI / 2)));
	y = cub()->player.pos[Y] + key * (sin(cub()->player.angle - (PI / 2)));
	if (!collision((x / SCALE), cub()->player.pos[Y] / SCALE))
		cub()->player.pos[X] = x;
	if (!collision((cub()->player.pos[X] / SCALE), y / SCALE))
		cub()->player.pos[Y] = y;
	cub()->player.map_pos[X] = cub()->player.pos[X] / SCALE;
	cub()->player.map_pos[Y] = cub()->player.pos[Y] / SCALE;
}

static void	rotateX(int key)
{
	cub()->player.angle += key * 0.001;
	if (cub()->player.angle < 0)
		cub()->player.angle += 2 * PI;
	if (cub()->player.angle > 2 * PI)
		cub()->player.angle -= 2 * PI;
	cub()->player.vector[X] = cos(cub()->player.angle);
	cub()->player.vector[Y] = sin(cub()->player.angle);
}

// static void rotateY(int key)
// {
// 	cub()->window.mid -= key;
// 	if (cub()->window.mid <= -(HEIGHT) || cub()->window.mid >= HEIGHT)
// 		cub()->window.mid += key;
	
// }

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
	mlx_mouse_get_pos(cub()->window.mlx, cub()->window.win, &cub()->player.mouse_x, &cub()->player.mouse_y);
	cub()->player.mouse_x -= (WIDTH / 2);
	rotateX(cub()->player.mouse_x);
	mlx_mouse_move(cub()->window.mlx, cub()->window.win, WIDTH / 2, HEIGHT / 2);
}
