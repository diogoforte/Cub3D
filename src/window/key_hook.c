/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:25:58 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/16 15:40:09 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode)
{
	printf("keycode: %d\n", keycode);
	if (keycode == KEY_ESC)
		cub()->exit(NULL);
	if (keycode == KEY_F1)
	{
		cub()->map = NULL;
		draw_menu();
	}
	if (!cub()->map)
		return (0);
	else if (keycode == KEY_W)
		cub()->player.y -= cub()->window.tile_size;
	else if (keycode == KEY_S)
		cub()->player.y += cub()->window.tile_size;
	else if (keycode == KEY_A)
		cub()->player.x -= cub()->window.tile_size;
	else if (keycode == KEY_D)
		cub()->player.x += cub()->window.tile_size;
	draw_map();
	return (0);
}
