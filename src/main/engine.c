/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:30:00 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/05 22:16:33 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_engine	*engine(void)
{
	static t_engine	engine;

	return (&engine);
}

void	engine_start(void)
{
	// engine()->mlx = mlx_init();
	// engine()->win = mlx_new_window(engine()->mlx, WIDTH, HEIGHT, "cub3D");
	engine()->free = &engine_free;
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

// void	engine_free(t_map *map)
// {
// 	// mlx_destroy_window(engine()->mlx, engine()->win);
// 	// if (engine()->mlx)
// 	// 	free(engine()->mlx);
// 	free(map->cords[NO]);
// 	free(map->cords[SO]);
// 	free(map->cords[WE]);
// 	free(map->cords[EA]);
// 	free(map->cords[F]);
// 	free(map->cords[C]);
// 	if (map->grid)
// 		free_split(map->grid);
// 	if (map->map)
// 		free_split(map->map);
// 	ft_bzero(map, sizeof(t_map));
// }
