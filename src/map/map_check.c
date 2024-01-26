/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:45:33 by dinunes-          #+#    #+#             */
/*   Updated: 2024/01/26 10:51:35 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_open_rooms(t_map *map, int x, int y, char *str);
void	matrix_char_to_char(char **matrix, char old, char new);
int		check_all_rooms(t_map *map);

void	map_check(t_map *map)
{
	if (!map->playable || map_invalid_char(map))
		return ;
	map_add_outline(map, OUTLINE);
	check_open_rooms(map, 0, 0, "Map not closed");
	check_all_rooms(map);
	matrix_char_to_char(map->map, FILLER, ' ');
}

int	map_invalid_char(t_map *map)
{
	int	i[3];

	i[0] = -1;
	i[2] = 0;
	while (map->map && map->map[++i[0]])
	{
		i[1] = -1;
		while (map->map && map->map[i[0]][++i[1]])
		{
			if (!ft_strchr(VALID_CHARS, map->map[i[0]][i[1]]))
				exit_cub("Invalid map character");
			if (ft_strchr(PLAYER_START, map->map[i[0]][i[1]]))
			{
				if (++i[2] == 2)
					exit_cub("Multiple starting positions");
				map->start_dir = map->map[i[0]][i[1]];
				map->start_x = i[1] - 1;
				map->start_y = i[0] - 1;
			}
		}
	}
	if (!i[2])
		exit_cub("No starting position");
	return (0);
}

int	check_open_rooms(t_map *map, int x, int y, char *str)
{
	if ((x < 0 || y < 0) || (x > map->map_width + 1 || y > map->map_height + 1)
		|| !map->playable)
		return (0);
	if (!map->map[y] || !map->map[y][x])
		return (0);
	if (ft_strchr(PLAYER_START, map->map[y][x]))
		exit_cub(str);
	if (map->map[y][x] == WALL || map->map[y][x] == FILLER)
		return (0);
	map->map[y][x] = FILLER;
	check_open_rooms(map, x + 1, y, str);
	check_open_rooms(map, x - 1, y, str);
	check_open_rooms(map, x, y + 1, str);
	check_open_rooms(map, x, y - 1, str);
	return (0);
}

int	check_all_rooms(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map && map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == ' ')
				check_open_rooms(map, j, i, "Empty space in map");
			j++;
		}
		i++;
	}
	return (0);
}
