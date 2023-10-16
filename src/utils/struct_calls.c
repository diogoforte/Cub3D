/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_calls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:04:19 by chaleira          #+#    #+#             */
/*   Updated: 2023/10/16 22:30:13 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	colision(int x, int y)
{
	// printf("%i, %i\n",x, y);
	if (x >= WIDTH || y >= HEIGHT || x < 1 || y < 1)
		return false;
	return (cub()->map->map[y][x] == '1');
}

void	movement(void)
{
	if (cub()->player.w && !colision((int)cub()->player.x / cub()->window.tile_size , (int)(cub()->player.y - 5) / cub()->window.tile_size))
		cub()->player.y -= 5;
	if (cub()->player.a && !colision((int)(cub()->player.x - 5) / cub()->window.tile_size, (int)cub()->player.y / cub()->window.tile_size))
		cub()->player.x -= 5;
	if (cub()->player.s && !colision((int)cub()->player.x / cub()->window.tile_size, (int)(cub()->player.y + 5) / cub()->window.tile_size))
		cub()->player.y += 5;
	if (cub()->player.d && !colision((int)(cub()->player.x + 5) / cub()->window.tile_size, (int)cub()->player.y / cub()->window.tile_size))
		cub()->player.x += 5;
}

int draw_game(void)
{
	cub()->move();
	cub()->draw();
	
	
	return (0);
}

t_cub	*cub(void)
{
	static t_cub cub = {
		NULL,
		NULL,
		0,
		map_add_list,
		map_load,
		exit_cub,
		maps_destroy,
		map_new,
		NULL,
		draw_menu,
		movement,
		{},
		{}
	};

	return (&cub);
}
