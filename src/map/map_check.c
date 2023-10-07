/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 06:45:19 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/07 12:41:28 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_check_variables(t_map *map)
{
	char	**tmp;
	int		i[2];

	if (WIDTH <= 0 || HEIGHT <= 0)
		err("Invalid resolution", map);
	else
	{
		i[0] = 3;
		while (++i[0] < 6 && map->playable)
		{
			if (ft_charcount(map->cords[i[0]], ',') != 2)
				err("Invalid color", map);
			tmp = ft_split(map->cords[i[0]], ',');
			i[1] = -1;
			while (tmp[++i[1]])
				if (ft_atoi(tmp[i[1]]) < 0 || ft_atoi(tmp[i[1]]) > 255)
					err("Invalid color", map);
			ft_freematrix(tmp);
		}
	}
}

void	map_check(t_map *map)
{
	map_check_variables(map);
	// map_check_map(map);
}
