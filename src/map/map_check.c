/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:45:33 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/09 00:41:03 by dinunes-         ###   ########.fr       */
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
	int		i[3];

	new_map = ft_calloc(map->map_height + 3, sizeof(char *));
	tmp = ft_calloc(map->map_width + 3, sizeof(char));
	ft_memset(tmp, OUTLINE, map->map_width + 2);
	new_map[0] = ft_strdup(tmp);
	new_map[map->map_height + 1] = ft_strdup(tmp);
	free(tmp);
	i[0] = -1;
	i[2] = 0;
	while (++i[0] < map->map_height)
	{
		i[2] = ft_strlen(map->map[i[0]]);
		tmp = ft_calloc(map->map_width + 3, sizeof(char));
		ft_memset(tmp, OUTLINE, map->map_width + 2);
		i[1] = -1;
		while (++i[1] < i[2])
			if (map->map[i[0]][i[1]] != ' ')
				tmp[i[1] + 1] = map->map[i[0]][i[1]];
		new_map[i[0] + 1] = tmp;
	}
	map->destroy_map(map);
	map->map = new_map;
}

void	flood_fill(t_map *map, int x, int y, char **visited)
{
	if (visited[y][x] == WALL || !map->playable)
		return ;
	if (visited[y][x] == OUTLINE)
	{
		err("Map not surrounded by walls.", map);
		return ;	
	}
	visited[y][x] = WALL;
	flood_fill(map, x + 1, y, visited);
	flood_fill(map, x - 1, y, visited);
	flood_fill(map, x, y + 1, visited);
	flood_fill(map, x, y - 1, visited);
	return ;
}

void	map_check_map(t_map *map)
{
	int		i[2];
	char	**visited = NULL;

	i[0] = -1;
	visited = ft_calloc(map->map_height + 3, sizeof(char *));
	while (++i[0] < map->map_height + 2)
		visited[i[0]] = ft_strdup(map->map[i[0]]);
	i[0] = -1;
	while (++i[0] < map->map_height + 2)
	{
		i[1] = -1;
		while (++i[1] < map->map_width)
		{
			if (map->map[i[0]][i[1]] == 'N' || map->map[i[0]][i[1]] == 'S'
				|| map->map[i[0]][i[1]] == 'E' || map->map[i[0]][i[1]] == 'W')
			{
				map->start_x = i[1];
				map->start_y = i[0];
				break ;
			}
		}
	}
	if (!map->start_x || !map->start_y)
		err("No starting position.", map);
	flood_fill(map, map->start_x, map->start_y, visited);
	ft_freematrix(visited);
}

void	map_check(t_map *map)
{
	map_check_variables(map);
	map_add_outline(map);
	map_check_map(map);
}
