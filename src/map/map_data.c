/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 23:50:18 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/07 20:42:43 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_extract_map(char **grid, t_map *map)
{
	char	*tmp;

	while (grid && *grid && !ft_strcmp(*grid, "\n"))
		grid++;
	while (grid && *grid && ft_strcmp(*grid, "\n"))
	{
		tmp = ft_strtrim(*grid, "\n");
		if (tmp && *tmp)
			ft_matrixadd_back(&map->map, tmp);
		free(tmp);
		grid++;
	}
	while (grid && *grid && !ft_strcmp(*grid, "\n"))
		grid++;
	if (grid && *grid)
		err("Empty line in map.", map);
	return (0);
}

void	map_extract_data(t_map *map)
{
	static char	*arr[7] = {"NO ", "SO ", "WE ", "EA ", "F ", "C ", 0};
	int			j = 0;
	int			i = 0;
	char 		*tmp;
	int			flag = 0;

	while (map->file[j] && flag < 6)
	{
		tmp = ft_strtrim(map->file[j++], " \n\t\r\b\v\f");
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
					map->cords[i] = ft_strtrim(tmp + 2, " \n\t\r\b\v\f");
				}	
			}
		}
		free(tmp);
	}
	if (all_filled(map) || err("Missing texture.", map))
		map_extract_map(&map->file[j], map);
}
