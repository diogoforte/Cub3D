/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaleira <chaleira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:30:00 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/06 19:34:51 by chaleira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_engine	*engine(void)
{
	static t_engine	engine;

	return (&engine);
}

void	engine_start(int argc)
{
	engine()->map = ft_calloc(argc, sizeof(t_map *));
	engine()->maps_init = &maps_loader;
	engine()->free = &engine_free;
	engine()->exit = &do_exit;
	// engine()->mlx = mlx_init();
	// engine()->win = mlx_new_window(engine()->mlx, WIDTH, HEIGHT, "cub3D");
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	engine_free(t_map *map)
{
	// mlx_destroy_window(engine()->mlx, engine()->win);
	// if (engine()->mlx)
	// 	free(engine()->mlx);
	if (map->cords[NO])
		free(map->cords[NO]);
	if (map->cords[SO])
		free(map->cords[SO]);
	if (map->cords[WE])
		free(map->cords[WE]);
	if (map->cords[EA])
		free(map->cords[EA]);
	if (map->cords[F])
		free(map->cords[F]);
	if (map->cords[C])
		free(map->cords[C]);
	if (map->grid)
		free_split(map->grid);
	if (map->map)
		free_split(map->map);
}

