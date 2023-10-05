/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:12:14 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/05 01:11:36 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	map_opener(char *map_path);
static void	map_reader(void);
static void	map_splitter(void);
static void	map_checker(void);

void	map_loader(char **av)
{
	map_opener(*++av);
	map_reader();
	map_splitter();
	map_checker();
}

static void	map_opener(char *map_path)
{
	static t_map	map;

	map.playable = true;
	if (!map_path || ft_strlen(map_path) < 4 || ft_strncmp(map_path
			+ ft_strlen(map_path) - 4, ".cub", 4))
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
		if (ft_strlen(line) > 0)
			engine()->map->rows++;
		free(line);
	}
	engine()->map->grid = ft_calloc(engine()->map->rows + 1, sizeof(char *));
	ft_lseek(engine()->map->fd, 0, SEEK_SET);
	engine()->map->rows = 0;
	while (get_next_line2(engine()->map->fd, &line))
	{
		if (ft_strlen(line) < 1)
			continue ;
		engine()->map->cols = ft_strlen(line);
		engine()->map->grid[engine()->map->rows] = ft_calloc(engine()->map->cols
			+ 1, sizeof(char));
		ft_memcpy(engine()->map->grid[engine()->map->rows], line,
			engine()->map->cols + 1);
		free(line);
		engine()->map->rows++;
	}
	close(engine()->map->fd);
}

static void	map_splitter(void)
{
	int	i;
	int	j;

	i = 0;
	while (engine()->map->grid[i])
	{
		if (engine()->map->grid[i][0] == '\n')
			i++;
		else if (!ft_strncmp(engine()->map->grid[i], "NO ", 3))
			engine()->map->NO = ft_strdup(engine()->map->grid[i] + 3);
		else if (!ft_strncmp(engine()->map->grid[i], "SO ", 3))
			engine()->map->SO = ft_strdup(engine()->map->grid[i] + 3);
		else if (!ft_strncmp(engine()->map->grid[i], "WE ", 3))
			engine()->map->WE = ft_strdup(engine()->map->grid[i] + 3);
		else if (!ft_strncmp(engine()->map->grid[i], "EA ", 3))
			engine()->map->EA = ft_strdup(engine()->map->grid[i] + 3);
		else if (!ft_strncmp(engine()->map->grid[i], "F ", 2))
			engine()->map->F = ft_strdup(engine()->map->grid[i] + 2);
		else if (!ft_strncmp(engine()->map->grid[i], "C ", 2))
			engine()->map->C = ft_strdup(engine()->map->grid[i] + 2);
		else
			break ;
		free(engine()->map->grid[i]);
		j = i;
		while (engine()->map->grid[++j])
			engine()->map->grid[j - 1] = engine()->map->grid[j];
		engine()->map->grid[j - 1] = NULL;
	}
}

static void	map_checker(void)
{
}
