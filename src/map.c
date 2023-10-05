/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:12:14 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/05 07:21:16 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_map	*map_opener(char *map_path);
static void	map_reader(t_map *map);
static void	types_fill(t_map *map);
static void	map_fill(char **grid, t_map *map);
// static void	map_checker(t_map *map);

void	map_loader(char **av, int argc)
{
	int i;
	
	i = 0;
	engine()->map = ft_calloc(argc - 1, sizeof(t_map *));
	while (*++av)
	{	
		engine()->map[i] = map_opener(*av);
		if (engine()->map[i]->playable)
		{
			map_reader(engine()->map[i]);
			types_fill(engine()->map[i]);
			// map_checker();
			// print_vars(engine()->map[i]);
		}
		i++;
	}
}

t_map	*map_opener(char *map_path)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	map->playable = true;
	if (!map_path || ft_strlen(map_path) < 4 || ft_strncmp(map_path
			+ ft_strlen(map_path) - 4, ".cub", 4))
		err("Invalid map file extension.", map);
	map->fd = open(map_path, O_RDONLY);
	if (map->fd == -1)
		err("Invalid map file.", map);
	return (map);
}

static void	types_fill(t_map *map)
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
					err("Duplicate type.", map);
				*arr_type(map)[i[1]] = ft_strtrim(map->grid[i[0]]
										+ ft_strlen(arr[i[1]]), " \n	");
			}
			i[1]++;
		}
		i[0]++;
	}
	map_fill(&map->grid[i[0]], map);
}

static void    map_reader(t_map *map)
{
    char    *line;

    map->rows = 0;
    while (get_next_line2(map->fd, &line))
    {
        map->grid = ft_realloc(map->grid,
            (map->rows + 1), sizeof(char *));
        map->grid[map->rows] = ft_strtrim(line, " 	");
        if (map->cols < (int)ft_strlen(line))
            map->cols = ft_strlen(line);
        free(line);
        map->rows++;
    }
    close(map->fd);
}

static void	map_fill(char **grid, t_map *map)
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

// static void	map_checker(void)
// {
// }
