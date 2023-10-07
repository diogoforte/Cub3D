/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 23:50:18 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/07 02:19:40 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_split(char **grid, t_map *map)
{
	char	*tmp;
	int		length;

	length = 0;
	while (grid && *grid)
	{
		tmp = ft_strtrim(*grid, " \n	");
		if (tmp && *tmp)
		{
			map->map = ft_realloc(map->map, (length + 1), sizeof(char *));
			map->map[length] = tmp;
			length++;
		}
		else
			free(tmp);
		grid++;
	}
}

char	***arr_type(t_map *map)
{
	static char	**arr_type[6];

	arr_type[0] = &map->cords[NO];
	arr_type[1] = &map->cords[SO];
	arr_type[2] = &map->cords[WE];
	arr_type[3] = &map->cords[EA];
	arr_type[4] = &map->cords[F];
	arr_type[5] = &map->cords[C];
	return (arr_type);
}

int	all_filled(t_map *map)
{
	char	***arr_type2;
	int		i;

	i = 0;
	arr_type2 = arr_type(map);
	while (i < 6)
	{
		if (!*arr_type2[i])
			return (1);
		i++;
	}
	return (0);
}

void	map_print(t_map *map)
{
	printf("Map number: %d\n", map->map_number);
	printf("Cords:\n");
	for (int i = 0; i < 6; i++)
	{
		if (map->cords[i])
			printf("cords[%d]: %s\n", i, map->cords[i]);
		else
			printf("cords[%d]: NULL\n", i);
	}
	printf("Map:\n");
	for (int i = 0; map->map && map->map[i]; i++)
		printf("%s\n", map->map[i]);
}

void	map_extract_data(t_map *map)
{
	static char	*arr[6] = {"NO", "SO", "WE", "EA", "F", "C"};
	int			i[2];

	if (map->playable == false)
		return ;
	i[0] = 0;
	while (map->file && map->file[i[0]] && all_filled(map))
	{
		i[1] = 0;
		while (arr[i[1]] && all_filled(map))
		{
			if (!ft_strncmp(map->file[i[0]], arr[i[1]], ft_strlen(arr[i[1]])))
			{
				if (map->cords[i[1]] != NULL)
					err("Duplicate type.");
				else
					map->cords[i[1]] = ft_strtrim(map->file[i[0]]
						+ ft_strlen(arr[i[1]]), " \n\t");
			}
			i[1]++;
		}
		i[0]++;
	}
	if (!all_filled(map))
		map_split(&map->file[i[0]], map);
	else
		err("Missing type.");
	map_print(map);
}
