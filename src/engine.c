/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:30:00 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/04 03:13:28 by dinunes-         ###   ########.fr       */
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

void	engine_free(void)
{
	mlx_destroy_window(engine()->mlx, engine()->win);
	if (engine()->mlx)
		free(engine()->mlx);
}
