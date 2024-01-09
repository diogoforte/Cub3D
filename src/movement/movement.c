/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:29:41 by dinunes-          #+#    #+#             */
/*   Updated: 2024/01/09 13:22:30 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	collision(int x, int y)
{
	return (cub()->map->map[y + 1][x + 1] == '1');
}

static void	move_and_strafe(int move_key, int strafe_key)
{
	float	x;
	float	y;
	float	norm;
	float	dir_x;
	float	dir_y;

	dir_x = move_key * cub()->player.vector[X] + strafe_key
		* cos(cub()->player.angle - (PI / 2));
	dir_y = move_key * cub()->player.vector[Y] + strafe_key
		* sin(cub()->player.angle - (PI / 2));
	norm = sqrt(pow(dir_x, 2) + pow(dir_y, 2));
	if (norm != 0)
	{
		dir_x /= norm;
		dir_y /= norm;
	}
	x = cub()->player.pos[X] + dir_x * MOVE_SPEED * cub()->window.frame_time;
	y = cub()->player.pos[Y] + dir_y * MOVE_SPEED * cub()->window.frame_time;
	if (!collision((int)x / SCALE, (int)cub()->player.pos[Y] / SCALE))
		cub()->player.pos[X] = x;
	if (!collision((int)cub()->player.pos[X] / SCALE, (int)y / SCALE))
		cub()->player.pos[Y] = y;
	cub()->player.map_pos[X] = cub()->player.pos[X] / SCALE;
	cub()->player.map_pos[Y] = cub()->player.pos[Y] / SCALE;
}

static void	rotate(int key)
{
	cub()->player.angle += key * ROT_SPEED * cub()->window.frame_time;
	if (cub()->player.angle < 0)
		cub()->player.angle += 2 * PI;
	if (cub()->player.angle > 2 * PI)
		cub()->player.angle -= 2 * PI;
	cub()->player.vector[X] = cos(cub()->player.angle);
	cub()->player.vector[Y] = sin(cub()->player.angle);
}

void	movement(void)
{
	int	move_direction;
	int	strafe_direction;

	move_direction = 0;
	strafe_direction = 0;
	if (cub()->player.w)
		move_direction += W;
	if (cub()->player.s)
		move_direction += S;
	if (cub()->player.a)
		strafe_direction += A;
	if (cub()->player.d)
		strafe_direction += D;
	move_and_strafe(move_direction, strafe_direction);
	if (cub()->player.q)
		rotate(Q);
	if (cub()->player.e)
		rotate(E);
	mlx_mouse_get_pos(cub()->window.mlx, cub()->window.win,
		&cub()->player.mouse_x, &cub()->player.mouse_y);
	cub()->player.mouse_x -= (WIDTH / 2);
	rotate(cub()->player.mouse_x);
	mlx_mouse_move(cub()->window.mlx, cub()->window.win, WIDTH / 2, HEIGHT / 2);
}
