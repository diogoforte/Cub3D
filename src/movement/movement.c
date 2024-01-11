/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:29:41 by dinunes-          #+#    #+#             */
/*   Updated: 2024/01/11 00:30:31 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	collision(double x, double y)
{
	int		x_arr[2];
	int		y_arr[2];

	x_arr[0] = (int)((x + (SCALE / 3)) / SCALE) + 1;
	x_arr[1] = (int)((x - (SCALE / 3)) / SCALE) + 1;
	y_arr[0] = (int)((y + (SCALE / 3)) / SCALE) + 1;
	y_arr[1] = (int)((y - (SCALE / 3)) / SCALE) + 1;
	if (cub()->map->map[(int)y_arr[0]][(int)x_arr[0]] == '1')
		return (true);
	if (cub()->map->map[(int)y_arr[0]][(int)x_arr[1]] == '1')
		return (true);
	if (cub()->map->map[(int)y_arr[1]][(int)x_arr[0]] == '1')
		return (true);
	if (cub()->map->map[(int)y_arr[1]][(int)x_arr[1]] == '1')
		return (true);
	return (false);
	// return (cub()->map->map[(int)y + 1][(int)x + 1] == '1');
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
	if (!collision(x, cub()->player.pos[Y]))
		cub()->player.pos[X] = x;
	if (!collision(cub()->player.pos[X], y))
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

static void rotateY(int key)
{
	cub()->window.mid -= key;
	if (cub()->window.mid <= -(HEIGHT / 2) || cub()->window.mid >= HEIGHT / 2)
		cub()->window.mid += key;
	
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
	cub()->player.mouse_y -= (HEIGHT / 2);
	rotate(cub()->player.mouse_x);
	rotateY(cub()->player.mouse_y);
	mlx_mouse_move(cub()->window.mlx, cub()->window.win, WIDTH / 2, HEIGHT / 2);
}
