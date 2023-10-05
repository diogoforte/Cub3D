/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:08:35 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/05 20:17:08 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	if (ac < 2)
		do_exit("Usage: ./cub3D <map.cub> ...");
	engine_start();
	maps_loader(av, ac);
	for (t_map *map = *engine()->map; map; map = map->next)
	{
		if (map->playable)
			print_vars(map);
	}
	do_exit(NULL);
	return (0);
}
