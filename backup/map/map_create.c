/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaleira <chaleira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:52:52 by plopes-c          #+#    #+#             */
/*   Updated: 2023/10/06 23:20:58 by chaleira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	map_create(char **grid, t_map *map)
{
	char 	*tmp;
	int 	lenght;
	
	lenght = 0;
	while (grid && *grid)
	{
		tmp = ft_strtrim(*grid, " \n	");
		if (tmp && *tmp)
		{
			map->map = ft_realloc(map->map,
				(lenght + 1), sizeof(char *));
			map->map[lenght] = tmp;
			lenght++;
		}
		else
			free(tmp);
		grid++;
	}
}

static void	map_extract_data(t_map *map)
{
	static char	*arr[6] = {"NO", "SO", "WE", "EA", "F", "C"};
	int	i[2];

	i[0] = 0;
	while (map->grid[i[0]] && all_filled(map))
	{
		i[1] = 0;
		while (arr[i[1]] && all_filled(map))
		{
			if (!ft_strncmp(map->grid[i[0]], arr[i[1]], ft_strlen(arr[i[1]])))
			{
				if (*arr_type(map)[i[1]])
					map->error("Duplicate type.", map);
				*arr_type(map)[i[1]] = ft_strtrim(map->grid[i[0]]
										+ ft_strlen(arr[i[1]]), " \n	");
			}
			i[1]++;
		}
		i[0]++;
	}
	if (!all_filled(map))
		map_create(&map->grid[i[0]], map);
	else
		map->error("Missing type.", map);
}
