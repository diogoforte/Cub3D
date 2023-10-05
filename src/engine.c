/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:30:00 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/05 07:04:20 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_engine	*engine(void)
{
	static t_engine	engine;

	return (&engine);
}

void	engine_start(void)
{
	engine()->mlx = mlx_init();
	engine()->win = mlx_new_window(engine()->mlx, WIDTH, HEIGHT, "cub3D");
	engine()->free = &engine_free;
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	engine_free(t_map *map)
{
	// mlx_destroy_window(engine()->mlx, engine()->win);
	// if (engine()->mlx)
	// 	free(engine()->mlx);
	if (map->C)
		free(map->C);
	if (map->F)
		free(map->F);
	if (map->EA)
		free(map->EA);
	if (map->WE)
		free(map->WE);
	if (map->SO)
		free(map->SO);
	if (map->NO)
		free(map->NO);
	if (map->grid)
		free_split(map->grid);
	
}
