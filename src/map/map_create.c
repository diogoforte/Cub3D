/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:56:50 by chaleira          #+#    #+#             */
/*   Updated: 2023/10/17 15:26:33 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*map_new(char *file_path)
{
	t_map		*map;
	static int	number_of_maps;

	if (!file_path)
		return (NULL);
	map = ft_calloc(1, sizeof(t_map));
	map->playable = 1;
	map->map_number = ++number_of_maps;
	map_extract_file(map, file_path);
	map_extract_data(map);
	map->map_height = ft_matrix_len(map->map);
	if (map->playable)
		map->map_width = matrix_biggest_string(map->map);
	map->start_x = 0;
	map->start_y = 0;
	map->print = map_print;
	map->destroy_map = map_destroy_map;
	map->destroy_error = map_destroy_error;
	map->destroy_cords = map_destroy_cords;
	map_check(map);
	// map_print(map);
	return (map);
}

void	load_files(int fd, t_map *map, int i)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		load_files(fd, map, i + 1);
	else if (i)
		map->map = ft_calloc(sizeof(char *), i + 1);
	if (map->map)
		map->map[i] = line;
}

void	map_extract_file(t_map *map, char *file_path)
{
	int	fd;

	map->map_name = file_path;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		err("File not found", map);
	else if (ft_strncmp(file_path + ft_strlen(file_path) - 4, ".cub", 4))
		err("File extension not supported", map);
	else
	{
		load_files(fd, map, 0);
		close(fd);
		if (!map->map)
			err("Empty file", map);
	}
}

void	map_load(char **argv)
{
	while (++argv && *argv)
		map_add_back(&cub()->maps, map_new(*argv));
}
