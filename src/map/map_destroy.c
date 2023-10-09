/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 05:32:33 by chaleira          #+#    #+#             */
/*   Updated: 2023/10/09 01:42:48 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_destroy_map(t_map *map)
{
	if (map->map)
		ft_freematrix(map->map);
	map->map = NULL;
}

void	map_destroy_error(t_map *map)
{
	if (map->error)
		free(map->error);
	map->error = NULL;
}

void	map_destroy_cords(t_map *map)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (map->cords[i])
		{
			free(map->cords[i]);
			map->cords[i] = NULL;
		}
	}
}
