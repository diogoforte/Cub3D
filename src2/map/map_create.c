/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaleira <chaleira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:56:50 by chaleira          #+#    #+#             */
/*   Updated: 2023/10/06 23:22:32 by chaleira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d2.h"

void	map_add_list(char *file_path)
{
	map_add_back(&cub()->map, map_new(file_path));
}

t_map	*map_new(char *file_path)
{
	t_map	*map;
	static	int	number_of_maps;

	if (!file_path)
		return (NULL);
	map = ft_calloc(1, sizeof(t_map));
	map->playable = 1;
	map->map_number = ++number_of_maps;
	map_extract_file(map, file_path);
	// map_set_variables(map);
	// map->print_variables = &print_variables;
	return (map);
}

void	map_extract_file(t_map *map, char *file_path)
{
	int 	fd;
	char 	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		err("Error\nFile not found");
	else
	{
		while (get_next_line2(fd, &line))
			matrix_add_back(&map->file, line);
		close(fd);
		if (!map->file)
			err("Error\nEmpty file");
	}
}

void	load_all_maps(char **argv)
{
	while (++argv && *argv)
	{
		printf("Loading map: %s\n", *argv);
		map_add_list(*argv);
	}
}