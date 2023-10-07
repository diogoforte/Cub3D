/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:00:30 by plopes-c          #+#    #+#             */
/*   Updated: 2023/10/07 21:04:31 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	matrix_biggest_string(char **str)
{
	int i;
	int j;
	int biggest;

	i = 0;
	biggest = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
			j++;
		if (j > biggest)
			biggest = j;
		i++;
	}
	return (biggest);
}

int	all_filled(t_map *map)
{
	int		i;

	i = 0;
	while (i < 6)
	{
		if (!map->cords[i])
			return (0);
		i++;
	}
	return (1);
}

void	map_print(t_map *map)
{
	static char	*arr[6] = {"NO", "SO", "WE", "EA", "F", "C"};

	printf("Map number: %d\n", map->map_number);
	if (map->playable)
	{
		printf("Playeable: Yes\n");
		printf("Cords:\n");
		for (int i = 0; i < 6; i++)
			printf("%s: (%s)\n", arr[i], map->cords[i]);
		printf("Map:\n");
		for (int i = 0; map->map && map->map[i]; i++)
			printf("%s\n", map->map[i]);
	}
	else
	{
		printf("Playeable: No");
			if (map->error)
				printf(" - %s\n", map->error);
	}
}
void	map_clear(t_map *map)
{
	if (map && !map->playable)
	{
		map->destroy_cords(map);
		map->destroy_map(map);
		map->destroy_file(map);
	}
}
