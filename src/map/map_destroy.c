/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaleira <chaleira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 05:32:33 by chaleira          #+#    #+#             */
/*   Updated: 2023/10/07 06:03:53 by chaleira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void map_destroy_file(t_map *map)
{
	if (map->file)
		ft_freematrix(map->file);
	map->file = NULL;
}

void map_destroy_map(t_map *map)
{
	if (map->map)
		ft_freematrix(map->map);
	map->map = NULL;
}

void map_destroy_error(t_map *map)
{
	if (map->error)
		free(map->error);
	map->error = NULL;
}

void map_destroy_cords(t_map *map)
{
	int i;

	i = -1;
	while (++i < 6)
		if (map->cords[i])
		{
			free(map->cords[i]);
			map->cords[i] = NULL;
		}
}