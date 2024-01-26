/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:56:50 by chaleira          #+#    #+#             */
/*   Updated: 2024/01/26 10:53:43 by dinunes-         ###   ########.fr       */
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
	map->destroy_map = map_destroy_map;
	map->destroy_error = map_destroy_error;
	map->destroy_cords = map_destroy_cords;
	map_check(map);
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
		exit_cub("File not found");
	else if (ft_strncmp(file_path + ft_strlen(file_path) - 4, ".cub", 4))
		exit_cub("File extension not supported");
	else
	{
		load_files(fd, map, 0);
		close(fd);
		if (!map->map)
			exit_cub("Empty file");
	}
}

void	map_load(char **argv)
{
	cub()->map = map_new(argv[1]);
}

int	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return (printf("Matrix is empty\n"));
	while (matrix[i])
	{
		printf("%s\n", matrix[i]);
		i++;
	}
	return (0);
}
