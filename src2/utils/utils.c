/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaleira <chaleira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:02:12 by chaleira          #+#    #+#             */
/*   Updated: 2023/10/06 23:06:20 by chaleira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d2.h"

void	matrix_add_back(char ***matrix, char *str)
{
	char **new_matrix;
	int i;
	
	new_matrix = ft_calloc(sizeof(char *), (ft_matrix_len(*matrix) + 2));
	i = 0;
	while (*matrix && (*matrix)[i])
	{
		new_matrix[i] = (*matrix)[i];
		i++;
	}
	new_matrix[i] = str;
	if (*matrix)
		free(*matrix);
	*matrix = new_matrix;
}

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
