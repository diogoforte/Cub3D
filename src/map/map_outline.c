/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_outline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:51:49 by dinunes-          #+#    #+#             */
/*   Updated: 2024/01/26 10:54:02 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**create_new_map(t_map *map, char c)
{
	char	**new_map;
	char	*tmp;

	new_map = ft_calloc(map->map_height + 3, sizeof(char *));
	tmp = ft_calloc(map->map_width + 3, sizeof(char));
	ft_memset(tmp, c, map->map_width + 2);
	new_map[0] = ft_strdup(tmp);
	new_map[map->map_height + 1] = ft_strdup(tmp);
	free(tmp);
	return (new_map);
}

void	copy_old_map_to_new(t_map *map, char **new_map, char c)
{
	char	*tmp;
	int		i[3];

	i[0] = -1;
	i[2] = 0;
	while (++i[0] < map->map_height)
	{
		i[2] = ft_strlen(map->map[i[0]]);
		tmp = ft_calloc(map->map_width + 3, sizeof(char));
		ft_memset(tmp, c, map->map_width + 2);
		i[1] = -1;
		while (++i[1] < i[2])
			if (map->map[i[0]][i[1]] != c)
				tmp[i[1] + 1] = map->map[i[0]][i[1]];
		new_map[i[0] + 1] = tmp;
	}
}

void	map_add_outline(t_map *map, char c)
{
	char	**new_map;

	new_map = create_new_map(map, c);
	copy_old_map_to_new(map, new_map, c);
	map->destroy_map(map);
	map->map = new_map;
	map->map_height += 2;
	map->map_width += 2;
}
