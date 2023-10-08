/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:16:57 by chaleira          #+#    #+#             */
/*   Updated: 2023/10/08 01:57:31 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	err(char *str, t_map *map)
{
	if (map)
	{
		if (!map->error)
			map->error = ft_strdup(str);
		else
			ft_strjoin_address(&map->error, str);
		map->playable = false;
	}
	while (str && *str)
		write(2, str++, 1);
	write(2, "\n", 1);
	cub()->status = 1;
	return (1);
}

void	exit_cub(char *str)
{
	cub()->maps_destroy();
	if (str)
		exit(err(str, NULL));
	else
		exit(cub()->status);
}

void	maps_destroy(void)
{
	t_map	*tmp;
	t_map	*map;
	
	map = cub()->map;
	while (map)
	{
		tmp = map->next;
		map->destroy_map(map);
		map->destroy_error(map);
		map->destroy_cords(map);
		if (map)
			free(map);
		map = tmp;
	}
	map = NULL;
}
