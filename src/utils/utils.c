/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:02:12 by chaleira          #+#    #+#             */
/*   Updated: 2023/10/07 06:21:57 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_matrix(char **matrix)
{
	while (matrix && *matrix)
	{
		printf("%s", *matrix);
		matrix++;
	}
}

void	map_add_back(t_map **map, t_map *new_map)
{
	t_map *last;

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
