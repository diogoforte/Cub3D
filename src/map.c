/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:12:14 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/04 01:20:41 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	map_loader(char **av)
{
	map_opener(*++av);
}

void	map_opener(char *map_path)
{
	static t_map	map;

	if (!map_path || ft_strlen(map_path) < 4 || ft_strncmp(map_path
			+ ft_strlen(map_path) - 4, ".cub", 4))
	{
		help_message(3);
		return ;
	}
	map.fd = open(map_path, O_RDONLY);
	if (map.fd == -1)
		help_message(2);
	engine()->map = &map;
}
