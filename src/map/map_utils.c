/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:00:30 by plopes-c          #+#    #+#             */
/*   Updated: 2024/01/26 10:50:03 by dinunes-         ###   ########.fr       */
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
	while (str && str[i])
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

void	matrix_char_to_char(char **matrix, char old, char new)
{
	int	i;
	int	j;

	i = 0;
	while (matrix && matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == old)
				matrix[i][j] = new;
			j++;
		}
		i++;
	}
}
