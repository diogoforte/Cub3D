/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:24:00 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/16 15:40:17 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	tile_size(void)
{
	if (WIDTH / cub()->map->map_width < HEIGHT / cub()->map->map_height)
		cub()->window.tile_size = WIDTH / cub()->map->map_width;
	else
		cub()->window.tile_size = HEIGHT / cub()->map->map_height;
	cub()->player.x *= cub()->window.tile_size;
	cub()->player.y *= cub()->window.tile_size;
	cub()->player.x += cub()->window.tile_size;
	cub()->player.y += cub()->window.tile_size;
}

static int	mouse_press(int button, int x, int y)
{
	t_map	*maps;
	int		menu_y;

	(void)x;
	if (button == MOUSE_LEFT && !cub()->map)
	{
		maps = cub()->maps;
		menu_y = 50;
		while (maps)
		{
			if (y >= menu_y && y < menu_y + 20 && maps->playable)
			{
				cub()->map = maps;
				cub()->player.x = cub()->map->start_x;
				cub()->player.y = cub()->map->start_y;
				tile_size();
				draw_map();
				return (0);
			}
			else if (y >= menu_y && y < menu_y + 20 && !maps->playable)
				printf("%s is not playable\n", maps->map_name);
			menu_y += 20;
			maps = maps->next;
		}
	}
	return (0);
}

void	draw_menu(void)
{
	t_map	*maps;
	int		y;

	if (!cub()->maps->next)
	{
		cub()->map = cub()->maps;
		tile_size();
		draw_map();
		return ;
	}
	maps = cub()->maps;
	mlx_clear_window(cub()->window.mlx, cub()->window.win);
	mlx_string_put(cub()->window.mlx, cub()->window.win, 20, 20, 0xFFFFFF,
		"Choose a map:");
	y = 50;
	while (maps)
	{
		if (maps->playable)
			mlx_string_put(cub()->window.mlx, cub()->window.win, 20, y += 20,
				0xFFFFFF, maps->map_name);
		else
		{
			mlx_string_put(cub()->window.mlx, cub()->window.win, 20, y += 20,
				0xFFFFFF, maps->map_name);
			mlx_string_put(cub()->window.mlx, cub()->window.win, 350, y,
				0xFFFFFF, "(not playable)");
			mlx_string_put(cub()->window.mlx, cub()->window.win, 600, y,
				0xFFFFFF, maps->error);
		}
		maps = maps->next;
	}
	mlx_mouse_hook(cub()->window.win, mouse_press, NULL);
}
