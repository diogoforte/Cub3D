/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 23:50:18 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/08 02:01:40 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_extract_map(char **grid, t_map *map)
{
	char	*tmp;
	t_map	*tmp_map = ft_calloc(1, sizeof(t_map));

	while (grid && *grid && !ft_strcmp(*grid, "\n"))
		grid++;
	while (grid && *grid && ft_strcmp(*grid, "\n"))
	{
		tmp = ft_strtrim(*grid, "\n");
		if (tmp && *tmp)
			ft_matrixadd_back(&tmp_map->map, tmp);
		free(tmp);
		grid++;
	}
	while (grid && *grid && !ft_strcmp(*grid, "\n"))
		grid++;
	if (grid && *grid)
		err("Empty line in map.", map);
	map_destroy_map(map);
	if (tmp_map->map)
		map->map = tmp_map->map;
	free(tmp_map);
}

void	map_extract_data(t_map *map)
{
	static char	*arr[7] = {"NO ", "SO ", "WE ", "EA ", "F ", "C ", 0};
	int			j = 0;
	int			i = 0;
	char 		*tmp;
	int			flag = 0;

	while (map->map[j] && flag < 6)
	{
		tmp = ft_strtrim(map->map[j++], SPACERS);
		if (tmp && *tmp)
		{
			i = -1;
			while (arr[++i])
			{
				if (tmp[0] == arr[i][0] && tmp[1] == arr[i][1] \
				&& (i > 3 || tmp[2] == arr[i][2]))
				{	
					flag += (map->cords[i] == NULL);
					free(map->cords[i]);
					map->cords[i] = ft_strtrim(tmp + 2, SPACERS);
				}	
			}
		}
		free(tmp);
	}
	if (all_filled(map) || err("Missing texture.", map))
		map_extract_map(&map->map[j], map);
}
