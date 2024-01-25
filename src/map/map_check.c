/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:45:33 by dinunes-          #+#    #+#             */
/*   Updated: 2024/01/25 19:46:10 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_open_rooms(t_map *map, int x, int y, char c, char *str);
void	matrix_char_to_char(char **matrix, char old, char new);
int		check_all_rooms(t_map *map);

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
	if (!map->playable || map_invalid_char(map))
		return ;
	map_add_outline(map, OUTLINE);
	check_open_rooms(map, 0, 0, FILLER, "Map not closed");
	check_all_rooms(map);
	matrix_char_to_char(map->map, FILLER, ' ');
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
				exit_cub("Invalid map character");
			if (ft_strchr(PLAYER_START, map->map[i][j]))
			{
				if (++k == 2)
					exit_cub("Multiple starting positions");
				map->start_dir = map->map[i][j];
				map->start_x = j - 1;
				map->start_y = i - 1;
			}
		}
	}
	if (k == 0)
		exit_cub("No starting position");
	return (0);
}

int	check_open_rooms(t_map *map, int x, int y, char c, char *str)
{
	if ((x < 0 || y < 0) || (x > map->map_width + 1 || y > map->map_height + 1)
		|| !map->playable)
		return (0);
	if (!map->map[y] || !map->map[y][x])
		return (0);
	if (ft_strchr(PLAYER_START, map->map[y][x]))
		exit_cub(str);
	if (map->map[y][x] == WALL || map->map[y][x] == c)
		return (0);
	map->map[y][x] = c;
	check_open_rooms(map, x + 1, y, c, str);
	check_open_rooms(map, x - 1, y, c, str);
	check_open_rooms(map, x, y + 1, c, str);
	check_open_rooms(map, x, y - 1, c, str);
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
				check_open_rooms(map, j, i, FILLER, "Empty space in map");
			j++;
		}
		i++;
	}
	return (0);
}

void	matrix_char_to_char(char **matrix, char old, char new)
{
	int	i;
	int	j;

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
