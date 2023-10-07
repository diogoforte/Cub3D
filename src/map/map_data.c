/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaleira <chaleira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 23:50:18 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/07 05:49:53 by chaleira         ###   ########.fr       */
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
		tmp = ft_strtrim(*grid, " \n\t");
		if (tmp && *tmp)
			matrix_add_back(&map->map, tmp);
		else
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
	static char	*arr[6] = {"NO", "SO", "WE", "EA", "F", "C"};
	int			i[2];

	i[0] = 0;
	while (map->file && map->file[i[0]] && !all_filled(map))
	{
		i[1] = 0;
		while (arr[i[1]] && !all_filled(map))
		{
			if (!ft_strncmp(map->file[i[0]], arr[i[1]], ft_strlen(arr[i[1]])))
			{
				if (map->cords[i[1]] != NULL)
					err("Duplicate type.", map);
				else
					map->cords[i[1]] = ft_strtrim(map->file[i[0]]
						+ ft_strlen(arr[i[1]]), " \n\t");
			}
			i[1]++;
		}
		i[0]++;
	}
	if (all_filled(map) || err("Missing texture.", map))
		map_extract_map(&map->file[i[0]], map);
}
