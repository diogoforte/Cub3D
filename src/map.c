/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:12:14 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/05 05:15:44 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	map_opener(char *map_path);
static void	map_reader(void);
static void	map_extract_data(void);
static void	map_checker(void);

void	map_loader(char **av)
{
	map_opener(*++av);
	map_reader();
	map_extract_data();
	map_checker();
}

static void	map_opener(char *map_path)
{
	static t_map	map;

	map.playable = true;
	if (!map_path || ft_strncmp(map_path + ft_strlen(map_path) - 4, ".cub", 4))
	{
		help_message(3);
		map.playable = false;
		return ;
	}
	map.fd = open(map_path, O_RDONLY);
	if (map.fd == -1)
	{
		help_message(2);
		map.playable = false;
	}
	engine()->map = &map;
}

static void	map_reader(void)
{
	char	*line;

	engine()->map->rows = 0;
	while (get_next_line2(engine()->map->fd, &line))
	{
		engine()->map->grid = ft_realloc(engine()->map->grid,
			(engine()->map->rows + 1), sizeof(char *));
		engine()->map->grid[engine()->map->rows] = ft_strdup(line);
		if (engine()->map->cols < (int)ft_strlen(line))
			engine()->map->cols = ft_strlen(line);
		free(line);
		engine()->map->rows++;
	}
	close(engine()->map->fd);
}

static void	map_extract_data(void)
{
	static char	*arr[6] = {"NO", "SO", "WE", "EA", "F", "C"};
	char		**arr_type[6];
	int			i[2];

	arr_type[0] = &engine()->map->NO;
	arr_type[1] = &engine()->map->SO;
	arr_type[2] = &engine()->map->WE;
	arr_type[3] = &engine()->map->EA;
	arr_type[4] = &engine()->map->F;
	arr_type[5] = &engine()->map->C;
	i[0] = 0;
	while (engine()->map->grid[i[0]])
	{
		i[1] = 0;
		while (arr[i[1]])
		{
			if (!ft_strncmp(engine()->map->grid[i[0]], arr[i[1]],
					ft_strlen(arr[i[1]])))
				if (!*arr_type[i[1]])
					*arr_type[i[1]] = ft_strdup(engine()->map->grid[i[0]]
						+ ft_strlen(arr[i[1]]));
			i[1]++;
		}
		i[0]++;
	}
}

static void	map_checker(void)
{
}
