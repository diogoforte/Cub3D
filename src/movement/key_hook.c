/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:28:27 by plopes-c          #+#    #+#             */
/*   Updated: 2023/12/04 14:28:44 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode)
{
	if (!cub()->map)
		return (0);
	if (keycode == KEY_ESC)
		cub()->exit(NULL);
	if (keycode == KEY_W)
		cub()->player.w = true;
	else if (keycode == KEY_A)
		cub()->player.a = true;
	else if (keycode == KEY_S)
		cub()->player.s = true;
	else if (keycode == KEY_D)
		cub()->player.d = true;
	else if (keycode == KEY_Q)
		cub()->player.q = true;
	else if (keycode == KEY_E)
		cub()->player.e = true;
	return (0);
}

int	key_release(int keycode)
{
	if (!cub()->map)
		return (0);
	if (keycode == KEY_W)
		cub()->player.w = false;
	else if (keycode == KEY_A)
		cub()->player.a = false;
	else if (keycode == KEY_S)
		cub()->player.s = false;
	else if (keycode == KEY_D)
		cub()->player.d = false;
	else if (keycode == KEY_Q)
		cub()->player.q = false;
	else if (keycode == KEY_E)
		cub()->player.e = false;
	return (0);
}
