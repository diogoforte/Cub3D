/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:00:30 by plopes-c          #+#    #+#             */
/*   Updated: 2023/10/09 06:14:21 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	matrix_biggest_string(char **str)
{
	int	i;
	int	j;
	int	biggest;

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
	int	i;

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
	int			i;

	printf("Map number: %d\n", map->map_number);
	printf("Map name: %s\n", map->map_name);
	if (map->playable)
	{
		printf("Playeable: Yes\n");
		printf("Cords:\n");
		i = -1;
		while (++i < 6)
			printf("%s: (%s)\n", arr[i], map->cords[i]);
		i = -1;
		printf("Map:\n");
		while (map->map && map->map[++i])
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

void	map_add_back(t_map **map, t_map *new_map)
{
	t_map	*last;

	if (!map || !new_map)
		return ;
	if (!*map)
	{
		*map = new_map;
		return ;
	}
	last = *map;
	while (last->next)
		last = last->next;
	last->next = new_map;
}
