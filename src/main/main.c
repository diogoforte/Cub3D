/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaleira <chaleira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:08:35 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/06 03:20:40 by chaleira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	engine_start(ac);
	if (ac < 2)
		engine()->exit("Usage: ./cub3D <map.cub> ...");
	engine()->maps_init(av);
	for (t_map *map = *engine()->map; map; map = map->next)
	{
		if (map->playable)
			print_vars(map);
	}
	engine()->exit(NULL);
}
