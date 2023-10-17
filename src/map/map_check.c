/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:45:33 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/17 11:49:24 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
int	check_open_rooms(t_map	*map, int x, int y, char c, char *str);
void matrix_char_to_char(char **matrix, char old, char new);
int check_all_rooms(t_map *map);

int	map_check_variables(t_map *map)
{
	char	**tmp;
	int		i[2];

	if (!map->playable)
		return (1);
	if (WIDTH <= 0 || HEIGHT <= 0)
		return (err("Invalid resolution", map));
	else
	{
		i[0] = 3;
		while (++i[0] < 6 && map->playable)
		{
			if (ft_charcount(map->cords[i[0]], ',') != 2)
				return (err("Invalid color", map));
			tmp = ft_split(map->cords[i[0]], ',');
			i[1] = -1;
			while (tmp[++i[1]])
				if (ft_atoi(tmp[i[1]]) < 0 || ft_atoi(tmp[i[1]]) > 255)
					err("Invalid color", map);
			ft_freematrix(tmp);
		}
	}
	return (0);
}

void	map_add_outline(t_map *map, char c)
{
	char	**new_map;
	char	*tmp;
	int		i[3];

	new_map = ft_calloc(map->map_height + 3, sizeof(char *));
	tmp = ft_calloc(map->map_width + 3, sizeof(char));
	ft_memset(tmp, c, map->map_width + 2);
	new_map[0] = ft_strdup(tmp);
	new_map[map->map_height + 1] = ft_strdup(tmp);
	free(tmp);
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
	map->destroy_map(map);
	map->map = new_map;
	map->map_height += 2;
	map->map_width += 2;
}

void	map_check(t_map *map)
{
	if (map_check_variables(map) || map_invalid_char(map))
		return ;
	map_add_outline(map, OUTLINE);
	check_open_rooms(map, 0, 0, -2, "Map not closed");
	check_all_rooms(map);
	matrix_char_to_char(map->map, -2, ' ');
}

int	map_invalid_char(t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (map->map && map->map[++i])
	{
		j = -1;
		while (map->map && map->map[i][++j])
		{
			if (!ft_strchr(VALID_CHARS, map->map[i][j]))
					return (err("Invalid map character", map));
			if (ft_strchr(PLAYER_START, map->map[i][j]))
			{
				if (++k == 2)
					return (err("Multiple starting positions", map));
				map->start_x = j - 1;
				map->start_y = i - 1;
			}
		}
	}
	if (k == 0)
		return (err("No starting position", map));
	return (0);
}

int	check_open_rooms(t_map	*map, int x, int y, char c, char *str)
{
	if ((x < 0 || y < 0)
		|| (x > map->map_width + 1 || y > map->map_height + 1)
		|| !map->playable)
		return (0);
	if (!map->map[y] || !map->map[y][x])
		return (0);
	if (ft_strchr(PLAYER_START, map->map[y][x]))
		return (err(str, map));
	if (map->map[y][x] == WALL || map->map[y][x] == c)
			return (0);
	map->map[y][x] = c;
	check_open_rooms(map, x + 1, y, c, str);
	check_open_rooms(map, x - 1, y, c, str);
	check_open_rooms(map, x, y + 1, c, str);
	check_open_rooms(map, x, y - 1, c, str);
	return (0);
}

int check_all_rooms(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (map->map && map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == ' ')
				check_open_rooms(map, j, i, -2, "Empty space in map");
			j++;
		}
		i++;
	}
	return (0);
}

void matrix_char_to_char(char **matrix, char old, char new)
{
	int i;
	int j;

	i = 0;
	while (matrix && matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == old)
				matrix[i][j] = new;
			j++;
		}
		i++;
	}
}
