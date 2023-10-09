/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 23:50:18 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/09 06:12:25 by dinunes-         ###   ########.fr       */
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
		err("Empty line in map.", map);
	map_destroy_map(map);
	if (tmp_map)
		map->map = tmp_map;
}

void	map_extract_data(t_map *map)
{
	static char	*arr[7] = {"NO ", "SO ", "WE ", "EA ", "F ", "C ", 0};
	int			i[3];
	char		*tmp;

	if (!map->playable)
		return ;
	i[0] = 0;
	i[2] = 0;
	while (map->map[i[0]] && i[2] < 6)
	{
		tmp = ft_strtrim(map->map[i[0]++], SPACERS);
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
	if (all_filled(map) || err("Missing texture.", map))
		map_extract_map(&map->map[i[0]], map);
}
