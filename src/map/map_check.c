/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:45:33 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/08 02:02:47 by dinunes-         ###   ########.fr       */
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

void	map_add_outline(t_map *map)
{
	char	**new_map;
	char	*tmp;
	int i[5];

	i[4] = ft_matrix_len(map->map);
	i[3] = matrix_biggest_string(map->map);
	new_map = ft_calloc(i[4] + 3, sizeof(char *));
	tmp = ft_calloc(i[3] + 3, sizeof(char));
	ft_memset(tmp, '_', i[3] + 2);
	new_map[0] = tmp;
	new_map[i[4] + 1] = tmp;
	i[0] = -1;
	i[2] = 0;
	while (++i[0] < i[4])
	{
		i[2] = ft_strlen(map->map[i[0]]);
		tmp = ft_calloc(i[3] + 3, sizeof(char));
		ft_memset(tmp, '_', i[3] + 2);
		i[1] = -1;
		while (++i[1] < i[2])
			if (map->map[i[0]][i[1]] != ' ')
				tmp[i[1] + 1] = map->map[i[0]][i[1]];
		new_map[i[0] + 1] = tmp;
	}
	map_destroy_map(map);
	map->map = new_map;
}

void	map_check(t_map *map)
{
	map_check_variables(map);
	map_add_outline(map);
	// map_check_map(map);
}
