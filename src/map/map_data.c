/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 23:50:18 by dinunes-          #+#    #+#             */
/*   Updated: 2024/01/26 13:40:20 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_extract_map(char **grid, t_map *map)
{
	char	*tmp;
	char	**tmp_map;

	tmp_map = NULL;
	while (grid && *grid && !ft_strcmp(*grid, "\n"))
		grid++;
	while (grid && *grid && ft_strcmp(*grid, "\n"))
	{
		tmp = ft_strtrim(*grid, "\t\n\v\f\r");
		if (tmp && *tmp)
			ft_matrixadd_back(&tmp_map, tmp);
		free(tmp);
		grid++;
	}
	while (grid && *grid && !ft_strcmp(*grid, "\n"))
		grid++;
	if (grid && *grid)
		exit_cub("Empty line in map");
	map_destroy_map(map);
	map->map = tmp_map;
	if (!tmp_map)
		exit_cub("Error in file configuration");
}

int	map_check_colors(t_map *map)
{
	char	**tmp;
	int		i[2];

	if (!map->playable)
		return (1);
	i[0] = 3;
	while (++i[0] < 6 && map->playable)
	{
		if (ft_charcount(map->cords[i[0]], ',') != 2)
			exit_cub("Invalid color");
		tmp = ft_split(map->cords[i[0]], ',');
		i[1] = -1;
		while (tmp[++i[1]])
			if (ft_atoi(tmp[i[1]]) < 0 || ft_atoi(tmp[i[1]]) > 255)
				exit_cub("Invalid color");
		ft_freematrix(tmp);
	}
	return (0);
}

void	rgb_to_hex(t_map *map)
{
	int		r;
	int		g;
	int		b;
	int		i;
	char	**colors;

	if (map_check_colors(map))
		return ;
	i = -1;
	while (++i < 2)
	{
		colors = ft_split(map->cords[i + 4], ',');
		if ((!colors[0] || !colors[1] || !colors[2]))
		{
			exit_cub("Invalid color");
			ft_freematrix(colors);
			return ;
		}
		r = ft_atoi(colors[0]);
		g = ft_atoi(colors[1]);
		b = ft_atoi(colors[2]);
		ft_freematrix(colors);
		map->fc[i] = (r << 16) | (g << 8) | b;
	}
}

void	map_data(t_map *map, int i[3], char *arr[7])
{
	char	*tmp;

	while (map->map[++i[0]] && i[2] < 6)
	{
		tmp = ft_strtrim(map->map[i[0]], SPACERS);
		if (tmp && *tmp)
		{
			i[1] = -1;
			while (arr[++i[1]])
			{
				if (tmp[0] == arr[i[1]][0] && tmp[1] == arr[i[1]][1]
					&& (i[0] > 3 || tmp[2] == arr[i[1]][2]))
				{
					i[2] += (map->cords[i[1]] == NULL);
					free(map->cords[i[1]]);
					map->cords[i[1]] = ft_strtrim(tmp + 2, SPACERS);
				}
			}
		}
		free(tmp);
	}
}

void	map_extract_data(t_map *map)
{
	static char	*arr[7] = {"NO ", "SO ", "WE ", "EA ", "F ", "C ", 0};
	int			i[3];

	i[0] = -1;
	i[2] = 0;
	map_data(map, i, arr);
	rgb_to_hex(map);
	if (all_filled(map) || exit_cub("Missing parameter"))
		map_extract_map(&map->map[i[0]], map);
}
